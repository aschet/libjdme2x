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

namespace jdme2x {
namespace types {

JDME2X_API int getInt(const Number &value) {
  if (const int *intValue = std::get_if<int>(&value))
    return *intValue;
  return static_cast<int>(std::get<float>(value));
}

JDME2X_API bool getBool(const Number &value) {
  return static_cast<bool>(getInt(value));
}

JDME2X_API float getFloat(const Number &value) {
  if (const float *floatValue = std::get_if<float>(&value))
    return *floatValue;
  return static_cast<float>(std::get<int>(value));
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Number &instance) {
  if (const int *intValue = std::get_if<int>(&instance))
    stream << *intValue;
  else
    stream << std::get<float>(instance);
  return stream;
}

} // namespace types
} // namespace jdme2x
