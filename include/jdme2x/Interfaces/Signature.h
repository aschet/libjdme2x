//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_INTERFACCES_SIGNATURE_H
#define JDME2X_INTERFACCES_SIGNATURE_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Argument.h"
#include "jdme2x/Types/Data.h"
#include "jdme2x/Types/Error.h"

#include <optional>
#include <vector>

namespace jdme2x {
namespace interfaces {

using DataList = std::vector<types::Data>;

struct JDME2X_API Parameters {
  virtual ~Parameters() = default;

  virtual types::ArgumentList encode() const = 0;

  virtual std::optional<types::Error>
  decode(const types::ArgumentList &args) = 0;
};

struct JDME2X_API VoidParameters : public Parameters {
  types::ArgumentList encode() const override;

  std::optional<types::Error> decode(const types::ArgumentList &args) override;
};

struct JDME2X_API ReturnData {
  virtual ~ReturnData() = default;

  virtual DataList encode() const = 0;

  virtual void decode(const DataList &data) = 0;
};

struct JDME2X_API VoidReturnData : public ReturnData {
  DataList encode() const override;

  void decode(const DataList &data) override;
};

} // namespace interfaces
} // namespace jdme2x

#endif
