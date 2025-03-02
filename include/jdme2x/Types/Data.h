//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_DATA_H
#define JDME2X_TYPES_DATA_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Number.h"
#include "jdme2x/Types/Property.h"

#include <ostream>
#include <utility>
#include <variant>
#include <vector>

namespace jdme2x {

namespace types {

typedef PropertyArgumentList NumericalData;

typedef std::pair<String, String> PropertyData;

typedef std::vector<Property> PropertyList;

typedef std::variant<NumericalData, PropertyData, PropertyList, Method> Data;

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const PropertyData &Instance);

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const PropertyList &Instance);

JDME2X_API std::ostream &operator<<(std::ostream &Stream, const Data &Instance);

} // namespace types

} // namespace jdme2x

#endif
