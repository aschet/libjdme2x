//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Number.h"

#include <string>

namespace jdme2x {

namespace types {

JDME2X_API bool isInt(const Number &Value) {
  return std::holds_alternative<int>(Value);
}

JDME2X_API bool isFloat(const Number &Value) {
  return std::holds_alternative<float>(Value);
}

JDME2X_API int toInt(const Number &Value) {
  if (isInt(Value))
    return std::get<int>(Value);
  else
    return static_cast<int>(std::get<float>(Value));
}

JDME2X_API float toFloat(const Number &Value) {
  if (isInt(Value))
    return static_cast<float>(std::get<int>(Value));
  else
    return std::get<float>(Value);
}

JDME2X_API bool toBool(const Number &Value) {
  return static_cast<bool>(toInt(Value));
}

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const jdme2x::types::Number &Instance) {
  if (jdme2x::types::isInt(Instance)) {
    Stream << std::get<int>(Instance);
  } else {
    Stream << std::get<float>(Instance);
  }
  return Stream;
}

} // namespace types

} // namespace jdme2x

