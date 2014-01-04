#include <memory>
#include "operator.push.h"
#include "interface.operable.h"
#include "interface.environment.h"


OperatorPush::OperatorPush(IEvaluable *operand)
: _operand(operand)
{}


IOperable *OperatorPush::evaluate(IEnvironment *env)
{
  std::unique_ptr<IOperable> operand_result(_operand->evaluate(env));
  env->stack().emplace(operand_result->clone());
  return operand_result.release();
}
