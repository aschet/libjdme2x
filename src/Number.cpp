//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Number.h"

#include <any>

namespace jdme2x {

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

} // namespace jdme2x
