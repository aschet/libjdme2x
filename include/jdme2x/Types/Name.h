//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_NAME_H
#define JDME2X_TYPES_NAME_H

#include "jdme2x/API.h"

#include <ostream>
#include <string>
#include <string_view>

namespace jdme2x {
namespace types {

class JDME2X_API Name {
  friend std::ostream &operator<<(std::ostream &, const Name &);

public:
  Name();

  Name(std::string_view Value);

  Name &operator=(std::string_view Other);

  bool isBasic() const;

  operator const std::string &() const;

  bool operator==(std::string_view Other) const;

  bool operator!=(std::string_view Other) const;

private:
  std::string Value;
};

JDME2X_API std::ostream &operator<<(std::ostream &Stream, const Name &Instance);

} // namespace types

} // namespace jdme2x

#endif
