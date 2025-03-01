//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/CommandLexer.h"

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <utility>
#include <vector>

using namespace jdme2x::parser;

typedef std::vector<std::pair<TokenID, std::string>> CommandTokens;

static CommandTokens tokenize(const char *Text) {
  CommandLexer Lexer;
  CommandTokens Tokens;
  Lexer.tokenize(Text, [&Tokens](TokenID ID, std::string_view Text) -> bool {
    Tokens.emplace_back(std::make_pair(ID, Text));
    return true;
  });
  return Tokens;
}

BOOST_AUTO_TEST_SUITE(CommandLexerTest)

BOOST_AUTO_TEST_CASE(tokenizeCommand) {
  CommandTokens ExpectedTokens = {{TokenID::Number, "00001"},
                                  {TokenID::Space, " "},
                                  {TokenID::Name, "Test"},
                                  {TokenID::OpenParen, "("},
                                  {TokenID::String, "\"Ref Tool\""},
                                  {TokenID::Comma, ","},
                                  {TokenID::EventTag, "E0001"},
                                  {TokenID::Comma, ","},
                                  {TokenID::Name, "XT.R.A"},
                                  {TokenID::OpenParen, "("},
                                  {TokenID::CloseParen, ")"},
                                  {TokenID::Comma, ","},
                                  {TokenID::Name, "Roi"},
                                  {TokenID::OpenParen, "("},
                                  {TokenID::Number, "-5"},
                                  {TokenID::Comma, ","},
                                  {TokenID::Number, ".5"},
                                  {TokenID::Comma, ","},
                                  {TokenID::Number, "+5E7"},
                                  {TokenID::Comma, ","},
                                  {TokenID::Number, "5e-03"},
                                  {TokenID::CloseParen, ")"},
                                  {TokenID::CloseParen, ")"},
                                  {TokenID::Terminator, "\r\n"}};

  CommandTokens ActualTokens =
      tokenize("00001 Test(\"Ref "
               "Tool\",E0001,XT.R.A(),Roi(-5,.5,+5E7,5e-03))\r\n");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_CASE(tokenizeXMLCommand) {
  CommandTokens ExpectedTokens = {{TokenID::EventTag, "E0001"},
                                  {TokenID::Space, " "},
                                  {TokenID::Name, "TestE"},
                                  {TokenID::OpenParen, "("},
                                  {TokenID::XML, "<x><y a=\"b\">z</y></x>"},
                                  {TokenID::CloseParen, ")"},
                                  {TokenID::Terminator, "\r\n"}};

  CommandTokens ActualTokens =
      tokenize("E0001 TestE(<x><y a=\"b\">z</y></x>)\r\n");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_SUITE_END()
