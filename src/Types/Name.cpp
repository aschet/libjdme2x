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

namespace types {

Name::Name() = default;

Name::Name(std::string_view Value) : Value(Value) {}

Name &Name::operator=(std::string_view Other) {
  Value = Other;
  return *this;
};

bool Name::isBasic() const { return Value.find('.') == std::string::npos; }

Name::operator const std::string &() const { return Value; }

bool Name::operator==(std::string_view Other) const { return Value == Other; }

bool Name::operator!=(std::string_view Other) const { return Value != Other; }

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Name &Instance) {
  Stream << Instance.Value;
  return Stream;
}

} // namespace types

} // namespace jdme2x
