//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_CLIENT_METHODBUILDER_H
#define JDME2X_CLIENT_METHODBUILDER_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Tag.h"

namespace jdme2x {

struct JDME2X_API MethodBuilder {
  static Method buildStartSession();

  static Method buildEndSession();

  static Method buildStopDaemon(const Tag &eventTag);

  static Method buildStopAllDaemons();

  static Method buildAbortE();

  static Method buildGetErrorInfo(int errorNumber);

  static Method buildGetErrStatusE();

  static Method buildGetXtdErrStatus();

  static Method buildClearAllErrors();

  static Method buildEnumNameSpaces();
};

} // namespace jdme2x

#endif
