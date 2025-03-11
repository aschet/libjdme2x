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

struct JDME2X_API Tag {
  Tag();

  Tag(unsigned int number, TagType type);

  Tag(const Tag &) = default;

  Tag &operator=(const Tag &) = default;

  bool operator==(const Tag &other) const;

  bool operator!=(const Tag &other) const;

  bool operator<(const Tag &other) const;

  unsigned int number;

  TagType type;
};

const Tag UnsolicitedEvent = Tag(0, TagType::Event);

JDME2X_API std::ostream &operator<<(std::ostream &stream, const Tag &instance);

} // namespace types
} // namespace jdme2x

#endif
