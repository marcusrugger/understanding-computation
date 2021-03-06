#ifndef __OBJECTBOOLEAN_H__
#define __OBJECTBOOLEAN_H__


#include "implement.operable.h"
#include "interface.evaluable.h"


class ObjectBoolean : public ImplementOperable
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


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


public: // IOperable

  virtual IOperable *clone(void);

  virtual std::string to_string(void);
  virtual bool to_boolean(void);

  virtual ObjectBoolean *as_boolean(void);

  virtual IOperable *operator_boolean_not(void);
  virtual IOperable *operator_boolean_or(IOperable *right_side);
  virtual IOperable *operator_boolean_and(IOperable *right_side);
  virtual IOperable *operator_is_equal(IOperable *right_side);


protected:  // IOperable dispatchers

  virtual IOperable *dispatch_boolean_or(bool left_side);
  virtual IOperable *dispatch_boolean_and(bool left_side);
  virtual IOperable *dispatch_is_equal(bool left_side);


};


#endif  // __OBJECTBOOLEAN_H__
