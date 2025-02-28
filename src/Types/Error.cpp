//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Error.h"

#include <iomanip>

namespace jdme2x {
namespace types {

Error::Error()
    : severity(ErrorSeverity::Undefined),
      number(static_cast<int>(ErrorNumber::Undefined)) {}

Error::Error(const ErrorDefinition &definition, String &&cause)
    : severity(definition.severity),
      number(static_cast<int>(definition.number)), cause(cause),
      information(definition.information) {}

Error::Error(const ErrorDefinition &definition, const String &cause)
    : severity(definition.severity),
      number(static_cast<int>(definition.number)), cause(cause),
      information(definition.information) {}

Error::Error(ErrorSeverity severity, int number, const String &cause,
             const String &information)
    : severity(severity), number(number), cause(cause),
      information(information) {}

bool Error::operator==(const Error &other) const {
  if (this == &other)
    return true;
  return severity == other.severity && number == other.number &&
         cause == other.cause && information == other.information;
}

bool Error::operator!=(const Error &other) const { return !operator==(other); }

bool Error::operator<(const Error &other) const {
  return number < other.number;
}

bool Error::operator==(const ErrorNumber &other) const {
  return number == static_cast<int>(other);
}

bool Error::operator!=(const ErrorNumber &other) const {
  return !operator==(other);
};

ErrorGroup Error::getGroup() const {
  if (number >= 0 && number <= 4999)
    return ErrorGroup::DefinedByIPPDME;
  if (number >= 5000 && number <= 5999)
    return ErrorGroup::ReservedForOSIS;
  if (number >= 6000 && number <= 7999)
    return ErrorGroup::Reserved;
  if (number >= 8000 && number <= 8999)
    return ErrorGroup::DefineableFromServer;
  if (number >= 9000 && number <= 9999)
    return ErrorGroup::DefineableFromClient;
  return ErrorGroup::Undefined;
}

bool Error::requiresClearAllErrors() const {
  return severity > ErrorSeverity::Error;
}

JDME2X_API std::ostream &operator<<(std::ostream &stream,
                                    const Error &instance) {
  stream << ErrorID << ' ' << ErrorName << '('
         << static_cast<int>(instance.severity) << ", " << std::setw(4)
         << std::setfill('0') << instance.number << ", " << instance.cause
         << ", " << instance.information << ')';
  return stream;
}

} // namespace types
} // namespace jdme2x
