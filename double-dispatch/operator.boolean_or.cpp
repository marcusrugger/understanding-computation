#include <memory>
#include "operator.boolean_or.h"
#include "interface.operable.h"


OperatorBooleanOr::OperatorBooleanOr(IEvaluable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorBooleanOr::evaluate(IEnvironment *env)
{
  std::unique_ptr<IOperable> left_result(_left_operand->evaluate(env));
  std::unique_ptr<IOperable> right_result(_right_operand->evaluate(env));
  return left_result->operator_boolean_or(right_result.get());
}
