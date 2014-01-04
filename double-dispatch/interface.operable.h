#ifndef __IOPERABLE_H__
#define __IOPERABLE_H__


#include "interface.evaluable.h"


class ObjectBoolean;
class ObjectInteger;


class IOperable : public IEvaluable
{
public:

  virtual ~IOperable(void) {}

  virtual IOperable *clone(void) = 0;

  /* To primitives */

  virtual std::string to_string(void) = 0;
  virtual bool to_boolean(void) = 0;
  virtual int to_integer(void) = 0;


  /* Converters */

  virtual ObjectBoolean *as_boolean(void) = 0;
  virtual ObjectInteger *as_integer(void) = 0;


  /* Operator */

  virtual IOperable *operator_boolean_not(void) = 0;
  virtual IOperable *operator_boolean_or(IOperable *right_side) = 0;
  virtual IOperable *operator_boolean_and(IOperable *right_side) = 0;
  virtual IOperable *operator_is_equal(IOperable *right_side) = 0;
  virtual IOperable *operator_is_less_than(IOperable *right_side) = 0;
  virtual IOperable *operator_is_greater_than(IOperable *right_side) = 0;
  virtual IOperable *operator_add(IOperable *right_side) = 0;
  virtual IOperable *operator_subtract(IOperable *right_side) = 0;
  virtual IOperable *operator_multiply(IOperable *right_side) = 0;
  virtual IOperable *operator_divide(IOperable *right_side) = 0;


protected:

  friend class ObjectBoolean;
  friend class ObjectInteger;

  /* bool dispatchers */

  virtual IOperable *dispatch_boolean_or(bool left_side) = 0;
  virtual IOperable *dispatch_boolean_and(bool left_side) = 0;
  virtual IOperable *dispatch_is_equal(bool left_side) = 0;


  /* integer dispatchers */

  virtual IOperable *dispatch_is_equal(int left_side) = 0;
  virtual IOperable *dispatch_is_less_than(int left_side) = 0;
  virtual IOperable *dispatch_is_greater_than(int left_side) = 0;
  virtual IOperable *dispatch_add(int left_side) = 0;
  virtual IOperable *dispatch_subtract(int left_side) = 0;
  virtual IOperable *dispatch_multiply(int left_side) = 0;
  virtual IOperable *dispatch_divide(int left_side) = 0;

};


#endif  // __IOPERABLE_H__
