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
#include <sstream>

namespace jdme2x {

namespace types {

Tag::Tag() : Number(0), Type(TagType::Command) {};

Tag::Tag(unsigned int Number, TagType Type) : Number(Number), Type(Type) {}

void Tag::setNumber(unsigned int Value) { Number = Value; }

unsigned int Tag::getNumber() const { return Number; }

void Tag::setType(TagType Value) { Type = Value; }

TagType Tag::getType() const { return Type; }

bool Tag::isUnsolicitedEvent() const {
  return Type == TagType::Event && Number == 0;
}

Tag Tag::createUnsolicitedEvent() { return Tag(0, TagType::Event); }

bool Tag::operator==(const Tag &Other) const {
  return Type == Other.Type && Number == Other.Number;
}

bool Tag::operator!=(const Tag &Other) const { return !operator==(Other); }

JDME2X_API std::ostream &operator<<(std::ostream &Stream, const Tag &Instance) {
  if (Instance.Type == TagType::Command)
    Stream << std::setw(5) << std::setfill('0') << Instance.Number;
  else
    Stream << 'E' << std::setw(4) << std::setfill('0') << Instance.Number;
  return Stream;
}

} // namespace types

} // namespace jdme2x
