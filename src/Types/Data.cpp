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

namespace jdme2x {

namespace types {

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const PropertyData &Instance) {
  Stream << Instance.first << ", " << Instance.second;
  return Stream;
}

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const PropertyList &Instance) {
  if (!Instance.empty()) {
    auto End = Instance.end() - 1;
    for (auto It = Instance.begin(); It != End; ++It) {
      Stream << *It << ", ";
    }
    Stream << Instance.back();
  }
  return Stream;
}

struct DataVisitor {
  std::ostream &Stream;

  DataVisitor(std::ostream &Stream) : Stream(Stream) {}

  void operator()(const NumericalData &Value) const { Stream << Value; }

  void operator()(const PropertyData &Value) const { Stream << Value; }

  void operator()(const PropertyList &Value) const { Stream << Value; }

  void operator()(const Method &Value) const { Stream << Value; }
};

std::ostream &operator<<(std::ostream &Stream, const Data &Instance) {
  std::visit(DataVisitor(Stream), Instance);
  return Stream;
}

} // namespace types

} // namespace jdme2x
