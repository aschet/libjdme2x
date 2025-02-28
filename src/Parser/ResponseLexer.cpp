// Copyright (c) 2025 Thomas Ascher
// SPDX-License-Identifier: BSL-1.0
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#include "jdme2x/Parser/ResponseLexer.h"

#include "CommandLexerDefinition.h"

namespace lex = boost::spirit::lex;

namespace jdme2x {

namespace parser {

class ResponseLexerDefinition : public CommandLexerDefinition {
public:
  ResponseLexerDefinition() {
    add("#", ResponseTokenID::NumberSign);
    add("!", ResponseTokenID::ExclamationMark);
    add("&", ResponseTokenID::Ampersand);
    add("%", ResponseTokenID::PercentSign);
  }
};

ResponseLexer::ResponseLexer()
    : Impl(std::make_unique<ResponseLexerDefinition>()) {}

ResponseLexer::~ResponseLexer() = default;

bool ResponseLexer::tokenize(
    const std::string &Text,
    std::function<bool(ResponseTokenID, const std::string &)> TokenHandler) {

  if (Text.empty())
    return false;

  LexerFunctorAdapter<ResponseTokenID> FunctorAdapter(TokenHandler);
  const char *First = Text.c_str();
  const char *Last = &First[Text.length()];
  return lex::tokenize(First, Last, *Impl, FunctorAdapter);
}

} // namespace parser

} // namespace jdme2x
