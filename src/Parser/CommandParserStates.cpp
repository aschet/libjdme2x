//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "CommandParserStates.h"

#include "jdme2x/Parser/Lexer.h"
#include "jdme2x/Parser/ParserUtils.h"

#include <charconv>
#include <utility>

namespace jdme2x {
namespace parser {
namespace states {

bool CommandStartState::parseEventTag(CommandParserContext &context,
                                      std::string_view text) {
  if (auto eventTag = createTag(text)) {
    context.data.tag = *eventTag;
    context.transitionTo(Singleton<CommandMethodState>::instance());
    return true;
  }
  return false;
}

bool CommandStartState::parseNumber(CommandParserContext &context,
                                    std::string_view text) {
  return parseEventTag(context, text);
}

bool CommandMethodState::parse(CommandParserContext &context, TokenID id,
                               std::string_view text) {
  bool result = context.data.methodContext.parse(id, text);
  if (result && hasCompleteParse(context))
    context.transitionTo(Singleton<CommandEndState>::instance());
  return result;
}

bool CommandMethodState::hasCompleteParse(CommandParserContext &context) {
  return context.data.methodContext.hasCompleteParse();
}

bool CommandEndState::hasCompleteParse(CommandParserContext &) { return true; }

} // namespace states
} // namespace parser
} // namespace jdme2x
