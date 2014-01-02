#ifndef __IOPERABLE_H__
#define __IOPERABLE_H__


class ObjectBoolean;
class ICastable;


class IOperable
{
public:

  virtual ~IOperable(void) {}

  virtual ObjectBoolean *operator_boolean_not(void) = 0;
  virtual ObjectBoolean *operator_boolean_or(IOperable *right_side) = 0;
  virtual ObjectBoolean *operator_boolean_and(IOperable *right_side) = 0;
  virtual ObjectBoolean *operator_is_equal(IOperable *right_side) = 0;
  virtual ObjectBoolean *operator_is_less_than(IOperable *right_side) = 0;
  virtual ObjectBoolean *operator_is_greater_than(IOperable *right_side) = 0;

  virtual IOperable *operator_add(IOperable *right_side) = 0;
  virtual IOperable *operator_subtract(IOperable *right_side) = 0;
  virtual IOperable *operator_multiply(IOperable *right_side) = 0;
  virtual IOperable *operator_divide(IOperable *right_side) = 0;

};


#endif  // __IOPERABLE_H__
