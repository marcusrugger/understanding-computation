#include <memory>
#include "operator.divide.h"
#include "interface.operable.h"


OperatorDivide::OperatorDivide(IEvaluable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorDivide::evaluate(IEnvironment *env)
{
  std::unique_ptr<IOperable> left_result(_left_operand->evaluate(env));
  std::unique_ptr<IOperable> right_result(_right_operand->evaluate(env));
  return left_result->operator_divide(right_result.get());
}
