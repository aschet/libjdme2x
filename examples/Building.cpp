#include <jdme2x/Types/Command.h>
#include <jdme2x/Types/Error.h>
#include <jdme2x/Types/Errors.h>
#include <jdme2x/Types/Response.h>

#include <iostream>

using namespace jdme2x::types;

static void buildCommand() {
  Command onMoveReportECommand(Tag(1, TagType::Event),
                               Method("OnMoveReportE")
                                   .with(Property("Time").with(Number(5)))
                                   .with(Property("Dis").with(Number(0.34)))
                                   .with(Property("X"))
                                   .with(Property("Y"))
                                   .with(Property("Z")));
  std::cout << onMoveReportECommand;
}

static void buildResponse() {
  Response acknowledgeRespone(Tag(2, TagType::Command), Acknowledge());
  std::cout << acknowledgeRespone;

  Response doneRespone(Tag(3, TagType::Command), Done());
  std::cout << doneRespone;

  Response dataRespone(Tag(4, TagType::Command),
                       Data(NumericalData{Number(1), Number(2)}));
  std::cout << dataRespone;

  Response errorRespone(Tag(5, TagType::Command),
                        Error(errors::ProtocolError, "Server::someMethod()"));
  std::cout << errorRespone;
}

int main() {
  buildCommand();
  buildResponse();
  return 0;
}
