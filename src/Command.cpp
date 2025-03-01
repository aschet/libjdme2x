//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Command.h"

#include <iomanip>
#include <sstream>

namespace jdme2x {

Command::Command() = default;

Command::Command(const Tag &CommandTag, const Method &CommandMethod)
    : CommandTag(CommandTag), CommandMethod(CommandMethod) {}

void Command::setTag(const Tag &Value) { CommandTag = Value; }

const Tag &Command::getTag() const { return CommandTag; }

void Command::setMethod(const Method &Value) { CommandMethod = Value; }

const Method &Command::getMethod() const { return CommandMethod; }

Method &Command::getMethod() { return CommandMethod; }

std::string Command::toString() const {
  std::ostringstream Stream;
  Stream << std::noskipws;
  Stream << CommandTag.toString();
  Stream << ' ';
  Stream << CommandMethod.toString();
  Stream << "\r\n";
  return Stream.str();
}

} // namespace jdme2x
