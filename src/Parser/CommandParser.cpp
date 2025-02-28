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

using namespace jdme2x::parser::states;

namespace jdme2x {
namespace parser {

struct CommandParser::Private {
  Lexer lexer;
};

CommandParser::CommandParser() : impl(std::make_unique<Private>()) {}

CommandParser::~CommandParser() = default;

CommandParser::CommandParser(CommandParser &&) = default;

CommandParser &CommandParser::operator=(CommandParser &&) = default;

std::pair<bool, types::Command> CommandParser::parse(std::string_view text) {
  if (text.empty())
    return std::make_pair(false, types::Command());

  CommandParserContext context(Singleton<CommandStartState>::instance());
  impl->lexer.tokenize(text,
                       [&context](TokenID id, std::string_view text) -> bool {
                         return context.parse(id, text);
                       });
  return std::make_pair(
      context.hasCompleteParse(),
      types::Command(context.data.tag,
                     std::move(context.data.methodContext.data.method)));
}

} // namespace parser
} // namespace jdme2x
