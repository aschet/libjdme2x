//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef TYPES_STREAMUTILS_H
#define TYPES_STREAMUTILS_H

#include <ostream>

namespace jdme2x {

template <typename T>
std::ostream &writeList(std::ostream &stream, const T &instance) {
  if (!instance.empty()) {
    auto end = instance.end() - 1;
    for (auto it = instance.begin(); it != end; ++it)
      stream << *it << ", ";
    stream << instance.back();
  }
  return stream;
}

} // namespace jdme2x

#endif
