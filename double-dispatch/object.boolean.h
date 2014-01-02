#ifndef __OBJECTBOOLEAN_H__
#define __OBJECTBOOLEAN_H__


#include "implement.operable.h"
#include "interface.evaluable.h"
#include "interface.object.h"


class ObjectBoolean : public ImplementOperable,
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
  virtual bool to_boolean(void);
  virtual int to_integer(void);


public: // IEvaluable

  virtual IOperable *evaluate(environment *env);


public: // IOperable

  virtual ObjectBoolean *as_boolean(void);

  virtual ObjectBoolean *operator_boolean_not(void);
  virtual ObjectBoolean *operator_boolean_or(IOperable *right_side);
  virtual ObjectBoolean *operator_boolean_and(IOperable *right_side);
  virtual ObjectBoolean *operator_is_equal(IOperable *right_side);


protected:  // IOperable dispatchers

  virtual ObjectBoolean *dispatch_boolean_or(bool left_side);
  virtual ObjectBoolean *dispatch_boolean_and(bool left_side);
  virtual ObjectBoolean *dispatch_is_equal(bool left_side);


};


#endif  // __OBJECTBOOLEAN_H__
