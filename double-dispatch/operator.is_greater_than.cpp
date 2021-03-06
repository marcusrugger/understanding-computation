#include <memory>
#include "operator.is_greater_than.h"
#include "interface.operable.h"


OperatorIsGreaterThan::OperatorIsGreaterThan(IEvaluable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorIsGreaterThan::evaluate(IEnvironment *env)
{
  std::unique_ptr<IOperable> left_result(_left_operand->evaluate(env));
  std::unique_ptr<IOperable> right_result(_right_operand->evaluate(env));
  return left_result->operator_is_greater_than(right_result.get());
}
