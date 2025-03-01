//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/ResponseLexer.h"

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <utility>
#include <vector>

using namespace jdme2x::parser;

typedef std::vector<std::pair<TokenID, std::string>> ResponseTokens;

static ResponseTokens tokenize(const char *Text) {
  ResponseLexer Lexer;
  ResponseTokens Tokens;
  Lexer.tokenize(Text, [&Tokens](TokenID ID, std::string_view Text) -> bool {
    Tokens.emplace_back(std::make_pair(ID, Text));
    return true;
  });
  return Tokens;
}

BOOST_AUTO_TEST_SUITE(ResponseLexerTest)

BOOST_AUTO_TEST_CASE(tokenizeAcknowledgment) {
  ResponseTokens ExpectedTokens = {{TokenID::Number, "00005"},
                                   {TokenID::Space, " "},
                                   {TokenID::Ampersand, "&"},
                                   {TokenID::Terminator, "\r\n"}};

  ResponseTokens ActualTokens = tokenize("00005 &\r\n");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_CASE(tokenizeTransactionCompletion) {
  ResponseTokens ExpectedTokens = {{TokenID::EventTag, "E0005"},
                                   {TokenID::Space, " "},
                                   {TokenID::PercentSign, "%"},
                                   {TokenID::Terminator, "\r\n"}};

  ResponseTokens ActualTokens = tokenize("E0005 %\r\n");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_CASE(tokenizeError) {
  ResponseTokens ExpectedTokens = {
      {TokenID::Number, "00070"},
      {TokenID::Space, " "},
      {TokenID::ExclamationMark, "!"},
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

  ResponseTokens ActualTokens =
      tokenize("00070 ! Error(2,0006,\"00070 GoTo(X(20.0),Y(40.0),"
               "Z(60.0))\",\"Transaction aborted (Use ClearAllErrors to "
               "Continue)\")\r\n");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_CASE(tokenizeData) {
  ResponseTokens ExpectedTokens = {
      {TokenID::EventTag, "E0060"}, {TokenID::Space, " "},
      {TokenID::NumberSign, "#"},   {TokenID::Name, "X"},
      {TokenID::OpenParen, "("},    {TokenID::Number, "0.35145"},
      {TokenID::CloseParen, ")"},   {TokenID::Comma, ","},
      {TokenID::Name, "Y"},         {TokenID::OpenParen, "("},
      {TokenID::Number, "0.70290"}, {TokenID::CloseParen, ")"},
      {TokenID::Comma, ","},        {TokenID::Name, "Z"},
      {TokenID::OpenParen, "("},    {TokenID::Number, "1.05435"},
      {TokenID::CloseParen, ")"},   {TokenID::Terminator, "\r\n"}};

  ResponseTokens ActualTokens =
      tokenize("E0060 #X(0.35145),Y(0.70290),Z(1.05435)\r\n");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_SUITE_END()
