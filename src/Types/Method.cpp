//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Method.h"

#include <utility>

namespace jdme2x {

namespace types {

Method::Method(const Name &MethodName) : MethodName(MethodName) {}

void Method::setName(const Name &Value) { MethodName = Value; }

const Name &Method::getName() const { return MethodName; }

const MethodArgumentList &Method::getArguments() const {
  return MethodArguments;
}

Method &Method::addArgument(const Argument &Value) {
  XML.clear();
  MethodArguments.emplace_back(Value);
  return *this;
}

Method &Method::addArgument(Argument &&Value) {
  XML.clear();
  MethodArguments.emplace_back(std::move(Value));
  return *this;
}

void Method::clearArguments() { MethodArguments.clear(); }

void Method::setXML(std::string_view Value) { XML = Value; }

const std::string &Method::getXML() const { return XML; }

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const MethodArgumentList &Instance) {
  if (!Instance.empty()) {
    auto End = Instance.end() - 1;
    for (auto It = Instance.begin(); It != End; ++It) {
      Stream << *It << ", ";
    }
    Stream << Instance.back();
  }
  return Stream;
}

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Method &Instance) {
  Stream << Instance.MethodName << '(';
  if (Instance.XML.empty())
    Stream << Instance.MethodArguments;
  else
    Stream << Instance.XML;
  Stream << ')';
  return Stream;
}

} // namespace types

} // namespace jdme2x
