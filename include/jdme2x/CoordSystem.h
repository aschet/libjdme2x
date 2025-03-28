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

#include "jdme2x/API.h"

#include <string_view>

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

JDME2X_API CoordSystem toCoordSystem(std::string_view name);

JDME2X_API std::string_view toString(CoordSystem csy);

constexpr bool isSelectable(CoordSystem csy) {
  switch (csy) {
  case CoordSystem::MachineCsy:
  case CoordSystem::MoveableMachineCsy:
  case CoordSystem::MultipleArmCsy:
  case CoordSystem::RotaryTableVarCsy:
  case CoordSystem::PartCsy:
    return true;
  default:
    return false;
  }
}

constexpr bool isDefineable(CoordSystem csy) {
  switch (csy) {
  case CoordSystem::PartCsy:
  case CoordSystem::JogDisplayCsy:
  case CoordSystem::JogMoveCsy:
  case CoordSystem::SensorCsy:
  case CoordSystem::MoveableMachineCsy:
  case CoordSystem::MultipleArmCsy:
  case CoordSystem::RotaryTableFixCsy:
    return true;
  default:
    return false;
  }
}

} // namespace jdme2x

#endif
