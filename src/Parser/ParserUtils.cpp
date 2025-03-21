//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/ParserUtils.h"

#include <charconv>

namespace jdme2x {

JDME2X_API std::optional<Tag> createTag(std::string_view text) {
  constexpr size_t TagLength = 5;
  if (text.length() != TagLength)
    return std::nullopt;

  TagType type = TagType::Command;
  if (text.front() == 'E') {
    text.remove_prefix(1);
    type = TagType::Event;
  }

  unsigned int number = 0;
  auto [ptr, error] =
      std::from_chars(text.data(), text.data() + text.size(), number);

  if (error != std::errc())
    return std::nullopt;
  return Tag(number, type);
}

JDME2X_API std::optional<Number> createNumber(std::string_view text) {
  if (text.empty())
    return std::nullopt;

  constexpr size_t MaxNumberLength = 16;
  if (text.length() > MaxNumberLength)
    return std::nullopt;

  if (text.front() == '+')
    text.remove_prefix(1);

  if (text.find_first_of(".eE") != std::string::npos) {
    double number = 0.0;
    auto [ptr, error] =
        std::from_chars(text.data(), text.data() + text.size(), number);
    if (error != std::errc())
      return std::nullopt;
    return Number(number);
  } else {
    int number = 0;
    auto [ptr, error] =
        std::from_chars(text.data(), text.data() + text.size(), number);
    if (error != std::errc())
      return std::nullopt;
    return Number(number);
  }
}

JDME2X_API std::optional<String> createString(std::string_view text) {
  if (text.length() < 2)
    return std::nullopt;

  if (text[0] != '"')
    return std::nullopt;
  text.remove_prefix(1);

  if (text[text.length() - 1] != '"')
    return std::nullopt;
  text.remove_suffix(1);

  return String(text);
}

JDME2X_API std::optional<Error>
createError(const Method &method) {
  if (method.args.size() != 4)
    return std::nullopt;

  if (method.name.value != ErrorName)
    return std::nullopt;

  Error error;

  constexpr size_t SeverityIndex = 0;
  if (auto severity = std::get_if<Number>(&method.args[SeverityIndex])) {
    const int *intValue = std::get_if<int>(severity);
    if (!intValue)
      return std::nullopt;

    switch (*intValue) {
    case static_cast<int>(ErrorSeverity::Info):
    case static_cast<int>(ErrorSeverity::Warning):
    case static_cast<int>(ErrorSeverity::Error):
    case static_cast<int>(ErrorSeverity::CriticalError):
    case static_cast<int>(ErrorSeverity::FatalError):
      error.severity = static_cast<ErrorSeverity>(*intValue);
      break;
    case static_cast<int>(ErrorSeverity::Undefined):
    default:
      return std::nullopt;
    }
  } else {
    return std::nullopt;
  }

  constexpr size_t NumberIndex = 1;
  if (auto number = std::get_if<Number>(&method.args[NumberIndex])) {
    const int *intValue = std::get_if<int>(number);
    if (!intValue)
      return std::nullopt;
    if (*intValue < MinError || *intValue > MaxError)
      return std::nullopt;
    error.number = *intValue;
  } else {
    return std::nullopt;
  }

  constexpr size_t CauseIndex = 2;
  if (auto cause = std::get_if<String>(&method.args[CauseIndex]))
    error.cause = *cause;
  else
    return std::nullopt;

  constexpr size_t InformationIndex = 3;
  if (auto information =
          std::get_if<String>(&method.args[InformationIndex]))
    error.information = *information;
  else
    return std::nullopt;

  return error;
}

JDME2X_API std::optional<Property>
createProperty(const Method &method) {
  Property property(method.name);

  for (auto &arg : method.args) {
    if (auto number = std::get_if<Number>(&arg)) {
      property.args.emplace_back(*number);
    } else {
      return std::nullopt;
    }
  }

  return property;
}

} // namespace jdme2x
