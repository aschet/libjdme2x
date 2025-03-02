//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_NUMBER_H
#define JDME2X_NUMBER_H

#include "jdme2x/API.h"

#include <variant>

namespace jdme2x {

typedef std::variant<int, float> Number;

JDME2X_API bool isInt(const Number& Value);

JDME2X_API bool isFloat(const Number &Value);

JDME2X_API int toInt(const Number &Value);

JDME2X_API float toFloat(const Number &Value);

} // namespace jdme2x

#endif
