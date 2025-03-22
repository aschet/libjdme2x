//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_COORDSYSTEM_H
#define JDME2X_COORDSYSTEM_H

namespace jdme2x {

enum class CoordSystem {
  MachineCsy,
  MultipleArmCsy,
  MoveableMachineCsy,
  RotaryTableFixCsy,
  RotaryTableVarCsy,
  PartCsy,
  JogDisplayCsy,
  JogMoveCsy,
  SensorCsy,
};

} // namespace jdme2x

#endif
