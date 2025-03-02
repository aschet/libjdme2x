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

typedef std::vector<Number> PropertyArgumentList;

class JDME2X_API Property {
  friend std::ostream &operator<<(std::ostream &, const Property &);

public:
  Property() = default;

  Property(const Property &) = default;

  Property(Property &&) = default;

  Property(const Name &PropertyName);

  void setName(const Name &Value);

  const Name &getName() const;

  Property &addArgument(const Number &Value);

  Property &addArgument(Number &&Value);

  void clearArguments();

  const PropertyArgumentList &getArguments() const;

  Property &operator=(const Property &) = default;

  Property &operator=(Property &&) = default;

private:
  types::Name PropertyName;

  PropertyArgumentList PropertyArguments;
};

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const PropertyArgumentList &Instance);

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Property &Instance);

} // namespace types

} // namespace jdme2x

#endif
