#include <cstdio>
#include <memory>
#include <stdexcept>
#include <sstream>
#include <iostream>

#include "interface.evaluable.h"
#include "interface.operable.h"
#include "object.boolean.h"
#include "object.integer.h"
#include "object.variable.h"
#include "operator.assign.h"
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
#include "statement.if.h"
#include "statement.while.h"
#include "machine.environment.h"


const IEnvironment::map_key IStatement::KEY_LAST_RESULT = "last_result";


IEvaluable *create_boolean(bool a)
{
  return new ObjectBoolean(a);
}


IEvaluable *create_integer(int a)
{
  return new ObjectInteger(a);
}


IEvaluable *create_variable(IEnvironment::map_key key)
{
  return new ObjectVariable(key);
}


IEvaluable *create_add(int x, int y)
{
  return new OperatorAdd(create_integer(x), create_integer(y));
}


IEvaluable *create_decrementer(IEnvironment::map_key name)
{
  IEvaluable *subtract_expression;
  {
    IEvaluable *left = new ObjectVariable(name);
    IEvaluable *right = new ObjectInteger(1);
    subtract_expression = new OperatorSubtract(left, right);
  }

  IEvaluable *assign_expression;
  {
    IAssignable *left = new ObjectVariable(name);
    assign_expression = new OperatorAssign(left, subtract_expression);
  }

  IEvaluable *condition;
  {
    IEvaluable *right = new ObjectInteger(0);
    condition = new OperatorIsGreaterThan(assign_expression, right);
  }

  return condition;
}


void test_pair(void)
{
  std::unique_ptr<IEvaluable> first_expression(create_add(3, 5));
  std::unique_ptr<IEvaluable> second_expression(create_add(7, 11));
  std::unique_ptr<IStatement> statement(new StatementPair(first_expression.release(), second_expression.release()));

  MachineEnvironment env;
  IEnvironment *result(statement->execute(&env));

  IOperable *last_result(result->map().at(IStatement::KEY_LAST_RESULT).get());
  printf("test_pair: last result: %d\n", last_result->to_integer());
}


void test_if(bool flag)
{
  std::unique_ptr<IEvaluable> condition(create_boolean(flag));
  std::unique_ptr<IEvaluable> true_expression(create_add(3, 5));
  std::unique_ptr<IEvaluable> false_expression(create_add(7, 11));
  std::unique_ptr<IStatement> statement(new StatementIf(condition.release(), true_expression.release(), false_expression.release()));

  MachineEnvironment env;
  IEnvironment *result(statement->execute(&env));

  IOperable *last_result(result->map().at(IStatement::KEY_LAST_RESULT).get());
  printf("test_if: last result: %d\n", last_result->to_integer());
}


void test_while(int n)
{
  MachineEnvironment env;

  IEnvironment::map_key name("count_down");

  IStatement *while_statement;
  {
    IEvaluable *condition(create_decrementer(name));
    IStatement *body(new StatementDoNothing());
    while_statement = new StatementWhile(condition, body);
  }

  env.map()[name].reset(new ObjectInteger(n));
  while_statement->execute(&env);
}


int main(int argc, char **argv)
{
  printf("Hello world!\n");

  test_pair();
  test_if(true);
  test_if(false);
  test_while(500000);

  printf("Goodbye, cruel world.\n");
}