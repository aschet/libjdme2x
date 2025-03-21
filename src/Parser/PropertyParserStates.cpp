//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "PropertyParserStates.h"

#include "jdme2x/Parser/ParserUtils.h"

#include <charconv>
#include <utility>

namespace jdme2x {
namespace parser {

bool PropertyStartState::parseName(PropertyParserContext &context,
                                   std::string_view text) {
  context.data.name = text;
  context.transitionTo(Singleton<PropertyValueStartState>::instance());
  return true;
}

bool PropertyValueStartState::beginScope(PropertyParserContext &context) {
  context.transitionTo(Singleton<PropertyValueState>::instance());
  return true;
}

bool PropertyValueState::endScope(PropertyParserContext &context) {
  context.transitionTo(Singleton<PropertyEndState>::instance());
  return true;
}

bool PropertyValueState::parseNumber(PropertyParserContext &context,
                                     std::string_view text) {
  if (auto number = createNumber(text)) {
    context.data.with(std::move(*number));
    context.transitionTo(Singleton<NextPropertyValueState>::instance());
    return true;
  }
  return false;
}

bool NextPropertyValueState::endScope(PropertyParserContext &context) {
  context.transitionTo(Singleton<PropertyEndState>::instance());
  return true;
}

bool NextPropertyValueState::endSection(PropertyParserContext &context) {
  context.transitionTo(Singleton<NextPropertyValueState>::instance());
  return true;
}

bool PropertyEndState::hasCompleteParse(PropertyParserContext &) {
  return true;
}

} // namespace parser
} // namespace jdme2x
