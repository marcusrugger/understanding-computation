#ifndef __IMPLEMENT_OPERABLE_H__
#define __IMPLEMENT_OPERABLE_H__


#include "interface.operable.h"
#include <stdexcept>


class ImplementOperable : public IOperable
{
public:

  /* Converters */

  virtual ObjectBoolean *as_boolean(void)
  { return (ObjectBoolean *) NULL; }

  virtual ObjectInteger *as_integer(void)
  { return (ObjectInteger *) NULL; }


  /* Operators */

  virtual ObjectBoolean *operator_boolean_not(void)
  { throw std::runtime_error("operator_not is not supported"); }

  virtual ObjectBoolean *operator_boolean_or(IOperable *right_side)
  { throw std::runtime_error("operator_boolean_or is not supported"); }

  virtual ObjectBoolean *operator_boolean_and(IOperable *right_side)
  { throw std::runtime_error("operator_boolean_or is not supported"); }

  virtual ObjectBoolean *operator_is_equal(IOperable *right_side)
  { throw std::runtime_error("operator_is_equal is not supported"); }

  virtual ObjectBoolean *operator_is_less_than(IOperable *right_side)
  { throw std::runtime_error("operator_is_less_than is not supported"); }

  virtual ObjectBoolean *operator_is_greater_than(IOperable *right_side)
  { throw std::runtime_error("operator_is_greater_than is not supported"); }

  virtual IOperable *operator_add(IOperable *right_side)
  { throw std::runtime_error("operator_add is not supported"); }

  virtual IOperable *operator_subtract(IOperable *right_side)
  { throw std::runtime_error("operator_subtract is not supported"); }

  virtual IOperable *operator_multiply(IOperable *right_side)
  { throw std::runtime_error("operator_multiply is not supported"); }

  virtual IOperable *operator_divide(IOperable *right_side)
  { throw std::runtime_error("operator_divide is not supported"); }

};


#endif  // __IMPLEMENT_OPERABLE_H__
