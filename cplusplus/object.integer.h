#ifndef __OBJECTINTEGER_H__
#define __OBJECTINTEGER_H__


#include "implement.operable.h"
#include "implement.castable.h"
#include "interface.evaluable.h"
#include "interface.object.h"


class ObjectInteger : public ImplementCastable,
                      public ImplementOperable,
                      public IEvaluable,
                      public IObject
{
private:

  int _value;


public:

  ObjectInteger(int value);
  ObjectInteger(ObjectInteger *pObj);


public: // IObject

  virtual std::string to_string(void);


public: // IEvaluable

  virtual IOperable *evaluate(environment *env);


public: // ICastable

  virtual ObjectBoolean *as_boolean(void);
  virtual ObjectInteger *as_integer(void);


public: // IOperable

  virtual ObjectBoolean *operator_boolean_not(void);
  virtual ObjectBoolean *operator_boolean_or(ICastable *right_side);
  virtual ObjectBoolean *operator_boolean_and(ICastable *right_side);
  virtual ObjectBoolean *operator_is_equal(ICastable *right_side);
  virtual ObjectBoolean *operator_is_less_than(ICastable *right_side);
  virtual ObjectBoolean *operator_is_greater_than(ICastable *right_side);

  virtual IOperable *operator_add(ICastable *right_side);
  virtual IOperable *operator_subtract(ICastable *right_side);
  virtual IOperable *operator_multiply(ICastable *right_side);
  virtual IOperable *operator_divide(ICastable *right_side);


};


#endif  // __OBJECTINTEGER_H__
