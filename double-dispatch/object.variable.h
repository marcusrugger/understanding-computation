#ifndef __OBJECTVARIABLE_H__
#define __OBJECTVARIABLE_H__


#include "implement.operable.h"
#include "interface.evaluable.h"


class ObjectVariable : public ImplementOperable,
                       public IEvaluable
{
private:

  IEvaluable::environment_key _name;
  IEvaluable::environment *_environment;


public:

  ObjectVariable(IEvaluable::environment_key name);
  ObjectVariable(ObjectVariable *pObj);


public: // IEvaluable

  virtual IOperable *evaluate(environment *env);


public: // IOperable

  virtual IOperable *clone(void);

  virtual IOperable *operator_assign(IOperable *right_side);

};


#endif  // __OBJECTVARIABLE_H__
