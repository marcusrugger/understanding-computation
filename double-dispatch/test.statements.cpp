#include <cstdio>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <iostream>

#include "interface.evaluable.h"
#include "interface.operable.h"
#include "object.boolean.h"
#include "object.integer.h"
#include "operator.boolean_or.h"
#include "operator.boolean_and.h"
#include "operator.is_equal.h"
#include "operator.is_less_than.h"
#include "operator.is_greater_than.h"
#include "operator.add.h"
#include "operator.subtract.h"
#include "operator.multiply.h"
#include "operator.divide.h"
#include "statement.do_nothing.h"
#include "statement.single.h"
#include "statement.pair.h"


const std::string IStatement::KEY_LAST_RESULT = "last_result";


IEvaluable *create_integer(int a)
{
  return new ObjectInteger(a);
}


IEvaluable *create_add(int x, int y)
{
  return new OperatorAdd(create_integer(x), create_integer(y));
}


int main(int argc, char **argv)
{
  printf("Hello world!\n");

  std::unique_ptr<IEvaluable> first_expression(create_add(3, 5));
  std::unique_ptr<IEvaluable> second_expression(create_add(7, 11));
  std::unique_ptr<IStatement> statement(new StatementPair(first_expression.release(), second_expression.release()));

  IEvaluable::environment env;
  IEvaluable::environment *result(statement->execute(&env));

  IOperable *last_result((*result)[IStatement::KEY_LAST_RESULT]);
  printf("last result: %d\n", last_result->to_integer());

  printf("Goodbye, cruel world.\n");
}