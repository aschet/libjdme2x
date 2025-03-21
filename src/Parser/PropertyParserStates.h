//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef PARSER_PROPERTYPARSERSTATES_H
#define PARSER_PROPERTYPARSERSTATES_H

#include "ParserState.h"

#include "jdme2x/Types/Property.h"

#include <memory>
#include <string_view>

namespace jdme2x {

using PropertyParserState = State<Property>;

using PropertyParserContext = Context<Property>;

struct PropertyStartState : public PropertyParserState {
  bool parseName(PropertyParserContext &context,
                 std::string_view text) override;
};

struct PropertyValueStartState : public PropertyParserState {
  bool beginScope(PropertyParserContext &context) override;
};

struct PropertyValueState : public PropertyParserState {
  bool endScope(PropertyParserContext &context) override;

  bool parseNumber(PropertyParserContext &context,
                   std::string_view text) override;
};

struct NextPropertyValueState : public PropertyParserState {
  bool endScope(PropertyParserContext &context) override;

  bool endSection(PropertyParserContext &context) override;
};

struct PropertyEndState : public PropertyParserState {
  bool hasCompleteParse(PropertyParserContext &context) override;
};

} // namespace jdme2x

#endif
