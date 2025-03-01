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

#include "CommandLexerImpl.h"

namespace lex = boost::spirit::lex;

namespace jdme2x {

namespace parser {

class ResponseLexerImpl : public CommandLexerImpl {
public:
  ResponseLexerImpl() {
    add("#", TokenID::NumberSign);
    add("!", TokenID::ExclamationMark);
    add("&", TokenID::Ampersand);
    add("%", TokenID::PercentSign);
  }
};

ResponseLexer::ResponseLexer() : Impl(std::make_unique<ResponseLexerImpl>()) {}

ResponseLexer::~ResponseLexer() = default;

bool ResponseLexer::tokenize(
    std::string_view Text,
    std::function<bool(TokenID, std::string_view)> TokenHandler) const {
  return Impl->tokenize(Text, TokenHandler);
}

} // namespace parser

} // namespace jdme2x
