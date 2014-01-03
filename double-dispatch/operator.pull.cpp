#include <memory>
#include "operator.pull.h"
#include "interface.operable.h"
#include "interface.environment.h"


OperatorPull::OperatorPull(void)
{}


IOperable *OperatorPull::evaluate(IEnvironment *env)
{
  std::unique_ptr<IOperable> rv(env->stack().top()->clone());
  env->stack().pop();
  return rv.release();
}
