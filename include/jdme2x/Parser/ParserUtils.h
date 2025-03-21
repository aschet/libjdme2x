//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_PARSER_PARSERUTILS_H
#define JDME2X_PARSER_PARSERUTILS_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Error.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Number.h"
#include "jdme2x/Types/Property.h"
#include "jdme2x/Types/String.h"
#include "jdme2x/Types/Tag.h"

#include <optional>
#include <string_view>

namespace jdme2x {

JDME2X_API std::optional<Tag> createTag(std::string_view text);

JDME2X_API std::optional<Number> createNumber(std::string_view text);

JDME2X_API std::optional<String> createString(std::string_view text);

JDME2X_API std::optional<Error> createError(const Method &method);

JDME2X_API std::optional<Property> createProperty(const Method &method);

} // namespace jdme2x

#endif
