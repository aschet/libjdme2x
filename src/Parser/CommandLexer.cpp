#include "jdme2x/Parser/CommandLexer.h"

#include "CommandLexerDefinition.h"

namespace jdme2x {

namespace parser {

CommandLexer::CommandLexer()
    : Impl(std::make_unique<CommandLexerDefinition>()) {}

CommandLexer::~CommandLexer() = default;

bool CommandLexer::tokenize(
    std::string_view Text,
    std::function<bool(TokenID, std::string_view)> TokenHandler) {
  return Impl->tokenize(Text, TokenHandler);
}

} // namespace parser

} // namespace jdme2x
