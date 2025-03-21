//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Property.h"

#include "StreamUtils.h"

namespace jdme2x {

Property::Property(const Name &name) : name(name) {}

Property::Property(Name &&name) : name(name) {}

bool Property::operator==(const Property &other) const {
  if (this == &other)
    return true;
  return name == other.name && args == other.args;
}

bool Property::operator!=(const Property &other) const {
  return !operator==(other);
}

bool Property::operator<(const Property &other) const {
  return name < other.name;
}

Property &Property::with(const Number &number) {
  args.emplace_back(number);
  return *this;
}

Property &Property::with(Number &&number) {
  args.emplace_back(number);
  return *this;
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Property &instance) {
  stream << instance.name << '(' << instance.args << ')';
  return stream;
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const NumericalData &instance) {
  return writeList(stream, instance);
}

} // namespace jdme2x
