//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Argument.h"

#include <variant>

namespace jdme2x {

namespace types {

struct ArgumentVisitor {
  std::ostream &Stream;

  ArgumentVisitor(std::ostream &Stream) : Stream(Stream) {}

  void operator()(const Number &Value) const { Stream << Value; }

  void operator()(const Property &Value) const { Stream << Value; }

  void operator()(const Name &Value) const { Stream << Value; }

  void operator()(const String &Value) const { Stream << Value; }

  void operator()(const Tag &Value) const { Stream << Value; }
};

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Argument &Instance) {
  std::visit(ArgumentVisitor(Stream), Instance);
  return Stream;
}

} // namespace types

} // namespace jdme2x
