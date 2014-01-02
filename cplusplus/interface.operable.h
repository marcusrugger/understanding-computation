#ifndef __IOPERABLE_H__
#define __IOPERABLE_H__


class ObjectBoolean;
class ICastable;


class IOperable
{
public:

  virtual ~IOperable(void) {}

  virtual ObjectBoolean *operator_boolean_not(void) = 0;
  virtual ObjectBoolean *operator_boolean_or(ICastable *right_side) = 0;
  virtual ObjectBoolean *operator_boolean_and(ICastable *right_side) = 0;
  virtual ObjectBoolean *operator_is_equal(ICastable *right_side) = 0;
  virtual ObjectBoolean *operator_is_less_than(ICastable *right_side) = 0;
  virtual ObjectBoolean *operator_is_greater_than(ICastable *right_side) = 0;

  virtual IOperable *operator_add(ICastable *right_side) = 0;
  virtual IOperable *operator_subtract(ICastable *right_side) = 0;
  virtual IOperable *operator_multiply(ICastable *right_side) = 0;
  virtual IOperable *operator_divide(ICastable *right_side) = 0;

};


#endif  // __IOPERABLE_H__
