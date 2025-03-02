//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/ParserUtils.h"

#include <charconv>

namespace jdme2x {

namespace parser {

JDME2X_API std::optional<types::Number> parseNumber(std::string_view Text) {
  if (Text.empty())
    return std::nullopt;

  constexpr size_t MaxNumberLength = 16;
  if (Text.length() > MaxNumberLength)
    return std::nullopt;

  if (Text.front() == '+')
    Text.remove_prefix(1);

  if (Text.find_first_of(".eE") != std::string::npos) {
    float ParsedNumber = 0.0f;
    auto [Ptr, Error] =
        std::from_chars(Text.data(), Text.data() + Text.size(), ParsedNumber);
    if (Error != std::errc())
      return std::nullopt;
    return types::Number(ParsedNumber);
  } else {
    int ParsedNumber = 0;
    auto [Ptr, Error] =
        std::from_chars(Text.data(), Text.data() + Text.size(), ParsedNumber);
    if (Error != std::errc())
      return std::nullopt;
    return types::Number(ParsedNumber);
  }
}

} // namespace parser

} // namespace jdme2x
