//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Done.h"

namespace jdme2x {
namespace types {

bool Done::operator==(const Done &) const { return true; }

bool Done::operator!=(const Done &) const { return false; }

bool Done::operator<(const Done &) const { return false; }

JDME2X_API std::ostream &operator<<(std::ostream &stream, const Done &) {
  stream << DoneID;
  return stream;
}

} // namespace types
} // namespace jdme2x
