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
};

class JDME2X_API IntArgument : public Argument {
public:
  explicit IntArgument(int Value);

  int getValue() const;

  std::string toString() const override;

private:
  int Value;
};

class JDME2X_API FloatArgument : public Argument {
public:
  explicit FloatArgument(float Value);

  float getValue() const;

  std::string toString() const override;

private:
  float Value;
};

class JDME2X_API StringArgument : public Argument {
public:
  explicit StringArgument(std::string_view Value);

  const std::string &getValue() const;

  std::string toString() const override;

private:
  std::string Value;
};

class JDME2X_API NameArgument : public Argument {
public:
  explicit NameArgument(std::string_view Value);

  const std::string &getValue() const;

  std::string toString() const override;

private:
  std::string Value;
};

class JDME2X_API EventTagArgument : public Argument {
public:
  explicit EventTagArgument(const Tag &Value);

  const Tag &getValue() const;

  std::string toString() const override;

private:
  Tag Value;
};

typedef std::vector<std::shared_ptr<Argument>> Arguments;

JDME2X_API std::string toString(const Arguments &Args);

} // namespace jdme2x

#endif
