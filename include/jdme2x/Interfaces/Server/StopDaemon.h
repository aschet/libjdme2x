//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_INTERFACCES_SERVER_STOPDAEMON_H
#define JDME2X_INTERFACCES_SERVER_STOPDAEMON_H

#include "jdme2x/API.h"
#include "jdme2x/Interfaces/Signature.h"
#include "jdme2x/Types/Tag.h"

namespace jdme2x {
namespace interfaces {

constexpr const char *StopDaemonName = "StopDaemon";

struct JDME2X_API StopDaemonParameters : public Parameters {
  types::ArgumentList encode() const override;

  std::optional<types::Error> decode(const types::ArgumentList &args) override;

  types::Tag eventTag;
};

using StopDaemonReturnData = VoidReturnData;

} // namespace interfaces
} // namespace jdme2x

#endif
