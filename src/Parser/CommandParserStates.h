//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef PARSER_COMMANDPARSERSTATES_H
#define PARSER_COMMANDPARSERSTATES_H

#include "MethodParserStates.h"
#include "ParserState.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Tag.h"

#include <memory>
#include <string_view>

namespace jdme2x {
namespace parser {

struct CommandParserData {
  Tag tag;
  MethodParserContext methodContext =
      MethodParserContext(Singleton<MethodStartState>::instance());
};

using CommandParserContext = Context<CommandParserData>;

struct CommandStartState : public State<CommandParserData> {
  bool parseEventTag(CommandParserContext &context,
                     std::string_view text) override;

  bool parseNumber(CommandParserContext &context,
                   std::string_view text) override;
};

struct CommandMethodState : public StateFacade<CommandParserData> {
  bool parse(CommandParserContext &context, TokenID id,
             std::string_view text) override;

  bool hasCompleteParse(CommandParserContext &context) override;
};

struct CommandEndState : public State<CommandParserData> {
  bool hasCompleteParse(CommandParserContext &context) override;
};

} // namespace parser
} // namespace jdme2x

#endif
