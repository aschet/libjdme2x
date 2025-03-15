//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_INTERFACCES_SERVER_ENDSESSION_H
#define JDME2X_INTERFACCES_SERVER_ENDSESSION_H

#include "jdme2x/Interfaces/Signature.h"

namespace jdme2x {
namespace interfaces {

constexpr const char *EndSessionName = "EndSession";

struct EndSessionParameters : public Parameters {
  types::ArgumentList encode() const override;

  std::optional<types::Error> decode(const types::ArgumentList &args) override;
};

struct EndSessionReturnData : public ReturnData {
  DataList encode() const override;

  void decode(const DataList &data) override;
};

} // namespace interfaces
} // namespace jdme2x

#endif
