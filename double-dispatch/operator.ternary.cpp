#include <memory>
#include "operator.ternary.h"
#include "interface.operable.h"
#include "interface.environment.h"


OperatorTernary::OperatorTernary(IEvaluable *condition, IEvaluable *true_expression, IEvaluable *false_expression)
: _condition(condition),
  _true_expression(true_expression),
  _false_expression(false_expression)
{}


IOperable *OperatorTernary::evaluate(IEnvironment *env)
{
  if (_condition->evaluate(env)->to_boolean())
    return _true_expression->evaluate(env);
  else
    return _false_expression->evaluate(env);
}
