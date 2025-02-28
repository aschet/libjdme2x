#ifndef JDME2X_PARSER_COMMANDPARSER_H
#define JDME2X_PARSER_COMMANDPARSER_H

#include "jdme2x/API.h"
#include "jdme2x/Command.h"

#include <memory>
#include <string_view>
#include <utility>

namespace jdme2x {

namespace parser {

class JDME2X_API CommandParser {
public:
  CommandParser();

  ~CommandParser();

  CommandParser(const CommandParser &) = delete;

  CommandParser(CommandParser &&) = delete;

  CommandParser &operator=(const CommandParser &) = delete;

  CommandParser &operator=(CommandParser &&) = delete;

  std::pair<bool, Command> parse(std::string_view Text);

private:
  struct Private;

  std::unique_ptr<Private> Impl;
};

} // namespace parser

} // namespace jdme2x

#endif
