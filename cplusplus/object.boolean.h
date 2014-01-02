#ifndef __OBJECTBOOLEAN_H__
#define __OBJECTBOOLEAN_H__


#include "implement.operable.h"
#include "implement.castable.h"
#include "interface.evaluable.h"
#include "interface.object.h"


class ObjectBoolean : public ImplementCastable,
                      public ImplementOperable,
                      public IEvaluable,
                      public IObject
{
private:

  bool _value;


public:

  ObjectBoolean(bool value);
  ObjectBoolean(ObjectBoolean *pObj);


  bool is_true(void)
  { return _value; }

  bool is_false(void)
  { return !_value; }


public: // IObject

  virtual std::string to_string(void);


public: // IEvaluable

  virtual IOperable *evaluate(environment *env);


public: // ICastable

  virtual ObjectBoolean *as_boolean(void);


public: // IOperable

  virtual ObjectBoolean *operator_boolean_not(void);
  virtual ObjectBoolean *operator_boolean_or(ICastable *right_side);
  virtual ObjectBoolean *operator_boolean_and(ICastable *right_side);
  virtual ObjectBoolean *operator_is_equal(ICastable *right_side);


};


#endif  // __OBJECTBOOLEAN_H__
