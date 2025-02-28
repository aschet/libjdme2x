//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Command.h"

#include <utility>

namespace jdme2x {
namespace types {

Command::Command(const Tag &tag, const Method &method)
    : tag(tag), method(method) {}

Command::Command(const Tag &tag, Method &&method) : tag(tag), method(method) {}

bool Command::operator==(const Command &other) const {
  if (this == &other)
    return true;
  return tag == other.tag && method == other.method;
}

bool Command::operator!=(const Command &other) const {
  return !operator==(other);
}

bool Command::operator<(const Command &other) const { return tag < other.tag; }

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Command &instance) {
  stream << instance.tag << ' ' << instance.method << "\r\n";
  return stream;
}

} // namespace types
} // namespace jdme2x
