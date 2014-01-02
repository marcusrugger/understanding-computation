#ifndef __IMPLEMENT_OPERABLE_H__
#define __IMPLEMENT_OPERABLE_H__


#include "interface.operable.h"
#include <stdexcept>


class ImplementOperable : public IOperable
{
public:

  /* To primitives */

  virtual std::string to_string(void)
  { throw std::runtime_error("to_string is not supported"); }

  virtual bool to_boolean(void)
  { throw std::runtime_error("to_booolean is not supported"); }

  virtual int to_integer(void)
  { throw std::runtime_error("to_integer is not supported"); }


  /* Converters */

  virtual ObjectBoolean *as_boolean(void)
  { return (ObjectBoolean *) NULL; }

  virtual ObjectInteger *as_integer(void)
  { return (ObjectInteger *) NULL; }


  /* IOperable operators */

  virtual IOperable *operator_boolean_not(void)
  { throw std::runtime_error("operator_not is not supported"); }

  virtual IOperable *operator_boolean_or(IOperable *right_side)
  { throw std::runtime_error("operator_boolean_or is not supported"); }

  virtual IOperable *operator_boolean_and(IOperable *right_side)
  { throw std::runtime_error("operator_boolean_or is not supported"); }

  virtual IOperable *operator_is_equal(IOperable *right_side)
  { throw std::runtime_error("operator_is_equal is not supported"); }

  virtual IOperable *operator_is_less_than(IOperable *right_side)
  { throw std::runtime_error("operator_is_less_than is not supported"); }

  virtual IOperable *operator_is_greater_than(IOperable *right_side)
  { throw std::runtime_error("operator_is_greater_than is not supported"); }

  virtual IOperable *operator_add(IOperable *right_side)
  { throw std::runtime_error("operator_add is not supported"); }

  virtual IOperable *operator_subtract(IOperable *right_side)
  { throw std::runtime_error("operator_subtract is not supported"); }

  virtual IOperable *operator_multiply(IOperable *right_side)
  { throw std::runtime_error("operator_multiply is not supported"); }

  virtual IOperable *operator_divide(IOperable *right_side)
  { throw std::runtime_error("operator_divide is not supported"); }


protected:

  /* bool operators */

  virtual IOperable *dispatch_boolean_or(bool left_side)
  { throw std::runtime_error("dispatch_boolean_or is not supported"); }

  virtual IOperable *dispatch_boolean_and(bool left_side)
  { throw std::runtime_error("dispatch_boolean_or is not supported"); }

  virtual IOperable *dispatch_is_equal(bool left_side)
  { throw std::runtime_error("dispatch_is_equal is not supported"); }

  virtual IOperable *dispatch_is_less_than(bool left_side)
  { throw std::runtime_error("dispatch_is_less_than is not supported"); }

  virtual IOperable *dispatch_is_greater_than(bool left_side)
  { throw std::runtime_error("dispatch_is_greater_than is not supported"); }

  virtual IOperable *dispatch_add(bool left_side)
  { throw std::runtime_error("dispatch_add is not supported"); }

  virtual IOperable *dispatch_subtract(bool left_side)
  { throw std::runtime_error("dispatch_subtract is not supported"); }

  virtual IOperable *dispatch_multiply(bool left_side)
  { throw std::runtime_error("dispatch_multiply is not supported"); }

  virtual IOperable *dispatch_divide(bool left_side)
  { throw std::runtime_error("dispatch_divide is not supported"); }


  /* integer operators */

  virtual IOperable *dispatch_is_equal(int left_side)
  { throw std::runtime_error("dispatch_is_equal is not supported"); }

  virtual IOperable *dispatch_is_less_than(int left_side)
  { throw std::runtime_error("dispatch_is_less_than is not supported"); }

  virtual IOperable *dispatch_is_greater_than(int left_side)
  { throw std::runtime_error("dispatch_is_greater_than is not supported"); }

  virtual IOperable *dispatch_add(int left_side)
  { throw std::runtime_error("dispatch_add is not supported"); }

  virtual IOperable *dispatch_subtract(int left_side)
  { throw std::runtime_error("dispatch_subtract is not supported"); }

  virtual IOperable *dispatch_multiply(int left_side)
  { throw std::runtime_error("dispatch_multiply is not supported"); }

  virtual IOperable *dispatch_divide(int left_side)
  { throw std::runtime_error("dispatch_divide is not supported"); }

};


#endif  // __IMPLEMENT_OPERABLE_H__
