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

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Number &instance) {
  if (const int *specificValue = std::get_if<int>(&instance))
    stream << *specificValue;
  else
    stream << std::get<double>(instance);
  return stream;
}

} // namespace jdme2x
