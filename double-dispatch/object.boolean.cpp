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


bool ObjectBoolean::to_boolean(void)
{
  return _value;
}


int ObjectBoolean::to_integer(void)
{
  return 0;
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


ObjectBoolean *ObjectBoolean::operator_boolean_or(IOperable *right_side)
{
  return right_side->dispatch_boolean_or(to_boolean());
}


ObjectBoolean *ObjectBoolean::operator_boolean_and(IOperable *right_side)
{
  return right_side->dispatch_boolean_and(to_boolean());
}


ObjectBoolean *ObjectBoolean::operator_is_equal(IOperable *right_side)
{
  return right_side->dispatch_is_equal(to_boolean());
}


/* dispatchers */

ObjectBoolean *ObjectBoolean::dispatch_boolean_or(bool left_side)
{
  return new ObjectBoolean(left_side || to_boolean());
}


ObjectBoolean *ObjectBoolean::dispatch_boolean_and(bool left_side)
{
  return new ObjectBoolean(left_side && to_boolean());
}


ObjectBoolean *ObjectBoolean::dispatch_is_equal(bool left_side)
{
  return new ObjectBoolean(left_side && to_boolean());
}
