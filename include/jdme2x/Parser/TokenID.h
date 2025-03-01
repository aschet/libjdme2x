//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_PARSER_TOKENID_H
#define JDME2X_PARSER_TOKENID_H

namespace jdme2x {

namespace parser {

enum class TokenID : unsigned int {
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
  NumberSign,
  ExclamationMark,
  Ampersand,
  PercentSign,
};

} // namespace parser

} // namespace jdme2x

#endif
