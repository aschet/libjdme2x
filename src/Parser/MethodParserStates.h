//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef PARSER_METHODPARSERSTATES_H
#define PARSER_METHODPARSERSTATES_H

#include "ParserState.h"
#include "PropertyParserStates.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Name.h"

#include <memory>
#include <string_view>

namespace jdme2x {
namespace parser {
namespace states {

struct MethodParserData {
  types::Method method;
  types::Name currentName;
  PropertyParserContext propertyContext =
      PropertyParserContext(Singleton<PropertyStartState>::instance());
};

using MethodParserState = State<MethodParserData>;

using MethodParserContext = Context<MethodParserData>;

class MethodStartState : public MethodParserState {
public:
  bool parseName(MethodParserContext &context, std::string_view text) override;
};

class ArgumentListStartState : public MethodParserState {
public:
  bool beginScope(MethodParserContext &context) override;
};

class ArgumentState : public MethodParserState {
public:
  bool endScope(MethodParserContext &context) override;

  bool parseEventTag(MethodParserContext &context,
                     std::string_view text) override;

  bool parseName(MethodParserContext &context, std::string_view text) override;

  bool parseNumber(MethodParserContext &context,
                   std::string_view text) override;

  bool parseString(MethodParserContext &context,
                   std::string_view text) override;

  bool parseXML(MethodParserContext &context, std::string_view text) override;
};

class NextArgumentState : public MethodParserState {
public:
  bool endScope(MethodParserContext &context) override;

  bool endSection(MethodParserContext &context) override;
};

class PropertyOrNameArgumentState : public MethodParserState {
public:
  bool beginScope(MethodParserContext &context) override;

  bool endScope(MethodParserContext &context) override;

  bool endSection(MethodParserContext &context) override;
};

class PropertyArgumentState : public StateFacade<MethodParserData> {
public:
  bool parse(MethodParserContext &context, TokenID id,
             std::string_view text) override;

  bool hasCompleteParse(MethodParserContext &context) override;
};

class ArgumentListEndState : public MethodParserState {
public:
  bool endScope(MethodParserContext &context) override;
};

class MethodEndState : public MethodParserState {
public:
  bool hasCompleteParse(MethodParserContext &context) override;
};

} // namespace states
} // namespace parser
} // namespace jdme2x

#endif
