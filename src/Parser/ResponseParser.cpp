//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

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

bool ResponseParser::parse(std::string_view Text) {
  if (Text.empty())
    return false;

  return Impl->Lexer.tokenize(
      Text, [](TokenID ID, std::string_view Text) -> bool { return true; });
}

} // namespace parser

} // namespace jdme2x
