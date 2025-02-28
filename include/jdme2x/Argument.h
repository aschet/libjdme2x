#ifndef JDME2X_ARGUMENT_H
#define JDME2X_ARGUMENT_H

#include "jdme2x/API.h"
#include "jdme2x/Serializeable.h"
#include "jdme2x/Tag.h"

#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace jdme2x {

class JDME2X_API Argument : public Serializeable {
public:
  virtual ~Argument();
};

class JDME2X_API IntArgument : public Argument {
private:
  int Value;

public:
  explicit IntArgument(int Value);

  int getValue() const;

  std::string toString() const override;
};

class JDME2X_API FloatArgument : public Argument {
private:
  float Value;

public:
  explicit FloatArgument(float Value);

  float getValue() const;

  std::string toString() const override;
};

class JDME2X_API StringArgument : public Argument {
private:
  std::string Value;

public:
  explicit StringArgument(std::string_view Value);

  const std::string &getValue() const;

  std::string toString() const override;
};

class JDME2X_API NameArgument : public Argument {
private:
  std::string Value;

public:
  explicit NameArgument(std::string_view Value);

  const std::string &getValue() const;

  std::string toString() const override;
};

class JDME2X_API EventTagArgument : public Argument {
private:
  Tag Value;

public:
  explicit EventTagArgument(const Tag &Value);

  const Tag &getValue() const;

  std::string toString() const override;
};

typedef std::vector<std::shared_ptr<Argument>> Arguments;

JDME2X_API std::string toString(const Arguments &Args);

} // namespace jdme2x

#endif
