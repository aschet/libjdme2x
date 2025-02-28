//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_ERRORS_H
#define JDME2X_TYPES_ERRORS_H

#include "jdme2x/Types/Error.h"

namespace jdme2x {
namespace types {
namespace errors {

constexpr ErrorDefinition BufferFull = {
    static_cast<int>(ErrorNumber::BufferFull), ErrorSeverity::Info,
    "Buffer full"};

constexpr ErrorDefinition IllegalTag = {
    static_cast<int>(ErrorNumber::IllegalTag), ErrorSeverity::Error,
    "Illegal tag"};

constexpr ErrorDefinition NoSpaceAtPos6 = {
    static_cast<int>(ErrorNumber::NoSpaceAtPos6), ErrorSeverity::Error,
    "No space at pos. 6"};

constexpr ErrorDefinition Reserved_3 = {
    static_cast<int>(ErrorNumber::Reserved_3), ErrorSeverity::Error,
    "Reserved"};

constexpr ErrorDefinition Reserved_4{static_cast<int>(ErrorNumber::Reserved_4),
                                     ErrorSeverity::Error, "Reserved"};

constexpr ErrorDefinition Reserved_5{static_cast<int>(ErrorNumber::Reserved_5),
                                     ErrorSeverity::Error, "Reserved"};

constexpr ErrorDefinition TransactionAborted{
    static_cast<int>(ErrorNumber::TransactionAborted), ErrorSeverity::Error,
    "Transaction aborted (Use ClearAllErrors To Continue)"};

constexpr ErrorDefinition IllegalCharacter = {
    static_cast<int>(ErrorNumber::IllegalCharacter),
    ErrorSeverity::CriticalError, "Illegal character"};

constexpr ErrorDefinition ProtocolError = {
    static_cast<int>(ErrorNumber::ProtocolError), ErrorSeverity::CriticalError,
    "Protocol error"};

constexpr ErrorDefinition EmergencyStop = {
    static_cast<int>(ErrorNumber::EmergencyStop), ErrorSeverity::CriticalError,
    "Emergency stop"};

constexpr ErrorDefinition UnsupportedCommand = {
    static_cast<int>(ErrorNumber::UnsupportedCommand),
    ErrorSeverity::CriticalError, "Unsupported command"};

constexpr ErrorDefinition IncorrectArguments = {
    static_cast<int>(ErrorNumber::IncorrectArguments),
    ErrorSeverity::CriticalError, "Incorrect arguments"};

constexpr ErrorDefinition ControllerCommunicationsFailure = {
    static_cast<int>(ErrorNumber::ControllerCommunicationsFailure),
    ErrorSeverity::FatalError, "Controller communications failure"};

constexpr ErrorDefinition ArgumentOutOfRange = {
    static_cast<int>(ErrorNumber::ArgumentOutOfRange), ErrorSeverity::Warning,
    "Argument out of range"};

constexpr ErrorDefinition ArgumentNotRecognized = {
    static_cast<int>(ErrorNumber::ArgumentNotRecognized),
    ErrorSeverity::CriticalError, "Argument not recognized"};

constexpr ErrorDefinition ArgumentNotSupported = {
    static_cast<int>(ErrorNumber::ArgumentNotSupported),
    ErrorSeverity::CriticalError, "Argument not supported"};

constexpr ErrorDefinition IllegalCommand = {
    static_cast<int>(ErrorNumber::IllegalCommand), ErrorSeverity::CriticalError,
    "Illegal command"};

constexpr ErrorDefinition BadContext = {
    static_cast<int>(ErrorNumber::BadContext), ErrorSeverity::CriticalError,
    "Bad context"};

constexpr ErrorDefinition BadArgument = {
    static_cast<int>(ErrorNumber::BadArgument), ErrorSeverity::CriticalError,
    "Bad argument"};

constexpr ErrorDefinition BadProperty = {
    static_cast<int>(ErrorNumber::BadProperty), ErrorSeverity::CriticalError,
    "Bad property"};

constexpr ErrorDefinition ErrorProcessingMethod = {
    static_cast<int>(ErrorNumber::ErrorProcessingMethod),
    ErrorSeverity::CriticalError, "Error processing method"};

constexpr ErrorDefinition NoDaemonsAreActive = {
    static_cast<int>(ErrorNumber::NoDaemonsAreActive), ErrorSeverity::Warning,
    "No daemons are active"};

constexpr ErrorDefinition DaemonDoesNotExist = {
    static_cast<int>(ErrorNumber::DaemonDoesNotExist), ErrorSeverity::Error,
    "Daemon does not exist"};

constexpr ErrorDefinition UseClearAllErrorsToContinue = {
    static_cast<int>(ErrorNumber::UseClearAllErrorsToContinue),
    ErrorSeverity::Error, "Use ClearAllErrors to continue"};

constexpr ErrorDefinition DaemonAlreadyExists = {
    static_cast<int>(ErrorNumber::DaemonAlreadyExists), ErrorSeverity::Error,
    "Daemon already exists"};

constexpr ErrorDefinition MachineInErrorState = {
    static_cast<int>(ErrorNumber::MachineInErrorState),
    ErrorSeverity::CriticalError, "Machine in error state"};

constexpr ErrorDefinition IllegalTouch = {
    static_cast<int>(ErrorNumber::IllegalTouch), ErrorSeverity::Error,
    "Illegal touch"};

constexpr ErrorDefinition AxisDoesNotExist = {
    static_cast<int>(ErrorNumber::AxisDoesNotExist), ErrorSeverity::FatalError,
    "Axis does not exist"};

constexpr ErrorDefinition NoTouch = {static_cast<int>(ErrorNumber::NoTouch),
                                     ErrorSeverity::Error, "No touch"};

constexpr ErrorDefinition NumberOfAnglesNotSupported = {
    static_cast<int>(ErrorNumber::NumberOfAnglesNotSupported),
    ErrorSeverity::FatalError,
    "Number of angles not supported on current device"};

constexpr ErrorDefinition ErrorDuringHoming = {
    static_cast<int>(ErrorNumber::ErrorDuringHoming),
    ErrorSeverity::CriticalError, "Error during home"};

constexpr ErrorDefinition SurfaceNotFound = {
    static_cast<int>(ErrorNumber::SurfaceNotFound), ErrorSeverity::Error,
    "Surface not found"};

constexpr ErrorDefinition ThetaOutOfRange = {
    static_cast<int>(ErrorNumber::ThetaOutOfRange),
    ErrorSeverity::CriticalError, "Theta out of range"};

constexpr ErrorDefinition TargetPositionOutOfMachineVolume = {
    static_cast<int>(ErrorNumber::TargetPositionOutOfMachineVolume),
    ErrorSeverity::CriticalError, "Target position out of machine volume"};

constexpr ErrorDefinition AirPressureOutOfRange = {
    static_cast<int>(ErrorNumber::AirPressureOutOfRange),
    ErrorSeverity::CriticalError, "Air pressure out of range"};

constexpr ErrorDefinition VectorHasNoNorm = {
    static_cast<int>(ErrorNumber::VectorHasNoNorm), ErrorSeverity::Error,
    "Vector has no norm"};

constexpr ErrorDefinition UnableToMove = {
    static_cast<int>(ErrorNumber::UnableToMove), ErrorSeverity::Error,
    "Unable to move"};

constexpr ErrorDefinition BadLockCombinations = {
    static_cast<int>(ErrorNumber::BadLockCombinations), ErrorSeverity::Error,
    "Bad lock combinations"};

constexpr ErrorDefinition CoordinateSystemNotFound = {
    static_cast<int>(ErrorNumber::CoordinateSystemNotFound),
    ErrorSeverity::CriticalError, "Coordinate system not found"};

constexpr ErrorDefinition FailedToSetValueDueToCorrection = {
    static_cast<int>(ErrorNumber::FailedToSetValueDueToCorrection),
    ErrorSeverity::Error,
    "Failed to set value due to active internal correction"};

constexpr ErrorDefinition FailedToReseatHead = {
    static_cast<int>(ErrorNumber::FailedToReseatHead),
    ErrorSeverity::CriticalError, "Failed to re-seat head"};

constexpr ErrorDefinition ProbeNotArmed = {
    static_cast<int>(ErrorNumber::ProbeNotArmed), ErrorSeverity::CriticalError,
    "Probe not armed"};

constexpr ErrorDefinition ToolNotFound = {
    static_cast<int>(ErrorNumber::ToolNotFound), ErrorSeverity::CriticalError,
    "Tool not found"};

constexpr ErrorDefinition ToolNotDefined = {
    static_cast<int>(ErrorNumber::ToolNotDefined), ErrorSeverity::CriticalError,
    "Tool not defined"};

constexpr ErrorDefinition CollectionNotFound = {
    static_cast<int>(ErrorNumber::CollectionNotFound),
    ErrorSeverity::CriticalError, "Collection not found"};

constexpr ErrorDefinition ToolNotAlignable = {
    static_cast<int>(ErrorNumber::ToolNotAlignable), ErrorSeverity::Error,
    "Tool not alignable"};

constexpr ErrorDefinition ToolPropertyNotApplicable = {
    static_cast<int>(ErrorNumber::ToolPropertyNotApplicable),
    ErrorSeverity::Warning, "Tool property not applicable"};

constexpr ErrorDefinition ToolNotAlignableToGivenOrientation = {
    static_cast<int>(ErrorNumber::ToolPropertyNotApplicable),
    ErrorSeverity::CriticalError, "Tool not alignable to given orientation"};

constexpr ErrorDefinition ToolNotCalibrated = {
    static_cast<int>(ErrorNumber::ToolNotCalibrated),
    ErrorSeverity::CriticalError, "Tool not calibrated"};

constexpr ErrorDefinition HeadErrorExcessiveForce = {
    static_cast<int>(ErrorNumber::HeadErrorExcessiveForce),
    ErrorSeverity::Error, "Head error excessive force"};

constexpr ErrorDefinition TypeOfProbeDoesNotAllowThisOperation = {
    static_cast<int>(ErrorNumber::TypeOfProbeDoesNotAllowThisOperation),
    ErrorSeverity::CriticalError,
    "Type of probe does not allow this operation"};

constexpr ErrorDefinition RawDataOfAcquisitionNotAvailable = {
    static_cast<int>(ErrorNumber::RawDataOfAcquisitionNotAvailable),
    ErrorSeverity::CriticalError, "Raw data of Acquisition not available"};

constexpr ErrorDefinition NoSharedMemorySpaceAvailable = {
    static_cast<int>(ErrorNumber::NoSharedMemorySpaceAvailable),
    ErrorSeverity::CriticalError, "No shared memory space available"};

constexpr ErrorDefinition FileNotFound = {
    static_cast<int>(ErrorNumber::FileNotFound), ErrorSeverity::CriticalError,
    "File not found"};

constexpr ErrorDefinition MachineLimitEncountered = {
    static_cast<int>(ErrorNumber::MachineLimitEncountered),
    ErrorSeverity::CriticalError,
    "Machine limit encountered [Move Out Of Limits]"};

constexpr ErrorDefinition AxisNotActive = {
    static_cast<int>(ErrorNumber::AxisNotActive), ErrorSeverity::CriticalError,
    "Axis not active"};

constexpr ErrorDefinition AxisPositionError = {
    static_cast<int>(ErrorNumber::AxisPositionError),
    ErrorSeverity::CriticalError, "Axis position error"};

constexpr ErrorDefinition ScaleReadHeadFailure = {
    static_cast<int>(ErrorNumber::ScaleReadHeadFailure),
    ErrorSeverity::FatalError, "Scale read head failure"};

constexpr ErrorDefinition Collision = {static_cast<int>(ErrorNumber::Collision),
                                       ErrorSeverity::CriticalError,
                                       "Collision"};

constexpr ErrorDefinition SpecifiedAngleOutOfRange = {
    static_cast<int>(ErrorNumber::SpecifiedAngleOutOfRange),
    ErrorSeverity::Error, "Specified angle out of range"};

constexpr ErrorDefinition PartNotAligned = {
    static_cast<int>(ErrorNumber::PartNotAligned), ErrorSeverity::Error,
    "Part not aligned"};

constexpr ErrorDefinition WrongDataFormat = {
    static_cast<int>(ErrorNumber::WrongDataFormat), ErrorSeverity::Error,
    "Wrong data format"};

constexpr ErrorDefinition PortNotAvailable = {
    static_cast<int>(ErrorNumber::PortNotAvailable), ErrorSeverity::Error,
    "Port not available"};

} // namespace errors
} // namespace types
} // namespace jdme2x

#endif
