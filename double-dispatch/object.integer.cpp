#include <cstdio>
#include <memory>
#include <string>
#include "object.integer.h"
#include "object.boolean.h"


ObjectInteger::ObjectInteger(int value)
: _value(value)
{}


ObjectInteger::ObjectInteger(ObjectInteger *pObj)
: _value(pObj->_value)
{}


std::string ObjectInteger::to_string(void)
{
  return std::to_string(_value);
}


bool ObjectInteger::to_boolean(void)
{
  return _value != 0;
}


int ObjectInteger::to_integer(void)
{
  return _value;
}


IOperable *ObjectInteger::evaluate(IEnvironment *)
{
  return clone();
}


IOperable *ObjectInteger::clone(void)
{
  return new ObjectInteger(this);
}


ObjectBoolean *ObjectInteger::as_boolean(void)
{
  return new ObjectBoolean(to_boolean());
}


ObjectInteger *ObjectInteger::as_integer(void)
{
  return new ObjectInteger(this);
}


IOperable *ObjectInteger::operator_boolean_not(void)
{
  std::unique_ptr<ObjectBoolean> operand(as_boolean());
  return operand->operator_boolean_not();
}


IOperable *ObjectInteger::operator_boolean_or(IOperable *right_side)
{
  return right_side->dispatch_boolean_or(to_boolean());
}


IOperable *ObjectInteger::operator_boolean_and(IOperable *right_side)
{
  return right_side->dispatch_boolean_and(to_boolean());
}


IOperable *ObjectInteger::operator_is_equal(IOperable *right_side)
{
  return right_side->dispatch_is_equal(to_integer());
}


IOperable *ObjectInteger::operator_is_less_than(IOperable *right_side)
{
  return right_side->dispatch_is_less_than(to_integer());
}


IOperable *ObjectInteger::operator_is_greater_than(IOperable *right_side)
{
  return right_side->dispatch_is_greater_than(to_integer());
}


IOperable *ObjectInteger::operator_add(IOperable *right_side)
{
  return right_side->dispatch_add(to_integer());
}


IOperable *ObjectInteger::operator_subtract(IOperable *right_side)
{
  return right_side->dispatch_subtract(to_integer());
}


IOperable *ObjectInteger::operator_multiply(IOperable *right_side)
{
  return right_side->dispatch_multiply(to_integer());
}


IOperable *ObjectInteger::operator_divide(IOperable *right_side)
{
  return right_side->dispatch_divide(to_integer());
}


/* dispatchers */

IOperable *ObjectInteger::dispatch_boolean_or(bool left_side)
{
  return new ObjectBoolean(left_side || to_boolean());
}


IOperable *ObjectInteger::dispatch_boolean_and(bool left_side)
{
  return new ObjectBoolean(left_side && to_boolean());
}


IOperable *ObjectInteger::dispatch_is_equal(int left_side)
{
  return new ObjectBoolean(left_side == to_integer());
}


IOperable *ObjectInteger::dispatch_is_less_than(int left_side)
{
  return new ObjectBoolean(left_side < to_integer());
}


IOperable *ObjectInteger::dispatch_is_greater_than(int left_side)
{
  return new ObjectBoolean(left_side > to_integer());
}


IOperable *ObjectInteger::dispatch_add(int left_side)
{
  return new ObjectInteger(left_side + to_integer());
}


IOperable *ObjectInteger::dispatch_subtract(int left_side)
{
  return new ObjectInteger(left_side - to_integer());
}


IOperable *ObjectInteger::dispatch_multiply(int left_side)
{
  return new ObjectInteger(left_side * to_integer());
}


IOperable *ObjectInteger::dispatch_divide(int left_side)
{
  return new ObjectInteger(left_side / to_integer());
}
