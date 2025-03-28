//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/CommandParser.h"

#include "CommandParserStates.h"
#include "jdme2x/Parser/Lexer.h"

#include <utility>

using namespace jdme2x::parser;

namespace jdme2x {

struct CommandParser::Private {
  Lexer lexer;
};

CommandParser::CommandParser() : impl(std::make_unique<Private>()) {}

CommandParser::~CommandParser() = default;

CommandParser::CommandParser(CommandParser &&) = default;

CommandParser &CommandParser::operator=(CommandParser &&) = default;

std::pair<bool, Command> CommandParser::parse(std::string_view text) {
  if (text.empty())
    return std::make_pair(false, Command());

  CommandParserContext context(
      Singleton<parser::CommandStartState>::instance());
  impl->lexer.tokenize(text,
                       [&context](TokenID id, std::string_view text) -> bool {
                         return context.parse(id, text);
                       });
  return std::make_pair(
      context.hasCompleteParse(),
      Command(context.data.tag,
              std::move(context.data.methodContext.data.method)));
}

} // namespace jdme2x
