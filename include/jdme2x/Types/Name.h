//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_NAME_H
#define JDME2X_TYPES_NAME_H

#include "jdme2x/API.h"

#include <ostream>
#include <string>
#include <string_view>

namespace jdme2x {
namespace types {

class JDME2X_API Name {
public:
  Name() = default;

  Name(const Name &) = default;

  Name(Name &&) = default;

  Name(const char *text);

  Name(std::string_view text);

  Name(const std::string &text);

  Name(std::string &&text);

  Name &operator=(const Name &) = default;

  Name &operator=(Name &&) = default;

  bool operator==(const Name &other) const;

  bool operator!=(const Name &other) const;

  bool operator<(const Name &other) const;

  bool isBasic() const;

  std::string value;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream, const Name &instance);

} // namespace types
} // namespace jdme2x

#endif
