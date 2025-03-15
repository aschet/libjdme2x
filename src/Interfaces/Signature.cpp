//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Interfaces/Signature.h"

namespace jdme2x {
namespace interfaces {

types::ArgumentList VoidParameters::encode() const {
  return types::ArgumentList();
}

std::optional<types::Error>
VoidParameters::decode(const types::ArgumentList &) {
  return std::nullopt;
}

DataList VoidReturnData::encode() const { return DataList(); }

void VoidReturnData::decode(const DataList &) {}

} // namespace interfaces
} // namespace jdme2x
