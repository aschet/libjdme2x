#include "jdme2x/Parser/ResponseLexer.h"

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <utility>
#include <vector>

using namespace jdme2x::parser;

typedef std::vector<std::pair<ResponseTokenID, std::string>> ResponseTokens;

static ResponseTokens tokenize(const char *Text) {
  ResponseLexer Lexer;
  ResponseTokens Tokens;
  Lexer.tokenize(
      Text,
      [&Tokens](ResponseTokenID TokenID, const std::string &TokenText) -> bool {
        Tokens.emplace_back(std::make_pair(TokenID, TokenText));
        return true;
      });
  return Tokens;
}

BOOST_AUTO_TEST_SUITE(ResponseLexerTest)

BOOST_AUTO_TEST_CASE(tokenizeAcknowledgment) {
  ResponseTokens ExpectedTokens = {{ResponseTokenID::Number, "00005"},
                                   {ResponseTokenID::Space, " "},
                                   {ResponseTokenID::Ampersand, "&"},
                                   {ResponseTokenID::Terminator, "\n\r"}};

  ResponseTokens ActualTokens = tokenize("00005 &\n\r");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_CASE(tokenizeTransactionCompletion) {
  ResponseTokens ExpectedTokens = {{ResponseTokenID::EventTag, "E0005"},
                                   {ResponseTokenID::Space, " "},
                                   {ResponseTokenID::PercentSign, "%"},
                                   {ResponseTokenID::Terminator, "\n\r"}};

  ResponseTokens ActualTokens = tokenize("E0005 %\n\r");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_CASE(tokenizeError) {
  ResponseTokens ExpectedTokens = {
      {ResponseTokenID::EventTag, "00070"},
      {ResponseTokenID::Space, " "},
      {ResponseTokenID::ExclamationMark, "!"},
      {ResponseTokenID::Space, " "},
      {ResponseTokenID::Name, "Error"},
      {ResponseTokenID::OpenParen, "("},
      {ResponseTokenID::Number, "2"},
      {ResponseTokenID::Comma, ","},
      {ResponseTokenID::Number, "0006"},
      {ResponseTokenID::String, "\"00070 GoTo(X(20.0),Y(40.0),Z(60.0))\""},
      {ResponseTokenID::Comma, ","},
      {ResponseTokenID::String,
       "\"Transaction aborted (Use ClearAllErrors to Continue)\""},
      {ResponseTokenID::CloseParen, ")"},
      {ResponseTokenID::Terminator, "\n\r"}};

  ResponseTokens ActualTokens =
      tokenize("00070 ! Error(2,0006,\"00070 GoTo(X(20.0),Y(40.0),"
               "Z(60.0))\",\"Transaction aborted (Use ClearAllErrors to "
               "Continue)\")\n\r");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_CASE(tokenizeData) {
  ResponseTokens ExpectedTokens = {{ResponseTokenID::EventTag, "E0060"},
                                   {ResponseTokenID::Space, " "},
                                   {ResponseTokenID::NumberSign, "#"},
                                   {ResponseTokenID::Name, "X"},
                                   {ResponseTokenID::OpenParen, "("},
                                   {ResponseTokenID::Number, "0.35145"},
                                   {ResponseTokenID::CloseParen, ")"},
                                   {ResponseTokenID::Comma, ","},
                                   {ResponseTokenID::Name, "Y"},
                                   {ResponseTokenID::OpenParen, "("},
                                   {ResponseTokenID::Number, "0.70290"},
                                   {ResponseTokenID::CloseParen, ")"},
                                   {ResponseTokenID::Comma, ","},
                                   {ResponseTokenID::Name, "Z"},
                                   {ResponseTokenID::OpenParen, "("},
                                   {ResponseTokenID::Number, "1.05435"},
                                   {ResponseTokenID::CloseParen, ")"},
                                   {ResponseTokenID::Terminator, "\n\r"}};

  ResponseTokens ActualTokens =
      tokenize("E0060 #X(0.35145),Y(0.70290),Z(1.05435)\n\r");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_SUITE_END()
