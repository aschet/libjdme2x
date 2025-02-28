#ifndef PARSER_COMMANDLEXERDEFINITION_H
#define PARSER_COMMANDLEXERDEFINITION_H

#include "jdme2x/Parser/TokenID.h"

#include <boost/spirit/include/lex_lexertl.hpp>
#include <functional>
#include <string>

namespace jdme2x {

namespace parser {

class CommandLexerDefinition
    : public boost::spirit::lex::lexer<boost::spirit::lex::lexertl::lexer<>> {
public:
  CommandLexerDefinition();

  template <typename Enum> void add(const char *Pattern, Enum TokenID) {
    this->self.add(Pattern, static_cast<size_t>(TokenID));
  }
};

template <typename Enum> struct LexerFunctorAdapter {
  typedef bool result_type;

  LexerFunctorAdapter(std::function<bool(Enum, std::string_view)> Functor)
      : Functor(Functor) {}

  template <typename Token> bool operator()(const Token &CurrentToken) {
    const char *First = &*CurrentToken.value().begin();
    const char *Last = &*CurrentToken.value().end();
    std::string_view Text(First, Last - First);
    return Functor(static_cast<Enum>(CurrentToken.id()), Text);
  }

  std::function<bool(Enum, std::string_view)> Functor;
};

} // namespace parser

} // namespace jdme2x

#endif
