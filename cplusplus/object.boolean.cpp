#include <cstdio>
#include <memory>
#include "object.boolean.h"


ObjectBoolean::ObjectBoolean(bool value)
: _value(value)
{}


ObjectBoolean::ObjectBoolean(ObjectBoolean *pObj)
: _value(pObj->_value)
{}


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
  ObjectBoolean right(dynamic_cast<ObjectBoolean *>(right_side));
  return new ObjectBoolean(_value || right._value);
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
