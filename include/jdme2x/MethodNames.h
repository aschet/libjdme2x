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

constexpr const char *SetCoordSystemName = "SetCoordSystem"; // TODO#

constexpr const char *GetCoordSystemName = "GetCoordSystem"; // TODO

constexpr const char *SetCsyTransformationName = "SetCsyTransformation"; // TODO

constexpr const char *SaveNamedCsyTransformationName =
    "SaveNamedCsyTransformation"; // TODO

constexpr const char *GetNamedCsyTransformationName =
    "GetNamedCsyTransformation"; // TODO 

constexpr const char *GetCsyTransformationName = "GetCsyTransformation"; // TODO

constexpr const char *SaveActiveCoordSystemName = "SaveActiveCoordSystem"; // TODO

constexpr const char *LoadCoordSystemName = "LoadCoordSystem"; // TODO

constexpr const char *DeleteCoordSystemName = "DeleteCoordSystem"; // TODO

constexpr const char *EnumCoordSystemsName = "EnumCoordSystems"; // TODO

constexpr const char *GetTemperatureSensorsName = "GetTemperatureSensors"; // TODO

constexpr const char *ReadTemperatureSensorName = "ReadTemperatureSensor"; // TODO

constexpr const char *ReadAllTemperaturesName = "ReadAllTemperatures"; // TODO

// FormTester

constexpr const char *CenterPartName = "CenterPart";

constexpr const char *TiltPartName = "TiltPart";

constexpr const char *TiltCenterPartName = "TiltCenterPart";

constexpr const char *LockAxisName = "LockAxis"; // TODO

constexpr const char *LockPositionName = "LockPosition"; // TODO

// Mover

constexpr const char *EnableUserName = "EnableUser";

constexpr const char *DisableUserName = "DisableUser";

constexpr const char *IsUserEnabledName = "IsUserEnabled";

constexpr const char *EnumerateMoverAxesName = "EnumerateMoverAxes";

constexpr const char *UpdateScaleTemperaturesName = "UpdateScaleTemperatures";

constexpr const char *SetScaleTemperaturesName = "SetScaleTemperatures"; // TODO

constexpr const char *GetScaleTemperaturesName = "GetScaleTemperatures"; // TODO

constexpr const char *SetTemperatureCompensationOriginName =
    "SetTemperatureCompensationOrigin";

// Cartesian

constexpr const char *GoToName = "GoTo"; // TODO

constexpr const char *StepName = "Step"; // TODO

constexpr const char *GoToOnCircleName = "GoToOnCircle"; // TODO

constexpr const char *GoToOnSpiralName = "GoToOnSpiral"; // TODO

// Tool

constexpr const char *IsAlignableName = "IsAlignable"; // TODO

constexpr const char *GetName = "Get"; // TODO

constexpr const char *OnMoveReportName = "OnMoveReport"; // TODO

constexpr const char *OnMoveReportEName = "OnMoveReportE"; // TODO

constexpr const char *ReQualifyName = "ReQualify"; // TODO

// TouchTrigger

constexpr const char *OnPtMeasReportName = "OnPtMeasReport"; // TODO

constexpr const char *PtMeasName = "PtMeas"; // TODO

// Scanning

constexpr const char *OnScanReportName = "OnScanReport"; // TODO

constexpr const char *ScanOnCircleHintName = "ScanOnCircleHint"; // TODO

constexpr const char *ScanOnCircleName = "ScanOnCircle"; // TODO

constexpr const char *ScanOnLineHintName = "ScanOnLineHint"; // TODO

constexpr const char *ScanOnLineName = "ScanOnLine"; // TODO

constexpr const char *ScanOnCurveHintName = "ScanOnCurveHint"; // TODO

constexpr const char *ScanOnCurveDensityName = "ScanOnCurveDensity"; // TODO

constexpr const char *ScanOnCurveName = "ScanOnCurve"; // TODO

constexpr const char *ScanOnHelixName = "ScanOnHelix"; // TODO

constexpr const char *ScanUnknownHintName = "ScanUnknownHint"; // TODO

constexpr const char *ScanUnknownDensityName = "ScanUnknownDensity"; // TODO

constexpr const char *ScanInPlaneEndIsSphereName = "ScanInPlaneEndIsSphere"; // TODO

constexpr const char *ScanInPlaneEndIsPlaneName = "ScanInPlaneEndIsPlane"; // TODO

constexpr const char *ScanInPlaneEndIsCylName = "ScanInPlaneEndIsCyl"; // TODO

constexpr const char *ScanInCylEndIsSphereName = "ScanInCylEndIsSphere"; // TODO

constexpr const char *ScanInCylEndIsPlaneName = "ScanInCylEndIsPlane"; // TODO

// TouchTrigger_SelfCentering

constexpr const char *PtMeasSelfCenterName = "PtMeasSelfCenter"; // TODO

constexpr const char *PtMeasSelfCenterLockedName = "PtMeasSelfCenterLocked"; // TODO



} // namespace jdme2x

#endif
