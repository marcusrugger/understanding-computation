#include <memory>
#include "operator.assign.h"
#include "interface.operable.h"


OperatorAssign::OperatorAssign(IAssignable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorAssign::evaluate(IEnvironment *env)
{
  std::unique_ptr<IOperable> right_result(_right_operand->evaluate(env));
  return _left_operand->operator_assign(env, right_result.get());
}
