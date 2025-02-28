#include "jdme2x/Parser/CommandLexer.h"

#include "CommandLexerImpl.h"

namespace jdme2x {

namespace parser {

CommandLexer::CommandLexer() : Impl(std::make_unique<CommandLexerImpl>()) {}

CommandLexer::~CommandLexer() = default;

bool CommandLexer::tokenize(
    std::string_view Text,
    std::function<bool(TokenID, std::string_view)> TokenHandler) const {
  return Impl->tokenize(Text, TokenHandler);
}

} // namespace parser

} // namespace jdme2x
