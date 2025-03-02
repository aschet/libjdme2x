//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "CommandParserStates.h"

#include "jdme2x/Parser/ParserUtils.h"

#include <charconv>
#include <utility>

namespace jdme2x {

namespace parser {

CommandParserContext::CommandParserContext() {
  TransitionTo(std::make_unique<TagState>());
}

bool CommandParserContext::beginScope() { return State->beginScope(); }

bool CommandParserContext::endScope() { return State->endScope(); }

bool CommandParserContext::endSection() { return State->endSection(); }

bool CommandParserContext::parseEventTag(std::string_view Value) {
  return State->parseEventTag(Value);
}

bool CommandParserContext::parseName(std::string_view Value) {
  return State->parseName(Value);
}

bool CommandParserContext::parseNumber(std::string_view Value) {
  return State->parseNumber(Value);
}

bool CommandParserContext::parseString(std::string_view Value) {
  return State->parseString(Value);
}

bool CommandParserContext::parseXML(std::string_view Value) {
  return State->parseXML(Value);
}

bool CommandParserContext::hasCompleteParse() const {
  return State->hasCompleteParse();
}

void CommandParserContext::TransitionTo(
    std::unique_ptr<CommandParserState> NewState) {
  NewState->setContext(this);
  State = std::move(NewState);
}

void CommandParserState::setContext(CommandParserContext *Value) {
  Context = Value;
}

bool CommandParserState::beginScope() { return false; }

bool CommandParserState::endScope() { return false; }

bool CommandParserState::endSection() { return false; }

bool CommandParserState::parseEventTag(std::string_view) { return false; }

bool CommandParserState::parseName(std::string_view) { return false; }

bool CommandParserState::parseNumber(std::string_view) { return false; }

bool CommandParserState::parseString(std::string_view) { return false; }

bool CommandParserState::parseXML(std::string_view) { return false; }

bool CommandParserState::hasCompleteParse() const { return false; }

bool TagState::parseEventTag(std::string_view Value) {
  if (auto EventTag = parseTag(Value)) {
    Context->ParsedCommand.setTag(*EventTag);
    Context->TransitionTo(std::make_unique<MethodNameState>());
    return true;
  }
  return false;
}

bool TagState::parseNumber(std::string_view Value) {
  if (auto CommandTag = parseTag(Value)) {
    Context->ParsedCommand.setTag(*CommandTag);
    Context->TransitionTo(std::make_unique<MethodNameState>());
    return true;
  }
  return false;
}

bool MethodNameState::parseName(std::string_view Value) {
  Context->ParsedCommand.getMethod().setName(Value);
  Context->TransitionTo(std::make_unique<ArgumentListStartState>());
  return true;
}

bool ArgumentListStartState::beginScope() {
  Context->TransitionTo(std::make_unique<ArgumentState>());
  return true;
}

bool ArgumentState::endScope() {
  Context->TransitionTo(std::make_unique<TerminatorState>());
  return true;
}

bool ArgumentState::parseEventTag(std::string_view Value) {
  if (auto EventTag = parseTag(Value)) {
    Context->ParsedCommand.getMethod().addArgument(*EventTag);
    Context->TransitionTo(std::make_unique<ArgumentListSectionEndState>());
    return true;
  }
  return false;
}

bool ArgumentState::parseName(std::string_view Value) {
  Context->TransitionTo(std::make_unique<PropertyListBeginState>(Value));
  return true;
}

bool ArgumentState::parseNumber(std::string_view Value) {
  if (auto ParsedNumber = parser::parseNumber(Value)) {
    Context->ParsedCommand.getMethod().addArgument(std::move(*ParsedNumber));
    Context->TransitionTo(std::make_unique<ArgumentListSectionEndState>());
    return true;
  }
  return false;
}

bool ArgumentState::parseString(std::string_view Value) {
  Context->ParsedCommand.getMethod().addArgument(types::String(Value));
  Context->TransitionTo(std::make_unique<ArgumentListSectionEndState>());
  return true;
}

bool ArgumentState::parseXML(std::string_view Value) {
  Context->ParsedCommand.getMethod().setXML(Value);
  Context->TransitionTo(std::make_unique<ArgumentListEndState>());
  return true;
}

bool ArgumentListSectionEndState::endScope() {
  Context->TransitionTo(std::make_unique<TerminatorState>());
  return true;
}

bool ArgumentListSectionEndState::endSection() {
  Context->TransitionTo(std::make_unique<ArgumentState>());
  return true;
}

PropertyListBeginState::PropertyListBeginState(std::string_view Name)
    : CurrentProperty(std::make_shared<types::Property>(Name)) {}

bool PropertyListBeginState::beginScope() {
  Context->TransitionTo(
      std::make_unique<PropertyArgumentState>(CurrentProperty));
  return true;
}

bool PropertyListBeginState::endScope() {
  Context->ParsedCommand.getMethod().addArgument(CurrentProperty->getName());
  Context->TransitionTo(std::make_unique<TerminatorState>());
  return true;
}

bool PropertyListBeginState::endSection() {
  Context->ParsedCommand.getMethod().addArgument(CurrentProperty->getName());
  Context->TransitionTo(std::make_unique<ArgumentState>());
  return true;
}

PropertyArgumentState::PropertyArgumentState(
    std::shared_ptr<types::Property> CurrentProperty)
    : CurrentProperty(CurrentProperty) {}

bool PropertyArgumentState::endScope() {
  Context->ParsedCommand.getMethod().addArgument(std::move(*CurrentProperty));
  Context->TransitionTo(std::make_unique<ArgumentListSectionEndState>());
  return true;
}

bool PropertyArgumentState::parseNumber(std::string_view Value) {
  if (auto ParsedNumber = parser::parseNumber(Value)) {
    CurrentProperty->addArgument(std::move(*ParsedNumber));
    Context->TransitionTo(
        std::make_unique<PropertyArgumentListSectionEndState>(CurrentProperty));
    return true;
  }
  return false;
}

PropertyArgumentListSectionEndState::PropertyArgumentListSectionEndState(
    std::shared_ptr<types::Property> CurrentProperty)
    : CurrentProperty(CurrentProperty) {}

bool PropertyArgumentListSectionEndState::endScope() {
  Context->ParsedCommand.getMethod().addArgument(std::move(*CurrentProperty));
  Context->TransitionTo(std::make_unique<ArgumentListSectionEndState>());
  return true;
}

bool PropertyArgumentListSectionEndState::endSection() {
  Context->TransitionTo(
      std::make_unique<PropertyArgumentState>(CurrentProperty));
  return true;
}

bool ArgumentListEndState::endScope() {
  Context->TransitionTo(std::make_unique<TerminatorState>());
  return true;
}

bool TerminatorState::hasCompleteParse() const { return true; }

} // namespace parser

} // namespace jdme2x
