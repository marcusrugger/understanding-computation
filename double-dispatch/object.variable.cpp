#include <cstdio>
#include <memory>
#include <stdexcept>
#include "object.variable.h"
#include "interface.operable.h"


ObjectVariable::ObjectVariable(IEnvironment::map_key name)
: _name(name)
{}


ObjectVariable::ObjectVariable(ObjectVariable *pobj)
: _name(pobj->_name)
{}


IOperable *ObjectVariable::evaluate(IEnvironment *env)
{
  return env->map().at(_name)->clone();
}


IOperable *ObjectVariable::operator_assign(IEnvironment *env, IOperable *right_side)
{
  env->map()[_name].reset(right_side->clone());
  return right_side->clone();
}
