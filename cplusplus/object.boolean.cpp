#include <cstdio>
#include <memory>
#include <stdexcept>
#include "object.boolean.h"


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


ObjectBoolean *ObjectBoolean::as_boolean(void)
{
  return new ObjectBoolean(this);
}


ObjectBoolean *ObjectBoolean::operator_boolean_not(void)
{
  return new ObjectBoolean(!_value);
}


ObjectBoolean *ObjectBoolean::operator_boolean_or(ICastable *right_side)
{
  std::unique_ptr<ObjectBoolean> right(right_side->as_boolean());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectBoolean::operator_boolean_or: incompatible types");
  
  return new ObjectBoolean(_value || right->_value);
}


ObjectBoolean *ObjectBoolean::operator_boolean_and(ICastable *right_side)
{
  std::unique_ptr<ObjectBoolean> right(right_side->as_boolean());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectBoolean::operator_boolean_and: incompatible types");
  
  return new ObjectBoolean(_value && right->_value);
}


ObjectBoolean *ObjectBoolean::operator_is_equal(ICastable *right_side)
{
  std::unique_ptr<ObjectBoolean> right(right_side->as_boolean());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectBoolean::operator_is_equal: incompatible types");

  return new ObjectBoolean(_value == right->_value);
}
