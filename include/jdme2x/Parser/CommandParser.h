//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_PARSER_COMMANDPARSER_H
#define JDME2X_PARSER_COMMANDPARSER_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Command.h"

#include <memory>
#include <string_view>
#include <utility>

namespace jdme2x {
namespace parser {

class JDME2X_API CommandParser {
public:
  CommandParser();

  ~CommandParser();

  CommandParser(const CommandParser &) = delete;

  CommandParser(CommandParser &&);

  CommandParser &operator=(const CommandParser &) = delete;

  CommandParser &operator=(CommandParser &&);

  std::pair<bool, types::Command> parse(std::string_view text);

private:
  struct Private;

  std::unique_ptr<Private> impl;
};

} // namespace parser

} // namespace jdme2x

#endif
