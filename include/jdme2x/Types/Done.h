//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_DONE_H
#define JDME2X_TYPES_DONE_H

#include "jdme2x/API.h"

#include <ostream>

namespace jdme2x {
namespace types {

constexpr char DoneID = '%';

class JDME2X_API Done {
public:
  Done() = default;

  Done(const Done &) = default;

  Done(Done &&) = default;

  Done &operator=(const Done &) = default;

  Done &operator=(Done &&) = default;

  bool operator==(const Done &) const;

  bool operator!=(const Done &) const;

  bool operator<(const Done &) const;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream, const Done &);

} // namespace types
} // namespace jdme2x

#endif
