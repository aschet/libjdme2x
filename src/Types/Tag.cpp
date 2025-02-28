//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Tag.h"

#include <iomanip>

namespace jdme2x {
namespace types {

Tag::Tag() : number(0), type(TagType::Command) {};

Tag::Tag(unsigned int number, TagType type)
    : number(number), type(type) {}

bool Tag::operator==(const Tag &other) const {
  return type == other.type && number == other.number;
}

bool Tag::operator!=(const Tag &other) const { return !operator==(other); }

bool Tag::operator<(const Tag &other) const {
  if (type == other.type) {
    return number < other.number;
  }
  return type < other.type;
}

JDME2X_API std::ostream &operator<<(std::ostream &stream, const Tag &instance) {
  stream << std::setfill('0');
  if (instance.type == TagType::Command)
    stream << std::setw(5) << instance.number;
  else
    stream << 'E' << std::setw(4) << instance.number;
  return stream;
}

} // namespace types
} // namespace jdme2x
