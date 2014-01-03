#include <cstdio>
#include <memory>
#include <stdexcept>
#include "object.variable.h"


ObjectVariable::ObjectVariable(IEvaluable::environment_key name)
: _name(name),
  _environment(NULL)
{}


ObjectVariable::ObjectVariable(ObjectVariable *pobj)
: _name(pobj->_name),
  _environment(pobj->_environment)
{}


IOperable *ObjectVariable::evaluate(environment *env)
{
  _environment = env;
  return clone();
}


IOperable *ObjectVariable::clone(void)
{
  return new ObjectVariable(this);
}


IOperable *ObjectVariable::operator_assign(IOperable *right_side)
{
  (*_environment)[_name].reset(right_side);
  return right_side->clone();
}
