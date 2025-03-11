//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_TYPES_RESPONSE_H
#define JDME2X_TYPES_RESPONSE_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Acknowledge.h"
#include "jdme2x/Types/Data.h"
#include "jdme2x/Types/Done.h"
#include "jdme2x/Types/Error.h"

#include <ostream>
#include <variant>

namespace jdme2x {
namespace types {

using ResponseValue =
    std::variant<std::monostate, Acknowledge, Done, Data, Error>;

struct JDME2X_API Response {
  Response() = default;

  Response(const Tag &tag, const ResponseValue &value);

  Response(const Tag &tag, ResponseValue &&value);

  virtual ~Response() = default;

  Response(const Response &) = default;

  Response(Response &&) = default;

  Response &operator=(const Response &) = default;

  Response &operator=(Response &&) = default;

  bool operator==(const Response &other) const;

  bool operator!=(const Response &other) const;

  bool operator<(const Response &other) const;

  bool holdsAcknowledge() const;

  bool holdsDone() const;

  bool holdsData() const;

  const Data &data() const;

  Data &data();

  bool holdsError() const;

  const Error &error() const;

  Error &error();

  bool holdsNumericData() const;

  const NumericalData &numericData() const;

  NumericalData &numericData();

  bool holdsPropertyData() const;

  const PropertyData &propertyData() const;

  PropertyData &propertyData();

  bool holdsMethod() const;

  const Method &method() const;

  Method &method();

  bool holdsPropertyList() const;

  const PropertyList &propertyList() const;

  PropertyList &propertyList();

  Tag tag;

  ResponseValue value;
};

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const ResponseValue &instance);

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Response &instance);

} // namespace types
} // namespace jdme2x

#endif
