#ifndef __IMPLEMENT_OPERABLE_H__
#define __IMPLEMENT_OPERABLE_H__


#include "interface.operable.h"
#include <stdexcept>


class ImplementOperable : public IOperable
{
public:

  /* Boolean operators */

  virtual ObjectBoolean *operator_boolean_not(void)
  { throw std::runtime_error("operator_not is not supported"); }

  virtual ObjectBoolean *operator_boolean_or(ICastable *right_side)
  { throw std::runtime_error("operator_boolean_or is not supported"); }

  virtual ObjectBoolean *operator_boolean_and(ICastable *right_side)
  { throw std::runtime_error("operator_boolean_or is not supported"); }

  virtual ObjectBoolean *operator_is_equal(ICastable *right_side)
  { throw std::runtime_error("operator_is_equal is not supported"); }

  virtual ObjectBoolean *operator_is_less_than(ICastable *right_side)
  { throw std::runtime_error("operator_is_less_than is not supported"); }

  virtual ObjectBoolean *operator_is_greater_than(ICastable *right_side)
  { throw std::runtime_error("operator_is_greater_than is not supported"); }


  /* Numeric operators */

  virtual IOperable *operator_add(ICastable *right_side)
  { throw std::runtime_error("operator_add is not supported"); }

  virtual IOperable *operator_subtract(ICastable *right_side)
  { throw std::runtime_error("operator_subtract is not supported"); }

  virtual IOperable *operator_multiply(ICastable *right_side)
  { throw std::runtime_error("operator_multiply is not supported"); }

  virtual IOperable *operator_divide(ICastable *right_side)
  { throw std::runtime_error("operator_divide is not supported"); }

};


#endif  // __IMPLEMENT_OPERABLE_H__
