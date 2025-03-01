//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Method.h"

#include <sstream>

namespace jdme2x {

Method::Method() = default;

Method::Method(std::string_view Name) : Name(Name) {}

void Method::setName(std::string_view Value) { Name = Value; }

const std::string &Method::getName() const { return Name; }

const Arguments &Method::getArguments() const { return MethodArguments; }

Method &Method::addArgument(std::shared_ptr<Argument> Value) {
  XML.clear();
  MethodArguments.emplace_back(Value);
  return *this;
}

Method &Method::addValue(int Value) {
  return addArgument(std::make_shared<IntArgument>(Value));
}

Method &Method::addValue(float Value) {
  return addArgument(std::make_shared<FloatArgument>(Value));
}

Method &Method::addString(std::string_view Value) {
  return addArgument(std::make_shared<StringArgument>(Value));
}

Method &Method::addName(std::string_view Value) {
  return addArgument(std::make_shared<NameArgument>(Value));
}

Method &Method::addEventTag(const Tag &Value) {
  return addArgument(std::make_shared<EventTagArgument>(Value));
}

Method &Method::addProperty(const Property &Value) {
  return addArgument(std::make_shared<Property>(Value));
}

void Method::setXML(std::string_view Value) { XML = Value; }

const std::string &Method::getXML() const { return XML; }

std::string Method::toString() const {
  std::ostringstream Stream;
  Stream << Name;
  Stream << '(';
  if (XML.empty()) {
    Stream << jdme2x::toString(MethodArguments);
  } else {
    Stream << XML;
  }
  Stream << ')';
  return Stream.str();
}

} // namespace jdme2x
