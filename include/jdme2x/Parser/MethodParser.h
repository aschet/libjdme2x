//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_PARSER_METHODPARSER_H
#define JDME2X_PARSER_METHODPARSER_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Method.h"

#include <memory>
#include <string_view>
#include <utility>

namespace jdme2x {
namespace parser {

class JDME2X_API MethodParser {
public:
  MethodParser();

  ~MethodParser();

  MethodParser(const MethodParser &) = delete;

  MethodParser(MethodParser &&);

  MethodParser &operator=(const MethodParser &) = delete;

  MethodParser &operator=(MethodParser &&);

  std::pair<bool, types::Method> parse(std::string_view text);

private:
  struct Private;

  std::unique_ptr<Private> impl;
};

} // namespace parser

} // namespace jdme2x

#endif
