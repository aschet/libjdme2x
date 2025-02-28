//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "CommandLexerImpl.h"

namespace lex = boost::spirit::lex;

namespace jdme2x {
namespace parser {

struct LexerFunctorAdapter {
  typedef bool result_type;

  LexerFunctorAdapter(std::function<bool(TokenID, std::string_view)> functor)
      : functor(functor) {}

  template <typename Token> bool operator()(const Token &token) const {
    const char *first = &*token.value().begin();
    const char *last = &*token.value().end();
    std::string_view text(first, last - first);
    return functor(static_cast<TokenID>(token.id()), text);
  }

  std::function<bool(TokenID, std::string_view)> functor;
};

CommandLexerImpl::CommandLexerImpl() {
  add("\\(", TokenID::OpenParen);
  add("\\)", TokenID::CloseParen);
  add(",", TokenID::Comma);
  add("[ ]+", TokenID::Space);
  add("E\\d{4}", TokenID::EventTag);
  add("[a-zA-Z][a-zA-Z0-9]*(\\.[a-zA-Z][a-zA-Z0-9]*)*", TokenID::Name);
  add("[+\\-]?(\\d+(\\.\\d*)?|(\\.\\d+))([eE][+\\-]?\\d{1,3})?",
      TokenID::Number);
  add("\\\"[ -!#-~]+\\\"", TokenID::String);
  add("<[^>]+>.*<\\/[^>]+>", TokenID::XML);
  add("\r\n|\n|\r", TokenID::Terminator);
}

void CommandLexerImpl::add(const char *pattern, TokenID id) {
  this->self.add(pattern, static_cast<size_t>(id));
}

bool CommandLexerImpl::tokenize(
    std::string_view text,
    std::function<bool(TokenID, std::string_view)> tokenHandler) const {
  LexerFunctorAdapter functorAdapter(tokenHandler);
  const char *first = text.data();
  const char *last = first + text.length();
  return lex::tokenize(first, last, *this, functorAdapter);
}

} // namespace parser
} // namespace jdme2x
