//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Data.h"

#include "StreamUtils.h"

namespace jdme2x {
namespace types {

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const PropertyData &instance) {
  stream << instance.first << ", " << instance.second;
  return stream;
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const PropertyList &instance) {
  return writeList(stream, instance);
}

struct DataVisitor {
  std::ostream &stream;

  DataVisitor(std::ostream &stream) : stream(stream) {}

  void operator()(const std::monostate &) const {}

  void operator()(const NumericalData &value) const { stream << value; }

  void operator()(const PropertyData &value) const { stream << value; }

  void operator()(const PropertyList &value) const { stream << value; }

  void operator()(const Method &value) const { stream << value; }
};

std::ostream &operator<<(std::ostream &stream, const Data &instance) {
  stream << DataID << ' ';
  std::visit(DataVisitor(stream), instance);
  return stream;
}

} // namespace types
} // namespace jdme2x
