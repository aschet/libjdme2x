//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_TAG_H
#define JDME2X_TYPES_TAG_H

#include "jdme2x/API.h"

#include <ostream>

namespace jdme2x {
namespace types {

enum class TagType { Command, Event };

constexpr int MinCommandNumber = 1;

constexpr int MaxCommandNumber = 99999;

constexpr int MinEventNumber = 0;

constexpr int MaxEventNumber = 9999;

class JDME2X_API Tag {
  friend std::ostream &operator<<(std::ostream &, const Tag &);

public:
  Tag();

  Tag(unsigned int Number, TagType Type);

  void setNumber(unsigned int Value);

  unsigned int getNumber() const;

  void setType(TagType Value);

  TagType getType() const;

  bool isUnsolicitedEvent() const;

  static Tag createUnsolicitedEvent();

  bool operator==(const Tag &Other) const;

  bool operator!=(const Tag &Other) const;

private:
  unsigned int Number;

  TagType Type;
};

JDME2X_API std::ostream &operator<<(std::ostream &Stream, const Tag &Instance);

} // namespace types

} // namespace jdme2x

#endif
