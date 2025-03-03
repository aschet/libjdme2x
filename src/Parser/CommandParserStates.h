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

#include "jdme2x/Types/Command.h"

#include <memory>
#include <string_view>

namespace jdme2x {

namespace parser {

class CommandParserState;

class CommandParserContext {
public:
  CommandParserContext();

  bool beginScope();

  bool endScope();

  bool endSection();

  bool parseEventTag(std::string_view Value);

  bool parseName(std::string_view Value);

  bool parseNumber(std::string_view Value);

  bool parseString(std::string_view Value);

  bool parseXML(std::string_view Value);

  bool hasCompleteParse() const;

  void TransitionTo(std::unique_ptr<CommandParserState> NewState);

  types::Command ParsedCommand;

private:
  std::unique_ptr<CommandParserState> State;
};

class CommandParserState {
public:
  virtual ~CommandParserState() = default;

  void setContext(CommandParserContext *Value);

  virtual bool beginScope();

  virtual bool endScope();

  virtual bool endSection();

  virtual bool parseEventTag(std::string_view Value);

  virtual bool parseName(std::string_view Value);

  virtual bool parseNumber(std::string_view Value);

  virtual bool parseString(std::string_view Value);

  virtual bool parseXML(std::string_view Value);

  virtual bool hasCompleteParse() const;

protected:
  CommandParserContext *Context = nullptr;
};

class TagState : public CommandParserState {
public:
  bool parseEventTag(std::string_view Value) override;

  bool parseNumber(std::string_view Value) override;
};

class MethodNameState : public CommandParserState {
public:
  bool parseName(std::string_view Value) override;
};

class ArgumentListStartState : public CommandParserState {
public:
  bool beginScope() override;
};

class ArgumentState : public CommandParserState {
public:
  bool endScope() override;

  bool parseEventTag(std::string_view Value) override;

  bool parseName(std::string_view Value) override;

  bool parseNumber(std::string_view Value) override;

  bool parseString(std::string_view Value) override;

  bool parseXML(std::string_view Value) override;
};

class ArgumentListSectionEndState : public CommandParserState {
public:
  bool endScope() override;

  bool endSection() override;
};

class PropertyListBeginState : public CommandParserState {
public:
  PropertyListBeginState(std::string_view Name);

  bool beginScope() override;

  bool endScope() override;

  bool endSection() override;

private:
  std::shared_ptr<types::Property> CurrentProperty;
};

class PropertyArgumentState : public CommandParserState {
public:
  PropertyArgumentState(std::shared_ptr<types::Property> CurrentProperty);

  bool endScope() override;

  bool parseNumber(std::string_view Value) override;

private:
  std::shared_ptr<types::Property> CurrentProperty;
};

class PropertyArgumentListSectionEndState : public CommandParserState {
public:
  PropertyArgumentListSectionEndState(
      std::shared_ptr<types::Property> CurrentProperty);

  bool endScope() override;

  bool endSection() override;

private:
  std::shared_ptr<types::Property> CurrentProperty;
};

class ArgumentListEndState : public CommandParserState {
public:
  bool endScope() override;
};

class TerminatorState : public CommandParserState {
public:
  bool hasCompleteParse() const override;
};

} // namespace parser

} // namespace jdme2x

#endif
