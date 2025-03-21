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

#include "ResponseParserStates.h"
#include "jdme2x/Parser/Lexer.h"

using namespace jdme2x::parser::states;

namespace jdme2x {

struct ResponseParser::Private {
  Lexer lexer;
};

ResponseParser::ResponseParser() : impl(std::make_unique<Private>()) {}

ResponseParser::~ResponseParser() = default;

ResponseParser::ResponseParser(ResponseParser &&) = default;

ResponseParser &ResponseParser::operator=(ResponseParser &&) = default;

std::pair<bool, Response> ResponseParser::parse(std::string_view text) {
  if (text.empty())
    return std::make_pair(false, Response());

  ResponseParserContext context(Singleton<ResponseStartState>::instance());
  impl->lexer.tokenize(text,
                       [&context](TokenID id, std::string_view text) -> bool {
                         return context.parse(id, text);
                       });
  return std::make_pair(context.hasCompleteParse(),
                        Response(std::move(context.data.response)));
}

} // namespace jdme2x
