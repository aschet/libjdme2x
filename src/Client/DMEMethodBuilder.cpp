//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/DMEMethodBuilder.h"

#include "jdme2x/Names/MethodNames.h"

namespace jdme2x {

Method DMEMethodBuilder::buildGetDMEVersion() {
  return Method(GetDMEVersionName);
}

Method DMEMethodBuilder::buildGetSupportedCommands() {
  return Method(GetSupportedCommandsName);
}

Method DMEMethodBuilder::buildGetSupportedArguments() {
  return Method(GetSupportedArgumentsName);
}

Method DMEMethodBuilder::buildGetMachineClass() {
  return Method(GetMachineClassName);
}

Method DMEMethodBuilder::buildHome() { return Method(HomeName); }

Method DMEMethodBuilder::buildIsHomed() { return Method(IsHomedName); }

} // namespace jdme2x
