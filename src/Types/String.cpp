//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/String.h"

namespace jdme2x {
namespace types {

String::String(const char *text) : value(text) {}

String::String(const std::string &text) : value(text) {}

String::String(std::string_view text) : value(text) {}

bool String::operator==(const String &other) const {
  return value == other.value;
}

bool String::operator!=(const String &other) const {
  return !operator==(other);
}

bool String::operator<(const String &other) const {
  return value < other.value;
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const String &instance) {
  stream << '"' << instance.value << '"';
  return stream;
}

} // namespace types
} // namespace jdme2x
