//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_CLIENT_FORMTESTERMETHODBUILDER_H
#define JDME2X_CLIENT_FORMTESTERMETHODBUILDER_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Method.h"

namespace jdme2x {

struct JDME2X_API FormTesterMethodBuilder {
  FormTesterMethodBuilder() = delete;

  static Method buildCenterPart(double px, double py, double pz, double limit);

  static Method buildTiltPart(double dx, double dy, double dz, double limit);

  static Method buildTiltCenterPart(double px1, double py1, double pz1,
                                    double px2, double py2, double pz2,
                                    double limit);

  static Method buildLockAxis(bool x, bool y, bool z, bool r, bool a, bool b,
                              bool c);

  static Method buildLockPosition(bool xfr, bool yfr, bool zfr, bool rfr,
                                  bool pfr);
};

} // namespace jdme2x

#endif
