//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_PROPERTY_H
#define JDME2X_TYPES_PROPERTY_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Name.h"
#include "jdme2x/Types/Number.h"

#include <ostream>
#include <string>
#include <vector>

namespace jdme2x {
namespace types {

using NumericalData = std::vector<Number>;

class JDME2X_API Property {
public:
  Property() = default;

  Property(const Property &) = default;

  Property(Property &&) = default;

  Property(const Name &name);

  Property(Name &&name);

  Property &operator=(const Property &) = default;

  Property &operator=(Property &&) = default;

  bool operator==(const Property &other) const;

  bool operator!=(const Property &other) const;

  bool operator<(const Property &other) const;

  Property &with(const Number &number);

  Property &with(Number &&number);

  Name name;

  NumericalData args;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const NumericalData &instance);

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Property &instance);

} // namespace types
} // namespace jdme2x

#endif
