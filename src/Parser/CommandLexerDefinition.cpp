#include "CommandLexerDefinition.h"

namespace lex = boost::spirit::lex;

namespace jdme2x {

namespace parser {

struct LexerFunctorAdapter {
  typedef bool result_type;

  LexerFunctorAdapter(std::function<bool(TokenID, std::string_view)> Functor);

  template <typename Token> bool operator()(const Token &CurrentToken) {
    const char *First = &*CurrentToken.value().begin();
    const char *Last = &*CurrentToken.value().end();
    std::string_view Text(First, Last - First);
    return Functor(static_cast<TokenID>(CurrentToken.id()), Text);
  }

  std::function<bool(TokenID, std::string_view)> Functor;
};

CommandLexerDefinition::CommandLexerDefinition() {
  add("\\(", TokenID::OpenParen);
  add("\\)", TokenID::CloseParen);
  add(",", TokenID::Comma);
  add("[ ]+", TokenID::Space);
  add("E\\d{4}", TokenID::EventTag);
  add("[a-zA-Z][a-zA-Z0-9]*(\\.[a-zA-Z][a-zA-Z0-9]*)*", TokenID::Name);
  add("[+\\-]?(\\d+(\\.\\d*)?|(\\.\\d+))([eE][+\\-]?\\d{1,3})?",
      TokenID::Number);
  add("\\\"[ -!#-~]+\\\"", TokenID::String);
  // TODO: XML <[^>]+>([^<]*)<\/[^>]+>
  add("\n\r|\n|\r", TokenID::Terminator);
}

inline void CommandLexerDefinition::add(const char *Pattern, TokenID ID) {
  this->self.add(Pattern, static_cast<size_t>(ID));
}

bool CommandLexerDefinition::tokenize(
    std::string_view Text,
    std::function<bool(TokenID, std::string_view)> TokenHandler) {
  LexerFunctorAdapter FunctorAdapter(TokenHandler);
  const char *First = Text.data();
  const char *Last = First + Text.length();
  return lex::tokenize(First, Last, *this, FunctorAdapter);
  return false;
}

inline LexerFunctorAdapter::LexerFunctorAdapter(
    std::function<bool(TokenID, std::string_view)> Functor)
    : Functor(Functor) {}

} // namespace parser

} // namespace jdme2x
