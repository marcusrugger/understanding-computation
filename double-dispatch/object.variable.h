#ifndef __OBJECTVARIABLE_H__
#define __OBJECTVARIABLE_H__


#include "interface.assignable.h"
#include "interface.evaluable.h"
#include "interface.environment.h"


class ObjectVariable : public IAssignable,
                       public IEvaluable
{
private:

  IEnvironment::map_key _name;


public:

  ObjectVariable(IEnvironment::map_key name);
  ObjectVariable(ObjectVariable *pObj);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


public: // IAssignable

  virtual IOperable *operator_assign(IEnvironment *env, IOperable *right_side);

};


#endif  // __OBJECTVARIABLE_H__
