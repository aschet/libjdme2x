//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSEor copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/MethodBuilder.h"

#include "jdme2x/MethodNames.h"

#include <iomanip>
#include <sstream>

namespace jdme2x {

Method MethodBuilder::buildStartSession() { return Method(StartSessionName); }

Method MethodBuilder::buildEndSession() { return Method(EndSessionName); }

Method MethodBuilder::buildStopDaemon(const Tag &eventTag) {
  std::ostringstream stream;
  stream << eventTag;
  return Method(StopDaemonName).with(Name(stream.str()));
}

Method MethodBuilder::buildStopAllDaemons() {
  return Method(StopAllDaemonsName);
}

Method MethodBuilder::buildAbortE() { return Method(AbortEName); }

Method MethodBuilder::buildGetErrorInfo(int errorNumber) {
  std::ostringstream stream;
  stream << std::setw(4) << std::setfill('0') << errorNumber;
  return Method(GetErrorInfoName).with(Name(stream.str()));
}

Method MethodBuilder::buildGetErrStatusE() { return Method(GetErrStatusEName); }

Method MethodBuilder::buildGetXtdErrStatus() {
  return Method(GetXtdErrStatusName);
}

Method MethodBuilder::buildClearAllErrors() {
  return Method(ClearAllErrorsName);
}

Method MethodBuilder::buildEnumNameSpaces() {
  return Method(EnumNameSpacesName);
}

} // namespace jdme2x
