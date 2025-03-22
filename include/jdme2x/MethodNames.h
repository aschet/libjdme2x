//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_METHODNAMES_H
#define JDME2X_METHODNAMES_H

namespace jdme2x {
// Server
constexpr const char *StartSessionName = "StartSession";

constexpr const char *EndSessionName = "EndSession";

constexpr const char *StopDaemonName = "StopDaemon";

constexpr const char *StopAllDaemonsName = "StopAllDaemons";

constexpr const char *AbortEName = "AbortE";

constexpr const char *GetErrorInfoName = "GetErrorInfo";

constexpr const char *GetErrStatusEName = "GetErrStatusE";

constexpr const char *GetXtdErrStatusName = "GetXtdErrStatus";

constexpr const char *ClearAllErrorsName = "ClearAllErrors";

constexpr const char *EnumNameSpacesName = "EnumNameSpaces";

constexpr const char *SetPropName = "SetProp";

constexpr const char *GetPropName = "GetProp";

constexpr const char *EnumPropName = "EnumProp";

constexpr const char *EnumAllPropName = "EnumAllProp";

// DME

constexpr const char *GetDMEVersionName = "GetDMEVersion";

constexpr const char *GetSupportedCommandsName = "GetSupportedCommands";

constexpr const char *GetSupportedArgumentsName = "GetSupportedArguments";

constexpr const char *GetMachineClassName = "GetMachineClass";

constexpr const char *HomeName = "Home";

constexpr const char *IsHomedName = "IsHomed";

// CartCMM

} // namespace jdme2x

#endif
