#include <cstdio>
#include <memory>

#include "interface.evaluable.h"
#include "interface.operable.h"
#include "interface.object.h"
#include "object.boolean.h"
#include "object.integer.h"
#include "operator.boolean_or.h"
#include "operator.add.h"


void test_integer(void)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_integer(new ObjectInteger(3));
  std::unique_ptr<IEvaluable> y_integer(new ObjectInteger(5));
  std::unique_ptr<IEvaluable> add_expression(new OperatorAdd(x_integer.release(), y_integer.release()));

  std::unique_ptr<IOperable> result(add_expression->evaluate(&env));

  IObject *result_as_object(dynamic_cast<IObject *>(result.get()));
  printf("test_integer: result: %s\n", result_as_object->to_string().c_str());
}


void test_boolean(void)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_boolean(new ObjectBoolean(true));
  std::unique_ptr<IEvaluable> y_boolean(new ObjectBoolean(false));
  std::unique_ptr<IEvaluable> or_expression(new OperatorBooleanOr(x_boolean.release(), y_boolean.release()));

  std::unique_ptr<IOperable> result(or_expression->evaluate(&env));

  IObject *result_as_object(dynamic_cast<IObject *>(result.get()));
  printf("test_boolean: result: %s\n", result_as_object->to_string().c_str());
}


void test_boolean_or_with_integers(void)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_integer(new ObjectInteger(1));
  std::unique_ptr<IEvaluable> y_integer(new ObjectInteger(1));
  std::unique_ptr<IEvaluable> or_expression(new OperatorBooleanOr(x_integer.release(), y_integer.release()));

  std::unique_ptr<IOperable> result(or_expression->evaluate(&env));

  IObject *result_as_object(dynamic_cast<IObject *>(result.get()));
  printf("test_boolean: result: %s\n", result_as_object->to_string().c_str());
}


int main(int argc, char **argv)
{
  printf("Hello world!\n");

  //test_integer();
  //test_boolean();
  test_boolean_or_with_integers();

  printf("Goodbye cruel world.\n");
}
