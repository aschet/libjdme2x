//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TAG_H
#define JDME2X_TAG_H

#include "jdme2x/API.h"
#include "jdme2x/Serializeable.h"

namespace jdme2x {

enum class TagType { Command, Event };

class JDME2X_API Tag : public Serializeable {
public:
  Tag();
  
  Tag(unsigned int Number, TagType Type);

  void setNumber(unsigned int Value);

  unsigned int getNumber() const;

  void setType(TagType Value);

  TagType getType() const;

  std::string toString() const override;

private:
  unsigned int Number;

  TagType Type;
};

} // namespace jdme2x

#endif
