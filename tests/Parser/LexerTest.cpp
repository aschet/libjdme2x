//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/Lexer.h"

#include <boost/test/unit_test.hpp>
#include <utility>
#include <vector>

using namespace jdme2x;

using Tokens = std::vector<std::pair<TokenID, std::string>>;

static Tokens tokenize(const char *text) {
  Lexer lexer;
  Tokens tokens;
  lexer.tokenize(text, [&tokens](TokenID id, std::string_view text) -> bool {
    tokens.emplace_back(std::make_pair(id, text));
    return true;
  });
  return tokens;
}

BOOST_AUTO_TEST_SUITE(LexerTest)

BOOST_AUTO_TEST_CASE(tokenizeCommand) {
  Tokens expectedTokens = {{TokenID::Number, "00001"},
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
  BOOST_TEST(expectedTokens ==
             tokenize("00001 Test(\"Ref "
                      "Tool\",E0001,XT.R.A(),Roi(-5,.5,+5E7,5e-03))\r\n"));
}

BOOST_AUTO_TEST_CASE(tokenizeXMLCommand) {
  Tokens expectedTokens = {{TokenID::EventTag, "E0001"},
                           {TokenID::Space, " "},
                           {TokenID::Name, "TestE"},
                           {TokenID::OpenParen, "("},
                           {TokenID::XML, "<x><y a=\"b\">z</y></x>"},
                           {TokenID::CloseParen, ")"},
                           {TokenID::Terminator, "\r\n"}};
  BOOST_TEST(expectedTokens ==
             tokenize("E0001 TestE(<x><y a=\"b\">z</y></x>)\r\n"));
}

BOOST_AUTO_TEST_CASE(tokenizeAcknowledgeResponse) {
  Tokens expectedTokens = {{TokenID::Number, "00005"},
                           {TokenID::Space, " "},
                           {TokenID::ResponseType, "&"},
                           {TokenID::Terminator, "\r\n"}};
  BOOST_TEST(expectedTokens == tokenize("00005 &\r\n"));
}

BOOST_AUTO_TEST_CASE(tokenizeDoneResponse) {
  Tokens expectedTokens = {{TokenID::EventTag, "E0005"},
                           {TokenID::Space, " "},
                           {TokenID::ResponseType, "%"},
                           {TokenID::Terminator, "\r\n"}};
  BOOST_TEST(expectedTokens == tokenize("E0005 %\r\n"));
}

BOOST_AUTO_TEST_CASE(tokenizeErrorResponse) {
  Tokens expectedTokens = {
      {TokenID::Number, "00070"},
      {TokenID::Space, " "},
      {TokenID::ResponseType, "!"},
      {TokenID::Space, " "},
      {TokenID::Name, "Error"},
      {TokenID::OpenParen, "("},
      {TokenID::Number, "2"},
      {TokenID::Comma, ","},
      {TokenID::Number, "0006"},
      {TokenID::Comma, ","},
      {TokenID::String, "\"00070 GoTo(X(20.0),Y(40.0),Z(60.0))\""},
      {TokenID::Comma, ","},
      {TokenID::String,
       "\"Transaction aborted (Use ClearAllErrors to Continue)\""},
      {TokenID::CloseParen, ")"},
      {TokenID::Terminator, "\r\n"}};
  BOOST_TEST(expectedTokens ==
             tokenize("00070 ! Error(2,0006,\"00070 GoTo(X(20.0),Y(40.0),"
                      "Z(60.0))\",\"Transaction aborted (Use ClearAllErrors to "
                      "Continue)\")\r\n"));
}

BOOST_AUTO_TEST_CASE(tokenizeDataResponse) {
  Tokens expectedTokens = {
      {TokenID::EventTag, "E0060"}, {TokenID::Space, " "},
      {TokenID::ResponseType, "#"}, {TokenID::Name, "X"},
      {TokenID::OpenParen, "("},    {TokenID::Number, "0.35145"},
      {TokenID::CloseParen, ")"},   {TokenID::Comma, ","},
      {TokenID::Name, "Y"},         {TokenID::OpenParen, "("},
      {TokenID::Number, "0.70290"}, {TokenID::CloseParen, ")"},
      {TokenID::Comma, ","},        {TokenID::Name, "Z"},
      {TokenID::OpenParen, "("},    {TokenID::Number, "1.05435"},
      {TokenID::CloseParen, ")"},   {TokenID::Terminator, "\r\n"}};
  BOOST_TEST(expectedTokens ==
             tokenize("E0060 #X(0.35145),Y(0.70290),Z(1.05435)\r\n"));
}

BOOST_AUTO_TEST_SUITE_END()
