//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef TESTUTILS_H
#define TESTUTILS_H

#include <sstream>
#include <string>

namespace jdme2x {

template <typename T> std::string toString(const T &value) {
  std::ostringstream stream;
  stream << value;
  return stream.str();
}

} // namespace jdme2x

#endif
