//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_ARGUMENT_H
#define JDME2X_ARGUMENT_H

#include "jdme2x/API.h"
#include "jdme2x/Serializeable.h"
#include "jdme2x/Types/Number.h"
#include "jdme2x/Types/Tag.h"

#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace jdme2x {

class JDME2X_API Argument : public Serializeable {};

class JDME2X_API NumberArgument : public Argument {
public:
  explicit NumberArgument(const types::Number &Value);

  types::Number getValue() const;

  std::string toString() const override;

private:
  types::Number Value;
};

class JDME2X_API StringArgument : public Argument {
public:
  explicit StringArgument(std::string_view Value);

  const std::string &getValue() const;

  std::string toString() const override;

private:
  std::string Value;
};

class JDME2X_API NameArgument : public Argument {
public:
  explicit NameArgument(std::string_view Value);

  const std::string &getValue() const;

  std::string toString() const override;

private:
  std::string Value;
};

class JDME2X_API EventTagArgument : public Argument {
public:
  explicit EventTagArgument(const types::Tag &Value);

  const types::Tag &getValue() const;

  std::string toString() const override;

private:
  types::Tag Value;
};

typedef std::vector<std::shared_ptr<Argument>> Arguments;

JDME2X_API std::string toString(const Arguments &Args);

} // namespace jdme2x

#endif
