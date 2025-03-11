//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_COMMAND_H
#define JDME2X_TYPES_COMMAND_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Tag.h"

#include <ostream>
#include <utility>

namespace jdme2x {
namespace types {

struct JDME2X_API Command {
  Command() = default;

  Command(const Tag &tag, const Method &method);

  Command(const Tag &tag, Method &&method);

  Command(const Command &) = default;

  Command(Command &&) = default;

  Command &operator=(const Command &) = default;

  Command &operator=(Command &&) = default;

  bool operator==(const Command &other) const;

  bool operator!=(const Command &other) const;

  bool operator<(const Command &other) const;

  Tag tag;

  Method method;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Command &instance);

} // namespace types
} // namespace jdme2x

#endif
