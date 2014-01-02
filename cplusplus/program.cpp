#include <cstdio>
#include <memory>

#include "interface.evaluable.h"
#include "interface.operable.h"
#include "interface.castable.h"
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

  std::unique_ptr<IEvaluable> add_expression(new OperatorAdd(x_integer.get(), y_integer.get()));

  std::unique_ptr<IObject> result(dynamic_cast<IObject *>(add_expression->evaluate(&env)));

  printf("result: %s\n", result->to_string().c_str());

  printf("Goodbye cruel world.\n");
}
