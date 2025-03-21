//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_PARSER_RESPONSEPARSER_H
#define JDME2X_PARSER_RESPONSEPARSER_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Response.h"

#include <memory>
#include <string_view>
#include <utility>

namespace jdme2x {

class JDME2X_API ResponseParser {
public:
  ResponseParser();

  ~ResponseParser();

  ResponseParser(const ResponseParser &) = delete;

  ResponseParser(ResponseParser &&);

  ResponseParser &operator=(const ResponseParser &) = delete;

  ResponseParser &operator=(ResponseParser &&);

  std::pair<bool, Response> parse(std::string_view text);

private:
  struct Private;

  std::unique_ptr<Private> impl;
};

} // namespace jdme2x

#endif
