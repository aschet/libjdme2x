#include "jdme2x/Parser/CommandLexer.h"

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <utility>
#include <vector>

using namespace jdme2x::parser;

typedef std::vector<std::pair<CommandTokenID, std::string>> CommandTokens;

static CommandTokens tokenize(const char *Text) {
  CommandLexer Lexer;
  CommandTokens Tokens;
  Lexer.tokenize(
      Text,
      [&Tokens](CommandTokenID TokenID, const std::string &TokenText) -> bool {
        Tokens.emplace_back(std::make_pair(TokenID, TokenText));
        return true;
      });
  return Tokens;
}

BOOST_AUTO_TEST_SUITE(CommandLexerTest)

BOOST_AUTO_TEST_CASE(tokenizeCommand) {
  CommandTokens ExpectedTokens = {{CommandTokenID::Number, "00001"},
                                  {CommandTokenID::Space, " "},
                                  {CommandTokenID::Name, "Test"},
                                  {CommandTokenID::OpenParen, "("},
                                  {CommandTokenID::String, "\"Ref Tool\""},
                                  {CommandTokenID::Comma, ","},
                                  {CommandTokenID::EventTag, "E0001"},
                                  {CommandTokenID::Comma, ","},
                                  {CommandTokenID::Name, "XT.R.A"},
                                  {CommandTokenID::OpenParen, "("},
                                  {CommandTokenID::CloseParen, ")"},
                                  {CommandTokenID::Comma, ","},
                                  {CommandTokenID::Name, "Roi"},
                                  {CommandTokenID::OpenParen, "("},
                                  {CommandTokenID::Number, "-5"},
                                  {CommandTokenID::Comma, ","},
                                  {CommandTokenID::Number, ".5"},
                                  {CommandTokenID::Comma, ","},
                                  {CommandTokenID::Number, "+5E7"},
                                  {CommandTokenID::Comma, ","},
                                  {CommandTokenID::Number, "5e-03"},
                                  {CommandTokenID::CloseParen, ")"},
                                  {CommandTokenID::CloseParen, ")"},
                                  {CommandTokenID::Terminator, "\n\r"}};

  CommandTokens ActualTokens =
      tokenize("00001 Test(\"Ref "
               "Tool\",E0001,XT.R.A(),Roi(-5,.5,+5E7,5e-03))\n\r");

  BOOST_TEST(ExpectedTokens == ActualTokens);
}

BOOST_AUTO_TEST_SUITE_END()
