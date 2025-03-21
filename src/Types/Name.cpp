//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Name.h"

namespace jdme2x {

Name::Name(const char *text) : value(text) {}

Name::Name(std::string_view text) : value(text) {}

Name::Name(const std::string &text) : value(text) {}

Name::Name(std::string &&text) : value(text) {}

bool Name::operator==(const Name &other) const { return value == other.value; }

bool Name::operator!=(const Name &other) const { return !operator==(other); }

bool Name::operator<(const Name &other) const { return value < other.value; }

bool Name::isBasic() const { return value.find('.') == std::string::npos; }

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Name &instance) {
  stream << instance.value;
  return stream;
}

} // namespace jdme2x
