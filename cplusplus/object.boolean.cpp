#include <cstdio>
#include <memory>
#include <stdexcept>
#include "object.boolean.h"
#include "object.integer.h"


ObjectBoolean::ObjectBoolean(bool value)
: _value(value)
{}


ObjectBoolean::ObjectBoolean(ObjectBoolean *pObj)
: _value(pObj->_value)
{}


std::string ObjectBoolean::to_string(void)
{
  return std::string(_value ? "true" : "false");
}


IOperable *ObjectBoolean::evaluate(environment *env)
{
  return new ObjectBoolean(this);
}


ObjectBoolean *ObjectBoolean::operator_boolean_not(void)
{
  return new ObjectBoolean(!_value);
}


ObjectBoolean *ObjectBoolean::operator_boolean_or(IOperable *right_side)
{
  printf("We are in ObjectBoolean::operator_boolean_or: _value: %s\n", to_string().c_str());

  std::unique_ptr<ObjectBoolean> pbool;
  ObjectBoolean *right(dynamic_cast<ObjectBoolean *>(right_side));
  if (right == NULL)
  {
    ObjectInteger *pint(dynamic_cast<ObjectInteger *>(right_side));
    if (pint == NULL)
    {
      throw std::runtime_error("Well fuck!");
    }
    else
    {
      pbool.reset(dynamic_cast<ObjectBoolean *>(pint));
      right = pbool.get();
      if (right == NULL)
      {
        throw std::runtime_error("Well, doubly fuck!");
      }
    }
  }

  return new ObjectBoolean(_value || right->_value);
}


ObjectBoolean *ObjectBoolean::operator_boolean_and(IOperable *right_side)
{
  ObjectBoolean right(dynamic_cast<ObjectBoolean *>(right_side));
  return new ObjectBoolean(_value && right._value);
}


ObjectBoolean *ObjectBoolean::operator_is_equal(IOperable *right_side)
{
  ObjectBoolean right(dynamic_cast<ObjectBoolean *>(right_side));
  return new ObjectBoolean(_value == right._value);
}
