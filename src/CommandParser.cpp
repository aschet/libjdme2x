// Copyright (c) 2025 Thomas Ascher
// SPDX-License-Identifier: BSL-1.0
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#include "jdme2x/CommandParser.h"

#include "CommandParserStates.h"
#include "jdme2x/Command.h"
#include "jdme2x/Tag.h"

#include <boost/spirit/include/lex_lexertl.hpp>
#include <string_view>

namespace lex = boost::spirit::lex;

namespace jdme2x {

enum Tokens {
  TK_LeftParen = 1,
  TK_RightParen,
  TK_Comma,
  TK_Space,
  TK_EventTag,
  TK_Name,
  TK_Number,
  TK_String,
  TK_XML,
  TK_Terminator,
};

template <typename Lexer> struct CommandLexer : lex::lexer<Lexer> {
  CommandLexer() {
    self.add("\\(", TK_LeftParen);
    self.add("\\)", TK_RightParen);
    self.add(",", TK_Comma);
    self.add("[ ]+", TK_Space);
    self.add("E\\d{4}", TK_EventTag);
    self.add("[a-zA-Z][a-zA-Z0-9]*(\\.[a-zA-Z][a-zA-Z0-9]*)*", TK_Name);
    self.add("[+\\-]?(\\d+(\\.\\d*)?|(\\.\\d+))([eE][+\\-]?\\d{1,3})?",
             TK_Number);
    self.add("\\\"[ !-~]+\\\"", TK_String);
    // <[^>]+>([^<]*)<\/[^>]+>
    self.add("\n\r|\n|\r", TK_Terminator);
  }
};

struct CommandLexerFunctor {

  typedef bool result_type;

  template <typename Token> bool operator()(const Token &CurrentToken) {

    switch (CurrentToken.id()) {
    case TK_LeftParen:
      return Context->beginScope();
    case TK_RightParen:
      return Context->endScope();
    case TK_Comma:
      return Context->endSection();
    case TK_EventTag:
      return Context->parseEventTag(tokenToString(CurrentToken));
    case TK_Name:
      return Context->parseName(tokenToString(CurrentToken));
    case TK_Number:
      return Context->parseNumber(tokenToString(CurrentToken));
    case TK_String:
      return Context->parseString(tokenToString(CurrentToken));
    case TK_XML:
      return Context->parseXML(tokenToString(CurrentToken));
    }

    return true;
  }

  template <typename Token>
  std::string tokenToString(const Token &CurrentToken) {
    return std::string(CurrentToken.value().begin(),
                       CurrentToken.value().end());
  }

  std::shared_ptr<CommandParserContext> Context =
      std::make_shared<CommandParserContext>();
};

struct CommandParser::Private {
  CommandLexer<lex::lexertl::lexer<>> Lexer;
};

CommandParser::CommandParser() : Impl(std::make_unique<Private>()) {}

CommandParser::~CommandParser() = default;

std::pair<bool, Command> CommandParser::parse(const std::string &Text) {
  if (Text.empty())
    return std::make_pair(false, Command());

  CommandLexerFunctor LexerFunctor;
  const char *First = Text.c_str();
  const char *Last = &First[Text.length()];
  lex::tokenize(First, Last, Impl->Lexer, LexerFunctor);
  return std::make_pair(LexerFunctor.Context->hasCompleteParse(),
                        LexerFunctor.Context->ParsedCommand);
}

} // namespace jdme2x
