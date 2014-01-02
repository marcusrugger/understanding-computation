#include <cstdio>
#include <memory>

#include "interface.evaluable.h"
#include "interface.operable.h"
#include "interface.object.h"
#include "object.boolean.h"
#include "object.integer.h"
#include "operator.add.h"


int main(int argc, char **argv)
{
  printf("Hello world!\n");

  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_integer(new ObjectInteger(3));
  std::unique_ptr<IEvaluable> y_integer(new ObjectInteger(5));
  std::unique_ptr<IEvaluable> add_expression(new OperatorAdd(x_integer.release(), y_integer.release()));

  std::unique_ptr<IOperable> result(add_expression->evaluate(&env));

  IObject *result_as_object(dynamic_cast<IObject *>(result.get()));
  printf("result: %s\n", result_as_object->to_string().c_str());

  printf("Goodbye cruel world.\n");
}
