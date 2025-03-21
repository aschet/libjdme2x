//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_PARSER_LEXER_H
#define JDME2X_PARSER_LEXER_H

#include "jdme2x/API.h"

#include <functional>
#include <memory>
#include <string_view>

namespace jdme2x {

enum class TokenID {
  OpenParen = 1,
  CloseParen,
  Comma,
  Space,
  EventTag,
  Name,
  Number,
  String,
  XML,
  Terminator,
  ResponseType
};

struct LexerImpl;

class JDME2X_API Lexer {
public:
  Lexer();

  ~Lexer();

  Lexer(const Lexer &) = delete;

  Lexer(Lexer &&);

  Lexer &operator=(const Lexer &) = delete;

  Lexer &operator=(Lexer &&);

  /**
   * @brief Tokenizes the input text.
   *
   * @param text The input text to tokenize.
   * @param tokenHandler The handler function to process tokens.
   * @return bool Returns true if tokenization is successful.
   */
  bool
  tokenize(std::string_view text,
           std::function<bool(TokenID, std::string_view)> tokenHandler) const;

private:
  std::unique_ptr<LexerImpl> impl;
};

} // namespace jdme2x

#endif
