// Copyright (c) 2025 Thomas Ascher
// SPDX-License-Identifier: BSL-1.0
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#include "jdme2x/Parser/CommandParser.h"

#include "CommandParserStates.h"
#include "jdme2x/Parser/CommandLexer.h"
#include "jdme2x/Parser/TokenID.h"

namespace jdme2x {

namespace parser {

struct CommandParser::Private {
  CommandLexer Lexer;
};

CommandParser::CommandParser() : Impl(std::make_unique<Private>()) {}

CommandParser::~CommandParser() = default;

std::pair<bool, Command> CommandParser::parse(std::string_view Text) {
  if (Text.empty())
    return std::make_pair(false, Command());

  CommandParserContext Context;
  Impl->Lexer.tokenize(Text,
                       [&Context](TokenID ID, std::string_view Text) -> bool {
                         switch (ID) {
                         case TokenID::OpenParen:
                           return Context.beginScope();
                         case TokenID::CloseParen:
                           return Context.endScope();
                         case TokenID::Comma:
                           return Context.endSection();
                         case TokenID::EventTag:
                           return Context.parseEventTag(Text);
                         case TokenID::Name:
                           return Context.parseName(Text);
                         case TokenID::Number:
                           return Context.parseNumber(Text);
                         case TokenID::String:
                           return Context.parseString(Text);
                         case TokenID::XML:
                           return Context.parseXML(Text);
                         case TokenID::Space:
                           return true;
                         default:
                           return false;
                         }
                       });
  return std::make_pair(Context.hasCompleteParse(), Context.ParsedCommand);
}

} // namespace parser

} // namespace jdme2x
