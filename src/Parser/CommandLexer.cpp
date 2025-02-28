#include "jdme2x/Parser/CommandLexer.h"

#include "CommandLexerDefinition.h"

namespace lex = boost::spirit::lex;

namespace jdme2x {

namespace parser {

CommandLexer::CommandLexer()
    : Impl(std::make_unique<CommandLexerDefinition>()) {}

CommandLexer::~CommandLexer() = default;

bool CommandLexer::tokenize(
    std::string_view Text,
    std::function<bool(CommandTokenID, std::string_view)> TokenHandler) {
  if (Text.empty())
    return false;

  LexerFunctorAdapter<CommandTokenID> FunctorAdapter(TokenHandler);
  const char *First = Text.data();
  const char *Last = First + Text.length();
  return lex::tokenize(First, Last, *Impl, FunctorAdapter);
}

} // namespace parser

} // namespace jdme2x
