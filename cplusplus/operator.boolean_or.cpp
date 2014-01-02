#include <memory>
#include "object.boolean.h"
#include "operator.boolean_or.h"
#include "interface.castable.h"


OperatorBooleanOr::OperatorBooleanOr(IEvaluable *left, IEvaluable *right)
: _left_operand(left),
  _right_operand(right)
{}


IOperable *OperatorBooleanOr::evaluate(IEvaluable::environment *env)
{
  std::unique_ptr<IOperable> left_result(_left_operand->evaluate(env));
  std::unique_ptr<IOperable> right_result(_right_operand->evaluate(env));

  ICastable *right_castable(dynamic_cast<ICastable *>(right_result.get()));
  ObjectBoolean *result(left_result->operator_boolean_or(right_castable));

  return dynamic_cast<IOperable *>(result);
}
