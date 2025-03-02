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

namespace jdme2x {

namespace types {

class JDME2X_API Command {
  friend std::ostream &operator<<(std::ostream &, const Command &);

public:
  Command() = default;

  Command(const Tag &CommandTag, const Method &CommandMethod);

  Command(const Tag &CommandTag, Method &&CommandMethod);

  Command(const Command &) = default;

  Command(Command &&) = default;

  void setTag(const Tag &Value);

  const Tag &getTag() const;

  void setMethod(const Method &Value);

  void setMethod(Method &&Value);

  const Method &getMethod() const;

  Method &getMethod();

  Command &operator=(const Command &) = default;

  Command &operator=(Command &&) = default;

private:
  Tag CommandTag;

  Method CommandMethod;
};

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Command &Instance);

} // namespace types

} // namespace jdme2x

#endif
