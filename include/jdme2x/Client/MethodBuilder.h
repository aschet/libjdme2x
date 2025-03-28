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
#include "jdme2x/CoordSystem.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Name.h"
#include "jdme2x/Types/Property.h"
#include "jdme2x/Types/Tag.h"

#include <vector>

namespace jdme2x {

struct JDME2X_API MethodBuilder {
  // Server
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

  static Method buildSetProp(const std::vector<Property> &properties);

  static Method buildGetProp(const std::vector<Name> &properties);

  static Method buildEnumProp(const Name &reference);

  static Method buildEnumAllProp(const Name &reference);

  // DME
  static Method buildGetDMEVersion();

  static Method buildGetSupportedCommands();

  static Method buildGetSupportedArguments();

  static Method buildGetMachineClass();

  static Method buildHome();

  static Method buildIsHomed();

  // CartCMM
  static Method buildSetCoordSystem(CoordSystem csy);

  static Method buildGetCoordSystem();

  static Method buildSetCsyTransformation(CoordSystem csy, double x0, double y0,
                                          double z0, double theta, double psi,
                                          double phi);

  static Method buildSaveNamedCsyTransformation(const String &name, double x0,
                                                double y0, double z0,
                                                double theta, double psi,
                                                double phi);

  static Method buildGetNamedCsyTransformation(const String& name);

  static Method buildGetCsyTransformation(CoordSystem csy);

  static Method buildSaveActiveCoordSystem(const String& name);

  static Method buildLoadCoordSystem(const String &name);

  static Method buildDeleteCoordSystem(const String &name);

  static Method buildEnumCoordSystems();

  static Method buildGetTemperatureSensors();

  static Method buildReadTemperatureSensor(const String &name);

  static Method buildReadAllTemperatures();

  // CenterPart
  static Method buildCenterPart(double px, double py, double pz, double limit);

  static Method buildTiltPart(double dx, double dy, double dz, double limit);

  static Method buildTiltCenterPart(double px1, double py1, double pz1,
                                    double px2, double py2, double pz2,
                                    double limit);

  // Mover
  static Method buildEnableUser();

  static Method buildDisableUser();

  static Method buildIsUserEnabled();

  static Method buildEnumerateMoverAxes();

  static Method buildUpdateScaleTemperatures();
};

} // namespace jdme2x

#endif
