#include <memory>
#include "operator.subtract.h"


OperatorSubtract::OperatorSubtract(IEvaluable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorSubtract::evaluate(IEvaluable::environment *env)
{
  std::unique_ptr<IOperable> left_result(_left_operand->evaluate(env));
  std::unique_ptr<IOperable> right_result(_right_operand->evaluate(env));
  return left_result->operator_subtract(right_result.get());
}
