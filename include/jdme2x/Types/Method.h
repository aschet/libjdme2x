//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_METHOD_H
#define JDME2X_TYPES_METHOD_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Argument.h"

#include <ostream>

namespace jdme2x {

struct JDME2X_API Method {
  Method() = default;

  Method(const Method &) = default;

  Method(Method &&) = default;

  Method(const Name &name);

  Method(Name &&name);

  Method &operator=(const Method &) = default;

  Method &operator=(Method &&) = default;

  bool operator==(const Method &other) const;

  bool operator!=(const Method &other) const;

  bool operator<(const Method &other) const;

  bool isPrioritized() const;

  Method &with(const Argument &arg);

  Method &with(Argument &&arg);

  Method &withXML(const std::string &arg);

  Method &withXML(std::string &&arg);

  Name name;

  ArgumentList args;

  std::string xml;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Method &instance);

} // namespace jdme2x

#endif
