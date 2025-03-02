//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/String.h"

namespace jdme2x {

namespace types {

String::String() = default;

String::String(std::string_view Value) : Value(unquoted(Value)) {}

String &String::operator=(std::string_view Other) {
  Value = unquoted(Other);
  return *this;
};

std::string_view String::unquoted(std::string_view Value) {
  if (Value.length() < 2)
    return Value;

  if (Value[0] == '"')
    Value.remove_prefix(1);

  if (Value[Value.length() - 1] == '"')
    Value.remove_suffix(1);

  return Value;
}

String::operator const std::string &() const { return Value; }

bool String::operator==(std::string_view Other) const { return Value == Other; }

bool String::operator!=(std::string_view Other) const { return Value != Other; }

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const String &Instance) {
  Stream << '"' << Instance.Value << '"';
  return Stream;
}

} // namespace types

} // namespace jdme2x
