#ifndef __OBJECTINTEGER_H__
#define __OBJECTINTEGER_H__


#include "implement.operable.h"
#include "interface.evaluable.h"


class ObjectInteger : public ImplementOperable,
                      public IEvaluable
{
private:

  int _value;


public:

  ObjectInteger(int value);
  ObjectInteger(ObjectInteger *pObj);


public: // IEvaluable

  virtual IOperable *evaluate(environment *env);


public: // IOperable

  virtual std::string to_string(void);
  virtual bool to_boolean(void);
  virtual int to_integer(void);

  virtual ObjectBoolean *as_boolean(void);
  virtual ObjectInteger *as_integer(void);

  virtual IOperable *operator_boolean_not(void);
  virtual IOperable *operator_boolean_or(IOperable *right_side);
  virtual IOperable *operator_boolean_and(IOperable *right_side);
  virtual IOperable *operator_is_equal(IOperable *right_side);
  virtual IOperable *operator_is_less_than(IOperable *right_side);
  virtual IOperable *operator_is_greater_than(IOperable *right_side);

  virtual IOperable *operator_add(IOperable *right_side);
  virtual IOperable *operator_subtract(IOperable *right_side);
  virtual IOperable *operator_multiply(IOperable *right_side);
  virtual IOperable *operator_divide(IOperable *right_side);


protected:

  virtual IOperable *dispatch_boolean_or(bool left_side);
  virtual IOperable *dispatch_boolean_and(bool left_side);
  virtual IOperable *dispatch_is_equal(int left_side);
  virtual IOperable *dispatch_is_less_than(int left_side);
  virtual IOperable *dispatch_is_greater_than(int left_side);
  virtual IOperable *dispatch_add(int left_side);
  virtual IOperable *dispatch_subtract(int left_side);
  virtual IOperable *dispatch_multiply(int left_side);
  virtual IOperable *dispatch_divide(int left_side);


};


#endif  // __OBJECTINTEGER_H__
