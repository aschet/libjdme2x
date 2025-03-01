//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef PARSER_COMMANDLEXERIMPL_H
#define PARSER_COMMANDLEXERIMPL_H

#include "jdme2x/Parser/TokenID.h"

#include <boost/spirit/include/lex_lexertl.hpp>
#include <functional>
#include <string>

namespace jdme2x {

namespace parser {

class CommandLexerImpl
    : public boost::spirit::lex::lexer<boost::spirit::lex::lexertl::lexer<>> {
public:
  CommandLexerImpl();

  void add(const char *Pattern, TokenID ID);

  bool
  tokenize(std::string_view Text,
           std::function<bool(TokenID, std::string_view)> TokenHandler) const;
};

} // namespace parser

} // namespace jdme2x

#endif
