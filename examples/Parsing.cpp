#include <jdme2x/Parser/Lexer.h>

#include <iostream>

using namespace jdme2x::parser;

static void tokenizeCommand() {
  const char *commandText = "00002 AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)\r\n";
  Lexer lexer;
  std::cout << "Tokens of " << commandText;
  lexer.tokenize(commandText, [](TokenID ID, std::string_view Text) -> bool {
    if (ID != TokenID::Space && ID != TokenID::Terminator)
      std::cout << Text << "\n";
    return true;
  });
  std::cout << "\n";
}

static void tokenizeResponse() {
  const char *responseText = "E0005 %\r\n";
  Lexer lexer;
  std::cout << "Tokens of " << responseText;
  lexer.tokenize(responseText, [](TokenID ID, std::string_view Text) -> bool {
    if (ID != TokenID::Space && ID != TokenID::Terminator)
      std::cout << Text << "\n";
    return true;
  });
  std::cout << "\n";
}

int main() {
  tokenizeCommand();
  tokenizeResponse();
  return 0;
}
