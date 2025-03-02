//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_ARGUMENT_H
#define JDME2X_TYPES_ARGUMENT_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Name.h"
#include "jdme2x/Types/Number.h"
#include "jdme2x/Types/Property.h"
#include "jdme2x/Types/String.h"
#include "jdme2x/Types/Tag.h"

#include <ostream>
#include <variant>

namespace jdme2x {

namespace types {

typedef std::variant<Number, Property, Name, String, Tag> Argument;

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Argument &Instance);

} // namespace types

} // namespace jdme2x

#endif
