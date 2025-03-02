//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Command.h"

#include <utility>

namespace jdme2x {

namespace types {

Command::Command(const Tag &CommandTag, const Method &CommandMethod)
    : CommandTag(CommandTag), CommandMethod(CommandMethod) {}

Command::Command(const Tag &CommandTag, Method &&CommandMethod)
    : CommandTag(CommandTag), CommandMethod(std::move(CommandMethod)) {}

void Command::setTag(const types::Tag &Value) { CommandTag = Value; }

const Tag &Command::getTag() const { return CommandTag; }

void Command::setMethod(const types::Method &Value) { CommandMethod = Value; }

void Command::setMethod(Method &&Value) { CommandMethod = std::move(Value); }

const Method &Command::getMethod() const { return CommandMethod; }

Method &Command::getMethod() { return CommandMethod; }

JDME2X_API std::ostream &operator<<(std::ostream &Stream,
                                    const Command &Instance) {
  Stream << Instance.CommandTag << ' ' << Instance.CommandMethod << "\r\n";
  return Stream;
}

} // namespace types

} // namespace jdme2x
