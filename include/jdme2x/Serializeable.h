//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_SERIALIZEABLE_H
#define JDME2X_SERIALIZEABLE_H

#include "jdme2x/API.h"

#include <string>

namespace jdme2x {

class JDME2X_API Serializeable {
public:
  virtual ~Serializeable();

  virtual std::string toString() const = 0;
};

} // namespace jdme2x

#endif
