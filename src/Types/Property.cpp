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

#include <algorithm>
#include <iterator>
#include <sstream>

namespace jdme2x {

namespace types {

Property::Property(const Name &PropertyName) : PropertyName(PropertyName) {}

void Property::setName(const Name &Value) { PropertyName = Value; }

const Name &Property::getName() const { return PropertyName; }

Property &Property::addArgument(const Number &Value) {
  PropertyArguments.emplace_back(Value);
  return *this;
}

Property &Property::addArgument(Number &&Value) {
  PropertyArguments.emplace_back(Value);
  return *this;
}

void Property::clearArguments() { PropertyArguments.clear(); }

const PropertyArgumentList &Property::getArguments() const {
  return PropertyArguments;
}

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Property &Instance) {
  Stream << Instance.PropertyName << '(' << Instance.PropertyArguments << ')';
  return Stream;
}

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const PropertyArgumentList &Instance) {
  return writeList(Stream, Instance);
}

} // namespace types

} // namespace jdme2x
