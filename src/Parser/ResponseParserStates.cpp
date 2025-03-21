//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "ResponseParserStates.h"

#include "jdme2x/Parser/Lexer.h"
#include "jdme2x/Parser/ParserUtils.h"

#include <charconv>
#include <utility>

namespace jdme2x {
namespace parser {
namespace states {

bool ResponseStartState::parseEventTag(ResponseParserContext &context,
                                       std::string_view text) {
  if (auto tag = createTag(text)) {
    context.data.response.tag = *tag;
    context.transitionTo(Singleton<ResponseTypeState>::instance());
    return true;
  }
  return false;
}

bool ResponseStartState::parseNumber(ResponseParserContext &context,
                                     std::string_view text) {
  return parseEventTag(context, text);
}

bool ResponseTypeState::parseResponseType(ResponseParserContext &context,
                                          std::string_view text) {
  if (text.length() != 1)
    return false;

  switch (text[0]) {
  case AcknowledgeID: {
    context.data.response.value = Acknowledge();
    context.transitionTo(Singleton<ResponseEndState>::instance());
    return true;
  }
  case DoneID: {
    context.data.response.value = Done();
    context.transitionTo(Singleton<ResponseEndState>::instance());
    return true;
  }
  case ErrorID: {
    context.data.response.value = Error();
    context.data.methodContext.reset();
    context.transitionTo(Singleton<ResponseErrorState>::instance());
    return true;
  }
  case DataID: {
    context.data.response.value = Data();
    context.transitionTo(Singleton<ResponseDataState>::instance());
    return true;
  }
  }

  return false;
}

bool ResponseErrorState::parse(ResponseParserContext &context, TokenID id,
                               std::string_view text) {
  bool result = context.data.methodContext.parse(id, text);
  if (result && context.data.methodContext.hasCompleteParse()) {
    if (auto error = createError(context.data.methodContext.data.method)) {
      context.data.response.value = ResponseValue(std::move(*error));
      context.transitionTo(Singleton<ResponseEndState>::instance());
    } else {
      return false;
    }
  }
  return result;
}

bool ResponseErrorState::hasCompleteParse(ResponseParserContext &context) {
  return context.data.response.holdsError();
}

bool ResponseDataState::parseNumber(ResponseParserContext &context,
                                    std::string_view text) {
  context.data.response.value = Data(NumericalData());
  return Singleton<NumericDataState>::instance()->parseNumber(context, text);
}

bool ResponseDataState::parseString(ResponseParserContext &context,
                                    std::string_view text) {
  context.data.response.value = Data(PropertyData());
  context.data.response.propertyData().first = *createString(text);
  context.transitionTo(Singleton<PropertyDataSeparatorState>::instance());
  return true;
}

bool ResponseDataState::parseName(ResponseParserContext &context,
                                  std::string_view text) {
  context.data.methodContext.reset();
  Singleton<MethodStartState>::instance()->parseName(context.data.methodContext,
                                                     text);
  context.transitionTo(Singleton<MethodDataState>::instance());
  return true;
}

bool NumericDataState::parseNumber(ResponseParserContext &context,
                                   std::string_view text) {
  if (auto number = createNumber(text)) {
    context.data.response.numericData().emplace_back(std::move(*number));
    context.transitionTo(Singleton<NextNumericDataState>::instance());
    return true;
  }
  return false;
}

bool NextNumericDataState::endSection(ResponseParserContext &context) {
  context.transitionTo(Singleton<NumericDataState>::instance());
  return true;
}

bool NextNumericDataState::hasCompleteParse(ResponseParserContext &) {
  return true;
}

bool PropertyDataSeparatorState::endSection(ResponseParserContext &context) {
  context.transitionTo(Singleton<PropertyDataValueState>::instance());
  return true;
}

bool PropertyDataValueState::parseString(ResponseParserContext &context,
                                         std::string_view text) {
  context.data.response.propertyData().second = *createString(text);
  context.transitionTo(Singleton<ResponseEndState>::instance());
  return true;
}

bool MethodDataState::parse(ResponseParserContext &context, TokenID id,
                            std::string_view text) {
  bool result = context.data.methodContext.parse(id, text);
  if (result && hasCompleteParse(context)) {
    context.data.response.data() =
        std::move(context.data.methodContext.data.method);
    context.transitionTo(Singleton<NextPropertyListValueState>::instance());
  }
  return result;
}

bool MethodDataState::hasCompleteParse(ResponseParserContext &context) {
  return context.data.methodContext.hasCompleteParse();
}

bool NextPropertyListValueState::endSection(ResponseParserContext &context) {
  if (context.data.response.holdsMethod()) {
    if (auto property = createProperty(context.data.response.method())) {
      context.data.response.data() = PropertyList{std::move(*property)};
    } else {
      return false;
    }
  }
  context.data.methodContext.data.propertyContext.reset();
  context.transitionTo(Singleton<PropertyListValueState>::instance());
  return true;
}

bool NextPropertyListValueState::hasCompleteParse(ResponseParserContext &) {
  return true;
}

bool PropertyListValueState::parse(ResponseParserContext &context, TokenID id,
                                   std::string_view text) {
  bool result = context.data.methodContext.data.propertyContext.parse(id, text);
  if (result && hasCompleteParse(context)) {
    context.data.response.propertyList().emplace_back(
        std::move(context.data.methodContext.data.propertyContext.data));
    context.transitionTo(Singleton<NextPropertyListValueState>::instance());
  }
  return result;
}

bool PropertyListValueState::hasCompleteParse(ResponseParserContext &context) {
  return context.data.methodContext.data.propertyContext.hasCompleteParse();
}

bool ResponseEndState::hasCompleteParse(ResponseParserContext &) {
  return true;
}

} // namespace states
} // namespace parser
} // namespace jdme2x
