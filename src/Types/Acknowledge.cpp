//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Acknowledge.h"

namespace jdme2x {

bool Acknowledge::operator==(const Acknowledge &) const { return true; }

bool Acknowledge::operator!=(const Acknowledge &) const { return false; }

bool Acknowledge::operator<(const Acknowledge &) const { return false; }

JDME2X_API std::ostream &operator<<(std::ostream &stream, const Acknowledge &) {
  stream << AcknowledgeID;
  return stream;
}

} // namespace jdme2x
