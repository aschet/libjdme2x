//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "MethodParserStates.h"

#include "jdme2x/Parser/Lexer.h"
#include "jdme2x/Parser/ParserUtils.h"

#include <charconv>
#include <utility>

namespace jdme2x {
namespace parser {

bool MethodStartState::parseName(MethodParserContext &context,
                                 std::string_view text) {
  context.data.method.name = text;
  context.transitionTo(Singleton<ArgumentListStartState>::instance());
  return true;
}

bool ArgumentListStartState::beginScope(MethodParserContext &context) {
  context.transitionTo(Singleton<ArgumentState>::instance());
  return true;
}

bool ArgumentState::endScope(MethodParserContext &context) {
  context.transitionTo(Singleton<MethodEndState>::instance());
  return true;
}

bool ArgumentState::parseEventTag(MethodParserContext &context,
                                  std::string_view text) {
  if (auto eventTag = createTag(text)) {
    context.data.method.with(*eventTag);
    context.transitionTo(Singleton<NextArgumentState>::instance());
    return true;
  }
  return false;
}

bool ArgumentState::parseName(MethodParserContext &context,
                              std::string_view text) {
  context.data.currentName = text;
  context.transitionTo(Singleton<PropertyOrNameArgumentState>::instance());
  return true;
}

bool ArgumentState::parseNumber(MethodParserContext &context,
                                std::string_view text) {
  if (auto number = createNumber(text)) {
    context.data.method.with(std::move(*number));
    context.transitionTo(Singleton<NextArgumentState>::instance());
    return true;
  }
  return false;
}

bool ArgumentState::parseString(MethodParserContext &context,
                                std::string_view text) {
  if (auto string = createString(text)) {
    context.data.method.with(std::move(*string));
    context.transitionTo(Singleton<NextArgumentState>::instance());
    return true;
  }
  return false;
}

bool ArgumentState::parseXML(MethodParserContext &context,
                             std::string_view text) {
  context.data.method.xml = text;
  context.transitionTo(Singleton<ArgumentListEndState>::instance());
  return true;
}

bool NextArgumentState::endScope(MethodParserContext &context) {
  context.transitionTo(Singleton<MethodEndState>::instance());
  return true;
}

bool NextArgumentState::endSection(MethodParserContext &context) {
  context.transitionTo(Singleton<ArgumentState>::instance());
  return true;
}

bool PropertyOrNameArgumentState::beginScope(MethodParserContext &context) {
  // Open parenthesis after a name signals a property
  context.data.propertyContext.reset();
  context.data.propertyContext.data.name = std::move(context.data.currentName);
  context.data.propertyContext.transitionTo(
      Singleton<PropertyValueState>::instance());
  context.transitionTo(Singleton<PropertyArgumentState>::instance());
  return true;
}

bool PropertyOrNameArgumentState::endScope(MethodParserContext &context) {
  // Closing parenthesis after a basic name
  context.data.method.with(std::move(context.data.currentName));
  context.transitionTo(Singleton<MethodEndState>::instance());
  return true;
}

bool PropertyOrNameArgumentState::endSection(MethodParserContext &context) {
  // Comma after a basic name
  context.data.method.with(std::move(context.data.currentName));
  context.transitionTo(Singleton<ArgumentState>::instance());
  return true;
}

bool PropertyArgumentState::parse(MethodParserContext &context, TokenID id,
                          std::string_view text) {
  bool result = context.data.propertyContext.parse(id, text);
  if (result && hasCompleteParse(context)) {
    context.data.method.with(std::move(context.data.propertyContext.data));
    context.transitionTo(Singleton<NextArgumentState>::instance());
  }
  return result;
}

bool PropertyArgumentState::hasCompleteParse(MethodParserContext &context) {
  return context.data.propertyContext.hasCompleteParse();
}
bool ArgumentListEndState::endScope(MethodParserContext &context) {
  context.transitionTo(Singleton<MethodEndState>::instance());
  return true;
}

bool MethodEndState::hasCompleteParse(MethodParserContext &) { return true; }

} // namespace parser
} // namespace jdme2x
