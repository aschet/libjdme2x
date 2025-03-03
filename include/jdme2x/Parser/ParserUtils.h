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
#include "jdme2x/Types/Number.h"
#include "jdme2x/Types/Tag.h"

#include <optional>
#include <string_view>

namespace jdme2x {

namespace parser {

JDME2X_API std::optional<types::Tag> parseTag(std::string_view Text);

JDME2X_API std::optional<types::Number> parseNumber(std::string_view Text);

} // namespace parser

} // namespace jdme2x

#endif
