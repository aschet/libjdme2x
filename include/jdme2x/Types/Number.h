//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_NUMBER_H
#define JDME2X_TYPES_NUMBER_H

#include "jdme2x/API.h"

#include <ostream>
#include <variant>

namespace jdme2x {
namespace types {

using Number = std::variant<int, float>;

bool holdsInt(const Number &value) {
  return std::holds_alternative<int>(value);
}

bool holdsBool(const Number &value) {
  if (auto intValue = std::get_if<int>(&value)) {
    if (*intValue == 0 || *intValue == 1)
      return true;
  }
  return false;
}

bool holdsFloat(const Number &value) {
  return std::holds_alternative<float>(value);
}

JDME2X_API int getInt(const Number &value);

JDME2X_API bool getBool(const Number &value);

JDME2X_API float getFloat(const Number &value);

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Number &instance);

} // namespace types
} // namespace jdme2x

#endif
