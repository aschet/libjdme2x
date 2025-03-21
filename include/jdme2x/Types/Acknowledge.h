//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_AKNOWLEDGE_H
#define JDME2X_TYPES_AKNOWLEDGE_H

#include "jdme2x/API.h"

#include <ostream>

namespace jdme2x {

constexpr char AcknowledgeID = '&';

struct JDME2X_API Acknowledge {
  Acknowledge() = default;

  Acknowledge(const Acknowledge &) = default;

  Acknowledge(Acknowledge &&) = default;

  Acknowledge &operator=(const Acknowledge &) = default;

  Acknowledge &operator=(Acknowledge &&) = default;

  bool operator==(const Acknowledge &) const;

  bool operator!=(const Acknowledge &) const;

  bool operator<(const Acknowledge &) const;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream, const Acknowledge &);

} // namespace jdme2x

#endif
