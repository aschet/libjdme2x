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
  Response response;
  MethodParserContext methodContext =
      MethodParserContext(Singleton<MethodStartState>::instance());
};

using ResponseParserContext = Context<ResponseParserData>;

struct ResponseStartState : public State<ResponseParserData> {
  bool parseEventTag(ResponseParserContext &context,
                     std::string_view text) override;

  bool parseNumber(ResponseParserContext &context,
                   std::string_view text) override;
};

struct ResponseTypeState : public State<ResponseParserData> {
  bool parseResponseType(ResponseParserContext &context,
                         std::string_view text) override;
};

struct ResponseErrorState : public StateFacade<ResponseParserData> {
  bool parse(ResponseParserContext &context, TokenID id,
             std::string_view text) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

struct ResponseDataState : public State<ResponseParserData> {
  bool parseNumber(ResponseParserContext &context,
                   std::string_view text) override;

  bool parseString(ResponseParserContext &context,
                   std::string_view text) override;

  bool parseName(ResponseParserContext &context,
                 std::string_view text) override;
};

struct NumericDataState : public State<ResponseParserData> {
  bool parseNumber(ResponseParserContext &context,
                   std::string_view text) override;
};

struct NextNumericDataState : public State<ResponseParserData> {
  bool endSection(ResponseParserContext &context) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

struct PropertyDataSeparatorState : public State<ResponseParserData> {
  bool endSection(ResponseParserContext &context) override;
};

struct PropertyDataValueState : public State<ResponseParserData> {
  bool parseString(ResponseParserContext &context,
                   std::string_view text) override;
};

struct MethodDataState : public StateFacade<ResponseParserData> {
  bool parse(ResponseParserContext &context, TokenID id,
             std::string_view text) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

struct NextPropertyListValueState : public State<ResponseParserData> {
  bool endSection(ResponseParserContext &context) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

struct PropertyListValueState : public StateFacade<ResponseParserData> {
  bool parse(ResponseParserContext &context, TokenID id,
             std::string_view text) override;

  bool hasCompleteParse(ResponseParserContext &context) override;
};

struct ResponseEndState : public State<ResponseParserData> {
  bool hasCompleteParse(ResponseParserContext &) override;
};

} // namespace states
} // namespace parser
} // namespace jdme2x

#endif
