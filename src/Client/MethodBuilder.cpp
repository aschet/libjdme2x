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

Method MethodBuilder::buildSetProp(const std::vector<Property> &properties) {
  Method method(SetPropName);
  for (const auto &property : properties) {
    method.with(property);
  }
  return method;
}

Method MethodBuilder::buildGetProp(const std::vector<Name> &properties) {
  Method method(GetPropName);
  for (const auto &propertyName : properties) {
    method.with(Property(propertyName));
  }
  return method;
}

Method MethodBuilder::buildEnumProp(const Name &reference) {
  return Method(EnumPropName).with(Property(reference));
}

Method MethodBuilder::buildEnumAllProp(const Name &reference) {
  return Method(EnumAllPropName).with(Property(reference));
}

Method MethodBuilder::buildGetDMEVersion() { return Method(GetDMEVersionName); }

Method MethodBuilder::buildGetSupportedCommands() {
  return Method(GetSupportedCommandsName);
}

Method MethodBuilder::buildGetSupportedArguments() {
  return Method(GetSupportedArgumentsName);
}

Method MethodBuilder::buildGetMachineClass() {
  return Method(GetMachineClassName);
}

Method MethodBuilder::buildHome() { return Method(HomeName); }

Method MethodBuilder::buildIsHomed() { return Method(IsHomedName); }

} // namespace jdme2x
