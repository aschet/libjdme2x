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
  ArgumentVisitor(std::ostream &stream) : stream(stream) {}

  void operator()(const std::monostate &) const {}

  void operator()(const Number &value) const { stream << value; }

  void operator()(const Property &value) const { stream << value; }

  void operator()(const Name &value) const { stream << value; }

  void operator()(const String &value) const { stream << value; }

  void operator()(const Tag &value) const { stream << value; }

  std::ostream &stream;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Argument &instance) {
  std::visit(ArgumentVisitor(stream), instance);
  return stream;
}

} // namespace types
} // namespace jdme2x
