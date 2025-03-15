//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Interfaces/Server/StartSession.h"

namespace jdme2x {
namespace interfaces {

types::ArgumentList StartSessionParameters::encode() const {
  return types::ArgumentList();
}

std::optional<types::Error>
StartSessionParameters::decode(const types::ArgumentList &args) {
  return std::nullopt;
}

DataList StartSessionReturnData::encode() const { return DataList(); }

void StartSessionReturnData::decode(const DataList &data) {}

} // namespace interfaces
} // namespace jdme2x
