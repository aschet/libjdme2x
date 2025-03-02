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

namespace types {

typedef std::vector<Argument> MethodArgumentList;

class JDME2X_API Method {
  friend std::ostream &operator<<(std::ostream &, const Method &);

public:
  Method() = default;

  Method(const Method &) = default;

  Method(Method &&) = default;

  Method(const Name &MethodName);

  void setName(const Name &Value);

  const Name &getName() const;

  Method &addArgument(const Argument &Value);

  Method &addArgument(Argument &&Value);

  void clearArguments();

  const MethodArgumentList &getArguments() const;

  void setXML(std::string_view Value);

  const std::string &getXML() const;

  Method &operator=(const Method &) = default;

  Method &operator=(Method &&) = default;

private:
  Name MethodName;

  MethodArgumentList MethodArguments;

  std::string XML;
};

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const MethodArgumentList &Instance);

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Method &Instance);

} // namespace types

} // namespace jdme2x

#endif
