#ifndef JDME2X_COMMANDPARSER_H
#define JDME2X_COMMANDPARSER_H

#include "jdme2x/API.h"
#include "jdme2x/Command.h"

#include <string>
#include <utility>
#include <memory>

namespace jdme2x {

class JDME2X_API CommandParser {
public:
  CommandParser();

  ~CommandParser();

  CommandParser(const CommandParser &) = delete;

  CommandParser(CommandParser &&) = delete;

  CommandParser &operator=(const CommandParser &) = delete;

  CommandParser &operator=(CommandParser &&) = delete;

  std::pair<bool, Command> parse(const std::string &Text);

private:
  struct Private;

  std::unique_ptr<Private> Impl;
};

} // namespace jdme2x

#endif
