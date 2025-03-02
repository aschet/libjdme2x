//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_METHOD_H
#define JDME2X_METHOD_H

#include "jdme2x/API.h"
#include "jdme2x/Argument.h"
#include "jdme2x/Property.h"
#include "jdme2x/Serializeable.h"
#include "jdme2x/Types/Tag.h"

#include <string>
#include <string_view>

namespace jdme2x {

class JDME2X_API Method : public Serializeable {
public:
  Method();

  Method(std::string_view Value);

  void setName(std::string_view Value);

  const std::string &getName() const;

  const Arguments &getArguments() const;

  Method &addArgument(std::shared_ptr<Argument> Value);

  Method &addNumber(const types::Number& Value);

  Method &addString(std::string_view Value);

  Method &addName(std::string_view Value);

  Method &addEventTag(const types::Tag& Value);

  Method &addProperty(const Property &Value);

  void setXML(std::string_view Value);

  const std::string &getXML() const;

  std::string toString() const override;

private:
  std::string Name;

  Arguments MethodArguments;

  std::string XML;
};

} // namespace jdme2x

#endif
