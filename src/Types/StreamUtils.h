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

namespace types {

template <typename T>
std::ostream &writeList(std::ostream &Stream, const T &Instance) {
  if (!Instance.empty()) {
    auto End = Instance.end() - 1;
    for (auto It = Instance.begin(); It != End; ++It) {
      Stream << *It << ", ";
    }
    Stream << Instance.back();
  }
  return Stream;
}

} // namespace types

} // namespace jdme2x

#endif
