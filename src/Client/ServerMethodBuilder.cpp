//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/ServerMethodBuilder.h"

#include "jdme2x/Names/MethodNames.h"

#include <iomanip>
#include <sstream>

namespace jdme2x {

Method ServerMethodBuilder::buildStartSession() {
  return Method(StartSessionName);
}

Method ServerMethodBuilder::buildEndSession() { return Method(EndSessionName); }

Method ServerMethodBuilder::buildStopDaemon(const Tag &eventTag) {
  std::ostringstream stream;
  stream << eventTag;
  return Method(StopDaemonName).with(Name(stream.str()));
}

Method ServerMethodBuilder::buildStopAllDaemons() {
  return Method(StopAllDaemonsName);
}

Method ServerMethodBuilder::buildAbortE() { return Method(AbortEName); }

Method ServerMethodBuilder::buildGetErrorInfo(int errorNumber) {
  std::ostringstream stream;
  stream << std::setw(4) << std::setfill('0') << errorNumber;
  return Method(GetErrorInfoName).with(Name(stream.str()));
}

Method ServerMethodBuilder::buildGetErrStatusE() {
  return Method(GetErrStatusEName);
}

Method ServerMethodBuilder::buildGetXtdErrStatus() {
  return Method(GetXtdErrStatusName);
}

Method ServerMethodBuilder::buildClearAllErrors() {
  return Method(ClearAllErrorsName);
}

Method ServerMethodBuilder::buildEnumNameSpaces() {
  return Method(EnumNameSpacesName);
}

Method
ServerMethodBuilder::buildSetProp(const std::vector<Property> &properties) {
  Method method(SetPropName);
  for (const auto &property : properties) {
    method.with(property);
  }
  return method;
}

Method ServerMethodBuilder::buildGetProp(const std::vector<Name> &properties) {
  Method method(GetPropName);
  for (const auto &propertyName : properties) {
    method.with(Property(propertyName));
  }
  return method;
}

Method ServerMethodBuilder::buildEnumProp(const Name &reference) {
  return Method(EnumPropName).with(Property(reference));
}

Method ServerMethodBuilder::buildEnumAllProp(const Name &reference) {
  return Method(EnumAllPropName).with(Property(reference));
}

} // namespace jdme2x
