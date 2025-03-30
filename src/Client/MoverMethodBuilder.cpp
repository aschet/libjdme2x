//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/MoverMethodBuilder.h"

#include "jdme2x/Names/MethodNames.h"

namespace jdme2x {

Method MoverMethodBuilder::buildEnableUser() { return Method(EnableUserName); }

Method MoverMethodBuilder::buildDisableUser() {
  return Method(DisableUserName);
}

Method MoverMethodBuilder::buildIsUserEnabled() {
  return Method(IsUserEnabledName);
}

Method MoverMethodBuilder::buildEnumerateMoverAxes() {
  return Method(EnumerateMoverAxesName);
}

Method MoverMethodBuilder::buildUpdateScaleTemperatures() {
  return Method(UpdateScaleTemperaturesName);
}

} // namespace jdme2x
