#ifndef JDME2X_TAG_H
#define JDME2X_TAG_H

#include "jdme2x/API.h"
#include "jdme2x/Serializeable.h"

namespace jdme2x {

enum class TagType { Command, Event };

class JDME2X_API Tag : public Serializeable {
private:
  unsigned int Number;

  TagType Type;

public:
  Tag();
  
  Tag(unsigned int Number, TagType Type);

  void setNumber(unsigned int Value);

  unsigned int getNumber() const;

  void setType(TagType Value);

  TagType getType() const;

  std::string toString() const override;
};

} // namespace jdme2x

#endif
