//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Response.h"

#include <sstream>

namespace jdme2x {

Response::Response(const Tag &tag, const ResponseValue &value)
    : tag(tag), value(value) {}

Response::Response(const Tag &tag, ResponseValue &&value)
    : tag(tag), value(value) {}

bool Response::operator==(const Response &other) const {
  if (this == &other)
    return true;
  return tag == other.tag && value == other.value;
}

bool Response::operator!=(const Response &other) const {
  return !operator==(other);
}

bool Response::operator<(const Response &other) const {
  return tag < other.tag;
}

std::string Response::toString() const {
  std::ostringstream stream;
  stream << *this;
  return stream.str();
}

bool Response::holdsAcknowledge() const {
  return std::holds_alternative<Acknowledge>(value);
}

bool Response::holdsDone() const { return std::holds_alternative<Done>(value); }

bool Response::holdsData() const { return std::holds_alternative<Data>(value); }

const Data &Response::data() const { return std::get<Data>(value); }

Data &Response::data() { return std::get<Data>(value); }

bool Response::holdsError() const {
  return std::holds_alternative<Error>(value);
}

const Error &Response::error() const { return std::get<Error>(value); }

Error &Response::error() { return std::get<Error>(value); }

bool Response::holdsNumericData() const {
  if (holdsData())
    return std::holds_alternative<NumericalData>(data());
  return false;
}

const NumericalData &Response::numericData() const {
  return std::get<NumericalData>(data());
}

NumericalData &Response::numericData() {
  return std::get<NumericalData>(data());
}

bool Response::holdsPropertyData() const {
  if (holdsData())
    return std::holds_alternative<PropertyData>(data());
  return false;
}

const PropertyData &Response::propertyData() const {
  return std::get<PropertyData>(data());
}

PropertyData &Response::propertyData() {
  return std::get<PropertyData>(data());
}

bool Response::holdsMethod() const {
  if (holdsData())
    return std::holds_alternative<Method>(data());
  return false;
}

const Method &Response::method() const { return std::get<Method>(data()); }

Method &Response::method() { return std::get<Method>(data()); }

bool Response::holdsPropertyList() const {
  if (holdsData())
    return std::holds_alternative<PropertyList>(data());
  return false;
}

const PropertyList &Response::propertyList() const {
  return std::get<PropertyList>(data());
}

PropertyList &Response::propertyList() {
  return std::get<PropertyList>(data());
}

struct ResponseValueVisitor {
  std::ostream &stream;

  ResponseValueVisitor(std::ostream &stream) : stream(stream) {}

  void operator()(const Acknowledge &value) const { stream << value; }

  void operator()(const Done &value) const { stream << value; }

  void operator()(const Data &value) const { stream << value; }

  void operator()(const Error &value) const { stream << value; }
};

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const ResponseValue &instance) {
  std::visit(ResponseValueVisitor(stream), instance);
  return stream;
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Response &instance) {
  stream << instance.tag << ' ' << instance.value << "\r\n";
  return stream;
}

} // namespace jdme2x
