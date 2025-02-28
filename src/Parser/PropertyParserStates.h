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
namespace parser {
namespace states {

using PropertyParserState = State<types::Property>;

using PropertyParserContext = Context<types::Property>;

class PropertyStartState : public PropertyParserState {
public:
  bool parseName(PropertyParserContext &context, std::string_view text) override;
};

class PropertyValueStartState : public PropertyParserState {
public:
  bool beginScope(PropertyParserContext &context) override;
};

class PropertyValueState : public PropertyParserState {
public:
  bool endScope(PropertyParserContext &context) override;

  bool parseNumber(PropertyParserContext &context,
                   std::string_view text) override;
};

class NextPropertyValueState : public PropertyParserState {
public:
  bool endScope(PropertyParserContext &context) override;

  bool endSection(PropertyParserContext &context) override;
};

class PropertyEndState : public PropertyParserState {
public:
  bool hasCompleteParse(PropertyParserContext &context) override;
};

} // namespace states
} // namespace parser
} // namespace jdme2x

#endif
