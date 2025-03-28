//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/CoordSystem.h"

#include "jdme2x/CoordSystemNames.h"

#include <array>
#include <stdexcept>

namespace jdme2x {

constexpr std::array<std::pair<std::string_view, CoordSystem>, 9>
    CoordSystemMap{{{MachineCsyName, CoordSystem::MachineCsy},
                    {MultipleArmCsyName, CoordSystem::MultipleArmCsy},
                    {MoveableMachineCsyName, CoordSystem::MoveableMachineCsy},
                    {RotaryTableFixCsyName, CoordSystem::RotaryTableFixCsy},
                    {RotaryTableVarCsyName, CoordSystem::RotaryTableVarCsy},
                    {PartCsyName, CoordSystem::PartCsy},
                    {JogDisplayCsyName, CoordSystem::JogDisplayCsy},
                    {JogMoveCsyName, CoordSystem::JogMoveCsy},
                    {SensorCsyName, CoordSystem::SensorCsy}}};

JDME2X_API CoordSystem toCoordSystem(std::string_view name) {
  auto it =
      std::find_if(CoordSystemMap.begin(), CoordSystemMap.end(),
                   [&name](const auto &pair) { return pair.first == name; });
  if (it != CoordSystemMap.end()) {
    return it->second;
  }
  throw std::invalid_argument("Unknown CoordSystem name");
}

JDME2X_API std::string_view toString(CoordSystem csy) {
  auto it =
      std::find_if(CoordSystemMap.begin(), CoordSystemMap.end(),
                   [&csy](const auto &pair) { return pair.second == csy; });
  if (it != CoordSystemMap.end()) {
    return it->first;
  }
  throw std::invalid_argument("Unknown CoordSystem csy");
}

} // namespace jdme2x
