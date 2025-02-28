//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef PARSER_RESPONSEPARSERSTATES_H
#define PARSER_RESPONSEPARSERSTATES_H

#include "MethodParserStates.h"
#include "ParserState.h"
#include "jdme2x/Types/Response.h"
#include "jdme2x/Types/Tag.h"

#include <memory>
#include <string_view>

namespace jdme2x {
namespace parser {
namespace states {

struct ResponseParserData {
  types::Response response;
  MethodParserContext methodContext =
      MethodParserContext(Singleton<MethodStartState>::instance());
};

using ResponseParserContext = Context<ResponseParserData>;

class ResponseStartState : public State<ResponseParserData> {
public:
  bool parseEventTag(ResponseParserContext &context,
                     std::string_view text) override;

  bool parseNumber(ResponseParserContext &context,
                   std::string_view text) override;
};

class ResponseTypeState : public State<ResponseParserData> {
public:
  bool parseResponseType(ResponseParserContext &context,
                         std::string_view text) override;
};

class ResponseErrorState : public StateFacade<ResponseParserData> {
public:
  bool parse(ResponseParserContext &context, TokenID id,
             std::string_view text) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

class ResponseDataState : public State<ResponseParserData> {
public:
  bool parseNumber(ResponseParserContext &context,
                   std::string_view text) override;

  bool parseString(ResponseParserContext &context,
                   std::string_view text) override;

  bool parseName(ResponseParserContext &context,
                 std::string_view text) override;
};

class NumericDataState : public State<ResponseParserData> {
public:
  bool parseNumber(ResponseParserContext &context,
                   std::string_view text) override;
};

class NextNumericDataState : public State<ResponseParserData> {
public:
  bool endSection(ResponseParserContext &context) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

class PropertyDataSeparatorState : public State<ResponseParserData> {
public:
  bool endSection(ResponseParserContext &context) override;
};

class PropertyDataValueState : public State<ResponseParserData> {
public:
  bool parseString(ResponseParserContext &context,
                   std::string_view text) override;
};

class MethodDataState : public StateFacade<ResponseParserData> {
public:
  bool parse(ResponseParserContext &context, TokenID id,
             std::string_view text) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

class NextPropertyListValueState : public State<ResponseParserData> {
public:
  bool endSection(ResponseParserContext &context) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

class PropertyListValueState : public StateFacade<ResponseParserData> {
public:
  bool parse(ResponseParserContext &context, TokenID id,
             std::string_view text) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

class ResponseEndState : public State<ResponseParserData> {
public:
  bool hasCompleteParse(ResponseParserContext &) override;
};

} // namespace states
} // namespace parser
} // namespace jdme2x

#endif
