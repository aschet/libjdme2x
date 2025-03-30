//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_CLIENT_CARTCMMMETHODBUILDER_H
#define JDME2X_CLIENT_CARTCMMMETHODBUILDER_H

#include "jdme2x/API.h"
#include "jdme2x/CoordSystem.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/String.h"

namespace jdme2x {

struct JDME2X_API CartCMMMethodBuilder {
  CartCMMMethodBuilder() = delete;

  static Method buildSetCoordSystem(CoordSystem csy);

  static Method buildGetCoordSystem();

  static Method buildSetCsyTransformation(CoordSystem csy, double x0, double y0,
                                          double z0, double theta, double psi,
                                          double phi);

  static Method buildSaveNamedCsyTransformation(const String &name, double x0,
                                                double y0, double z0,
                                                double theta, double psi,
                                                double phi);

  static Method buildGetNamedCsyTransformation(const String &name);

  static Method buildGetCsyTransformation(CoordSystem csy);

  static Method buildSaveActiveCoordSystem(const String &name);

  static Method buildLoadCoordSystem(const String &name);

  static Method buildDeleteCoordSystem(const String &name);

  static Method buildEnumCoordSystems();

  static Method buildGetTemperatureSensors();

  static Method buildReadTemperatureSensor(const String &name);

  static Method buildReadAllTemperatures();
};

} // namespace jdme2x

#endif
