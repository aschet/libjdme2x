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

using Number = std::variant<int, double>;

constexpr bool holdsInt(const Number &value) {
  return std::holds_alternative<int>(value);
}

constexpr bool holdsBool(const Number &value) {
  if (const int *specificValue = std::get_if<int>(&value)) {
    if (*specificValue == 0 || *specificValue == 1)
      return true;
  }
  return false;
}

constexpr bool holdsDouble(const Number &value) {
  return std::holds_alternative<double>(value);
}

constexpr int getInt(const Number &value) {
  if (const int *specificValue = std::get_if<int>(&value))
    return *specificValue;
  return static_cast<int>(std::get<double>(value));
}

constexpr bool getBool(const Number &value) {
  return static_cast<bool>(getInt(value));
}

constexpr double getDouble(const Number &value) {
  if (const double *specificValue = std::get_if<double>(&value))
    return *specificValue;
  return static_cast<double>(std::get<int>(value));
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Number &instance);

} // namespace jdme2x

#endif
