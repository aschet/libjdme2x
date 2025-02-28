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

namespace jdme2x {
namespace types {

constexpr char DataID = '#';

using PropertyData = std::pair<String, String>;

using PropertyList = std::vector<Property>;

using Data = std::variant<std::monostate, NumericalData, PropertyData,
                          PropertyList, Method>;

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const PropertyData &instance);

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const PropertyList &instance);

JDME2X_API std::ostream &operator<<(std::ostream &stream, const Data &instance);

} // namespace types
} // namespace jdme2x

#endif
