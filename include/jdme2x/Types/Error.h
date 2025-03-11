//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_ERROR_H
#define JDME2X_TYPES_ERROR_H

#include "jdme2x/API.h"
#include "jdme2x/Types/String.h"

#include <ostream>

namespace jdme2x {
namespace types {

enum class ErrorNumber {
  Undefined = -1,
  BufferFull = 0,
  IllegalTag = 1,
  NoSpaceAtPos6 = 2,
  Reserved_3 = 3,
  Reserved_4 = 4,
  Reserved_5 = 5,
  TransactionAborted = 6,
  IllegalCharacter = 7,
  ProtocolError = 8,
  EmergencyStop = 500,
  UnsupportedCommand = 501,
  IncorrectArguments = 502,
  ControllerCommunicationsFailure = 503,
  ArgumentOutOfRange = 504,
  ArgumentNotRecognized = 505,
  ArgumentNotSupported = 506,
  IllegalCommand = 507,
  BadContext = 508,
  BadArgument = 509,
  BadProperty = 510,
  ErrorProcessingMethod = 511,
  NoDaemonsAreActive = 512,
  DaemonDoesNotExist = 513,
  UseClearAllErrorsToContinue = 514,
  DaemonAlreadyExists = 515,
  MachineInErrorState = 1000,
  IllegalTouch = 1001,
  AxisDoesNotExist = 1002,
  NoTouch = 1003,
  NumberOfAnglesNotSupported = 1004,
  ErrorDuringHoming = 1005,
  SurfaceNotFound = 1006,
  ThetaOutOfRange = 1007,
  TargetPositionOutOfMachineVolume = 1008,
  AirPressureOutOfRange = 1009,
  VectorHasNoNorm = 1010,
  UnableToMove = 1011,
  BadLockCombinations = 1012,
  CoordinateSystemNotFound = 1013,
  FailedToSetValueDueToCorrection = 1014,
  FailedToReseatHead = 1500,
  ProbeNotArmed = 1501,
  ToolNotFound = 1502,
  ToolNotDefined = 1503,
  CollectionNotFound = 1504,
  ToolNotAlignable = 1505,
  ToolPropertyNotApplicable = 1506,
  ToolNotAlignableToGivenOrientation = 1507,
  ToolNotCalibrated = 2000,
  HeadErrorExcessiveForce = 2001,
  TypeOfProbeDoesNotAllowThisOperation = 2002,
  RawDataOfAcquisitionNotAvailable = 2003,
  NoSharedMemorySpaceAvailable = 2004,
  FileNotFound = 2005,
  MachineLimitEncountered = 2500,
  AxisNotActive = 2501,
  AxisPositionError = 2502,
  ScaleReadHeadFailure = 2503,
  Collision = 2504,
  SpecifiedAngleOutOfRange = 2505,
  PartNotAligned = 2506,
  WrongDataFormat = 5000,
  PortNotAvailable = 5001,
};

enum class ErrorSeverity {
  Undefined = -1,
  Info = 0,
  Warning = 1,
  Error = 2,
  CriticalError = 3,
  FatalError = 9
};

enum class ErrorGroup {
  Undefined = -1,
  DefinedByIPPDME,
  ReservedForOSIS,
  Reserved,
  DefineableFromServer,
  DefineableFromClient
};

struct ErrorDefinition {
  int number;
  ErrorSeverity severity;
  const char *information;
};

constexpr char ErrorID = '!';

constexpr const char *ErrorName = "Error";

constexpr int MinError = 0;

constexpr int MaxError = 9999;

struct JDME2X_API Error {
  Error();

  Error(const ErrorDefinition &definition, const String &cause);

  Error(const ErrorDefinition &definition, String &&cause);

  Error(ErrorSeverity Severity, int number, const String &cause,
        const String &information);

  Error(const Error &) = default;

  Error(Error &&) = default;

  Error &operator=(const Error &) = default;

  Error &operator=(Error &&) = default;

  bool operator==(const Error &other) const;

  bool operator!=(const Error &other) const;

  bool operator<(const Error &other) const;

  bool operator==(const ErrorNumber &other) const;

  bool operator!=(const ErrorNumber &other) const;

  ErrorGroup getGroup() const;

  bool requiresClearAllErrors() const;

  ErrorSeverity severity;

  int number;

  String cause;

  String information;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Error &instance);

} // namespace types
} // namespace jdme2x

#endif
