//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/CartCMMMethodBuilder.h"

#include "jdme2x/Names/MethodNames.h"

namespace jdme2x {

Method CartCMMMethodBuilder::buildSetCoordSystem(CoordSystem csy) {
  if (isSelectable(csy))
    return Method(SetCoordSystemName).with(String(toString(csy)));
  throw std::invalid_argument("csy not valid for SetCoordSystem");
}

Method CartCMMMethodBuilder::buildGetCoordSystem() {
  return Method(GetCoordSystemName);
}

Method CartCMMMethodBuilder::buildSetCsyTransformation(CoordSystem csy,
                                                       double x0, double y0,
                                                       double z0, double theta,
                                                       double psi, double phi) {
  if (isDefineable(csy))
    return Method(SetCsyTransformationName)
        .with(String(toString(csy)))
        .with(Number(x0))
        .with(Number(y0))
        .with(Number(z0))
        .with(Number(theta))
        .with(Number(psi))
        .with(Number(phi));
  throw std::invalid_argument("csy not valid for SetCsyTransformation");
}

Method CartCMMMethodBuilder::buildSaveNamedCsyTransformation(
    const String &name, double x0, double y0, double z0, double theta,
    double psi, double phi) {
  return Method(SaveNamedCsyTransformationName)
      .with(name)
      .with(Number(x0))
      .with(Number(y0))
      .with(Number(z0))
      .with(Number(theta))
      .with(Number(psi))
      .with(Number(phi));
}

Method
CartCMMMethodBuilder::buildGetNamedCsyTransformation(const String &name) {
  return Method(GetNamedCsyTransformationName).with(name);
}

Method CartCMMMethodBuilder::buildGetCsyTransformation(CoordSystem csy) {
  if (isDefineable(csy))
    return Method(GetCsyTransformationName).with(String(toString(csy)));
  throw std::invalid_argument("csy not valid for GetCsyTransformationName");
}

Method CartCMMMethodBuilder::buildSaveActiveCoordSystem(const String &name) {
  return Method(SaveActiveCoordSystemName).with(name);
}

Method CartCMMMethodBuilder::buildLoadCoordSystem(const String &name) {
  return Method(LoadCoordSystemName).with(name);
}

Method CartCMMMethodBuilder::buildDeleteCoordSystem(const String &name) {
  return Method(DeleteCoordSystemName).with(name);
}

Method CartCMMMethodBuilder::buildEnumCoordSystems() {
  return Method(EnumCoordSystemsName);
}

Method CartCMMMethodBuilder::buildGetTemperatureSensors() {
  return Method(GetTemperatureSensorsName);
}

Method CartCMMMethodBuilder::buildReadTemperatureSensor(const String &name) {
  return Method(ReadTemperatureSensorName).with(name);
}

Method CartCMMMethodBuilder::buildReadAllTemperatures() {
  return Method(ReadAllTemperaturesName);
}

} // namespace jdme2x
