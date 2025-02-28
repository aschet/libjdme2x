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

  void add(const char *Pattern, TokenID ID);

  bool tokenize(std::string_view Text,
                std::function<bool(TokenID, std::string_view)> TokenHandler);
};

} // namespace parser

} // namespace jdme2x

#endif
