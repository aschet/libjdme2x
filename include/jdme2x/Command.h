#ifndef JDME2X_COMMAND_H
#define JDME2X_COMMAND_H

#include "jdme2x/API.h"
#include "jdme2x/Method.h"
#include "jdme2x/Serializeable.h"
#include "jdme2x/Tag.h"

#include <string>

namespace jdme2x {

class JDME2X_API Command : public Serializeable {
public:
  Command();

  Command(const Tag &CommandTag, const Method &CommandMethod);

  void setTag(const Tag &Value);

  const Tag &getTag() const;

  void setMethod(const Method &Value);

  const Method &getMethod() const;

  Method &getMethod();

  std::string toString() const override;

private:
  Tag CommandTag;

  Method CommandMethod;
};

} // namespace jdme2x

#endif
