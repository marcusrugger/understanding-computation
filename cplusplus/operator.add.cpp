#include <memory>
#include "operator.add.h"
#include "interface.castable.h"


OperatorAdd::OperatorAdd(IEvaluable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorAdd::evaluate(IEvaluable::environment *env)
{
  std::auto_ptr<IOperable> left_result(_left_operand->evaluate(env));
  std::auto_ptr<IOperable> right_result(_right_operand->evaluate(env));
  return left_result->operator_add(dynamic_cast<ICastable *>(right_result.get()));
}
