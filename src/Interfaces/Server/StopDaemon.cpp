//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Interfaces/Server/StopDaemon.h"

#include <sstream>

namespace jdme2x {
namespace interfaces {

types::ArgumentList StopDaemonParameters::encode() const {
  std::stringstream stream;
  stream << eventTag;
  return {types::Name(stream.str())};
}

std::optional<types::Error>
StopDaemonParameters::decode(const types::ArgumentList &) {
  return std::nullopt;
}

} // namespace interfaces
} // namespace jdme2x
