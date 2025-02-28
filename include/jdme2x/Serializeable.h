#ifndef JDME2X_SERIALIZEABLE_H
#define JDME2X_SERIALIZEABLE_H

#include "jdme2x/API.h"

#include <string>

namespace jdme2x {

class JDME2X_API Serializeable {
public:
  virtual ~Serializeable();

  virtual std::string toString() const = 0;
};

} // namespace jdme2x

#endif
