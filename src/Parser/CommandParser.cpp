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
  Impl->Lexer.tokenize(
      Text,
      [&Context](CommandTokenID TokenID, std::string_view TokenText) -> bool {
        switch (TokenID) {
        case CommandTokenID::OpenParen:
          return Context.beginScope();
        case CommandTokenID::CloseParen:
          return Context.endScope();
        case CommandTokenID::Comma:
          return Context.endSection();
        case CommandTokenID::EventTag:
          return Context.parseEventTag(TokenText);
        case CommandTokenID::Name:
          return Context.parseName(TokenText);
        case CommandTokenID::Number:
          return Context.parseNumber(TokenText);
        case CommandTokenID::String:
          return Context.parseString(TokenText);
        case CommandTokenID::XML:
          return Context.parseXML(TokenText);
        default:
          return true;
        }
      });
  return std::make_pair(Context.hasCompleteParse(), Context.ParsedCommand);
}

} // namespace parser

} // namespace jdme2x
