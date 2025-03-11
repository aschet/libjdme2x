//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_STRING_H
#define JDME2X_TYPES_STRING_H

#include "jdme2x/API.h"

#include <ostream>
#include <string>
#include <string_view>

namespace jdme2x {
namespace types {

struct JDME2X_API String {
  String() = default;

  String(const String &) = default;

  String(String &&) = default;

  String(const char *text);

  String(const std::string &text);

  String(std::string_view text);

  String &operator=(const String &) = default;

  String &operator=(String &&) = default;

  bool operator==(const String &other) const;

  bool operator!=(const String &other) const;

  bool operator<(const String &other) const;

  std::string value;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const String &instance);

} // namespace types
} // namespace jdme2x

#endif
