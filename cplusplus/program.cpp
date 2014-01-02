#include <cstdio>
#include <memory>

#include "interface.evaluable.h"
#include "interface.operable.h"
#include "interface.castable.h"
#include "interface.object.h"
#include "object.boolean.h"
#include "object.integer.h"
#include "operator.boolean_or.h"
#include "operator.add.h"


void test_integer(void)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(3));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(5));

  std::unique_ptr<IEvaluable> expression(new OperatorAdd(x_value.release(), y_value.release()));

  std::unique_ptr<IObject> result(dynamic_cast<IObject *>(expression->evaluate(&env)));

  printf("result: %s\n", result->to_string().c_str());
}


void test_boolean(void)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(0));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(0));

  std::unique_ptr<IEvaluable> expression(new OperatorBooleanOr(x_value.release(), y_value.release()));

  std::unique_ptr<IObject> result(dynamic_cast<IObject *>(expression->evaluate(&env)));

  printf("result: %s\n", result->to_string().c_str());
}


int main(int argc, char **argv)
{
  printf("Hello world!\n");

  test_integer();
  test_boolean();

  printf("Goodbye cruel world.\n");
}
