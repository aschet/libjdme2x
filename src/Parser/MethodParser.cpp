//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/MethodParser.h"

#include "MethodParserStates.h"
#include "jdme2x/Parser/Lexer.h"

#include <utility>

using namespace jdme2x::parser::states;

namespace jdme2x {

struct MethodParser::Private {
  Lexer lexer;
};

MethodParser::MethodParser() : impl(std::make_unique<Private>()) {}

MethodParser::~MethodParser() = default;

MethodParser::MethodParser(MethodParser &&) = default;

MethodParser &MethodParser::operator=(MethodParser &&) = default;

std::pair<bool, Method> MethodParser::parse(std::string_view text) {
  if (text.empty())
    return std::make_pair(false, Method());

  MethodParserContext context(Singleton<MethodStartState>::instance());
  impl->lexer.tokenize(text,
                       [&context](TokenID id, std::string_view text) -> bool {
                         return context.parse(id, text);
                       });
  return std::make_pair(context.hasCompleteParse(),
                        std::move(context.data.method));
}

} // namespace jdme2x
