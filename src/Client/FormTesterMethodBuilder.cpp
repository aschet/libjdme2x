//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/FormTesterMethodBuilder.h"

#include "jdme2x/Names/AxisNames.h"
#include "jdme2x/Names/MethodNames.h"
#include "jdme2x/Names/PositionNames.h"

namespace jdme2x {

Method FormTesterMethodBuilder::buildCenterPart(double px, double py, double pz,
                                                double limit) {
  return Method(CenterPartName)
      .with(Number(px))
      .with(Number(py))
      .with(Number(pz))
      .with(Number(limit));
}

Method FormTesterMethodBuilder::buildTiltPart(double dx, double dy, double dz,
                                              double limit) {
  return Method(TiltPartName)
      .with(Number(dx))
      .with(Number(dy))
      .with(Number(dz))
      .with(Number(limit));
}

Method FormTesterMethodBuilder::buildTiltCenterPart(double px1, double py1,
                                                    double pz1, double px2,
                                                    double py2, double pz2,
                                                    double limit) {
  return Method(TiltCenterPartName)
      .with(Number(px1))
      .with(Number(py1))
      .with(Number(pz1))
      .with(Number(px2))
      .with(Number(py2))
      .with(Number(pz2))
      .with(Number(limit));
}

Method FormTesterMethodBuilder::buildLockAxis(bool x, bool y, bool z, bool r,
                                              bool a, bool b, bool c) {
  Method method(LockAxisName);
  if (x)
    method.with(Property(XName));
  if (y)
    method.with(Property(YName));
  if (z)
    method.with(Property(ZName));
  if (r)
    method.with(Property(RName));
  if (a)
    method.with(Property(AName));
  if (b)
    method.with(Property(BName));
  if (c)
    method.with(Property(CName));
  return method;
}

Method FormTesterMethodBuilder::buildLockPosition(bool xfr, bool yfr, bool zfr,
                                                  bool rfr, bool pfr) {
  Method method(LockPositionName);
  if (xfr)
    method.with(Property(XFRName));
  if (yfr)
    method.with(Property(YFRName));
  if (zfr)
    method.with(Property(ZFRName));
  if (rfr)
    method.with(Property(RFRName));
  if (pfr)
    method.with(Property(PFRName));
  return method;
}

} // namespace jdme2x
