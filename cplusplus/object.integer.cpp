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


IOperable *ObjectInteger::evaluate(environment *env)
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


ObjectBoolean *ObjectInteger::operator_boolean_not(void)
{
  std::unique_ptr<ObjectBoolean> operand(as_boolean());
  return operand->operator_boolean_not();
}


ObjectBoolean *ObjectInteger::operator_boolean_or(IOperable *right_side)
{
  std::unique_ptr<ObjectBoolean> left(as_boolean());
  return left->operator_boolean_or(right_side);
}


ObjectBoolean *ObjectInteger::operator_boolean_and(IOperable *right_side)
{
  std::unique_ptr<ObjectBoolean> left(as_boolean());
  return left->operator_boolean_and(right_side);
}


ObjectBoolean *ObjectInteger::operator_is_equal(IOperable *right_side)
{
  std::unique_ptr<ObjectInteger> right(right_side->as_integer());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectInteger::operator_is_equal: incompatible types");
  
  return new ObjectBoolean(_value == right->_value);
}


ObjectBoolean *ObjectInteger::operator_is_less_than(IOperable *right_side)
{
  std::unique_ptr<ObjectInteger> right(right_side->as_integer());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectInteger::operator_is_less_than: incompatible types");
  
  return new ObjectBoolean(_value < right->_value);
}


ObjectBoolean *ObjectInteger::operator_is_greater_than(IOperable *right_side)
{
  std::unique_ptr<ObjectInteger> right(right_side->as_integer());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectInteger::operator_is_greater_than: incompatible types");
  
  return new ObjectBoolean(_value > right->_value);
}


IOperable *ObjectInteger::operator_add(IOperable *right_side)
{
  std::unique_ptr<ObjectInteger> right(right_side->as_integer());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectInteger::operator_add: incompatible types");
  
  return new ObjectInteger(_value + right->_value);
}


IOperable *ObjectInteger::operator_subtract(IOperable *right_side)
{
  std::unique_ptr<ObjectInteger> right(right_side->as_integer());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectInteger::operator_subtract: incompatible types");
  
  return new ObjectInteger(_value - right->_value);
}


IOperable *ObjectInteger::operator_multiply(IOperable *right_side)
{
  std::unique_ptr<ObjectInteger> right(right_side->as_integer());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectInteger::operator_multiply: incompatible types");
  
  return new ObjectInteger(_value * right->_value);
}


IOperable *ObjectInteger::operator_divide(IOperable *right_side)
{
  std::unique_ptr<ObjectInteger> right(right_side->as_integer());
  if (right.get() == NULL)
    throw std::runtime_error("ObjectInteger::operator_divide: incompatible types");
  
  return new ObjectInteger(_value / right->_value);
}
