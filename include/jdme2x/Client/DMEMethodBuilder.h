//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_CLIENT_DMEMETHODBUILDER_H
#define JDME2X_CLIENT_DMEMETHODBUILDER_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Method.h"

namespace jdme2x {

struct JDME2X_API DMEMethodBuilder {
  DMEMethodBuilder() = delete;

  static Method buildGetDMEVersion();

  static Method buildGetSupportedCommands();

  static Method buildGetSupportedArguments();

  static Method buildGetMachineClass();

  static Method buildHome();

  static Method buildIsHomed();
};

} // namespace jdme2x

#endif
