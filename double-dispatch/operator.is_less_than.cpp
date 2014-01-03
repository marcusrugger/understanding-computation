#include <memory>
#include "operator.is_less_than.h"
#include "interface.operable.h"


OperatorIsLessThan::OperatorIsLessThan(IEvaluable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorIsLessThan::evaluate(IEnvironment *env)
{
  std::unique_ptr<IOperable> left_result(_left_operand->evaluate(env));
  std::unique_ptr<IOperable> right_result(_right_operand->evaluate(env));
  return left_result->operator_is_less_than(right_result.get());
}
