#include <memory>
#include "operator.boolean_and.h"


OperatorBooleanAnd::OperatorBooleanAnd(IEvaluable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorBooleanAnd::evaluate(IEvaluable::environment *env)
{
  std::unique_ptr<IOperable> left_result(_left_operand->evaluate(env));
  std::unique_ptr<IOperable> right_result(_right_operand->evaluate(env));
  return left_result->operator_boolean_and(right_result.get());
}
