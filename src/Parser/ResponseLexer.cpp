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
    add("#", TokenID::NumberSign);
    add("!", TokenID::ExclamationMark);
    add("&", TokenID::Ampersand);
    add("%", TokenID::PercentSign);
  }
};

ResponseLexer::ResponseLexer()
    : Impl(std::make_unique<ResponseLexerDefinition>()) {}

ResponseLexer::~ResponseLexer() = default;

bool ResponseLexer::tokenize(
    std::string_view Text,
    std::function<bool(TokenID, std::string_view)> TokenHandler) {
  return Impl->tokenize(Text, TokenHandler);
}

} // namespace parser

} // namespace jdme2x
