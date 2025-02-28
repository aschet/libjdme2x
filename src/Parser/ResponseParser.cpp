// Copyright (c) 2025 Thomas Ascher
// SPDX-License-Identifier: BSL-1.0
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#include "jdme2x/Parser/ResponseParser.h"

#include "jdme2x/Parser/ResponseLexer.h"
#include "jdme2x/Parser/TokenID.h"

namespace jdme2x {

namespace parser {

struct ResponseParser::Private {
  ResponseLexer Lexer;
};

ResponseParser::ResponseParser() : Impl(std::make_unique<Private>()) {}

ResponseParser::~ResponseParser() = default;

bool ResponseParser::parse(const std::string &Text) {
  if (Text.empty())
    return false;

  return Impl->Lexer.tokenize(
      Text, [](ResponseTokenID TokenID, const std::string &TokenText) -> bool {
        return true;
      });
}

} // namespace parser

} // namespace jdme2x
