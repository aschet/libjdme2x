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

namespace jdme2x {

Method::Method(const Name &name) : name(name) {}

Method::Method(Name &&name) : name(name) {}

bool Method::operator==(const Method &other) const {
  if (this == &other)
    return true;
  return name == other.name && xml == other.xml && args == other.args;
}

bool Method::operator!=(const Method &other) const {
  return !operator==(other);
}

bool Method::operator<(const Method &other) const { return name < other.name; }

bool Method::isPrioritized() const {
  if (name.value.length() > 0 && name.value.back() == 'E')
    return true;
  return false;
}

TagType Method::getTagType() const {
  if (isPrioritized())
    return TagType::Event;
  else
    return TagType::Command;
}

Method &Method::with(const Argument &arg) {
  args.emplace_back(arg);
  xml.clear();
  return *this;
}

Method &Method::with(Argument &&arg) {
  args.emplace_back(arg);
  xml.clear();
  return *this;
}

Method &Method::withXML(const std::string &arg) {
  args.clear();
  xml = arg;
  return *this;
}

Method &Method::withXML(std::string &&arg) {
  args.clear();
  xml = arg;
  return *this;
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Method &instance) {
  stream << instance.name << '(';
  if (instance.xml.empty())
    stream << instance.args;
  else
    stream << instance.xml;
  stream << ')';
  return stream;
}

} // namespace jdme2x
