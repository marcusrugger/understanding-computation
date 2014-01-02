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


std::string bool_to_string(bool value)
{
  return value ? "true" : "false";
}


void should_eq(bool test, bool value, std::string description)
{
  if (test != value)
  {
    std::ostringstream ss;
    ss << description << ": was (" << bool_to_string(test) << "), should be (" << bool_to_string(value) << ")";
    throw std::runtime_error(ss.str());
  }
  else
  {
    std::cout << "success: " << description << "\n";
  }
}


void should_eq(int test, int value, std::string description)
{
  if (test != value)
  {
    std::ostringstream ss;
    ss << description << ": was (" << test << "), should be (" << value << ")";
    throw std::runtime_error(ss.str());
  }
  else
  {
    std::cout << "success: " << description << "\n";
  }
}


IEvaluable *create_add(int x, int y)
{
  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  return new OperatorAdd(x_value.release(), y_value.release());
}


IEvaluable *create_complex_add(int a, int b, int c, int d)
{
  std::unique_ptr<IEvaluable> x_expression(create_add(a, b));
  std::unique_ptr<IEvaluable> y_expression(create_add(c, d));
  return new OperatorAdd(x_expression.release(), y_expression.release());
}


int test_integer_expression(IEvaluable *expression)
{
  IEvaluable::environment env;
  std::unique_ptr<IOperable> result(expression->evaluate(&env));
  return result->to_integer();
}


int main(int argc, char **argv)
{
  printf("Hello world!\n");
  std::unique_ptr<IEvaluable> expression;

  expression.reset(create_complex_add(1, 2, 3, 4));
  should_eq(test_integer_expression(expression.get()), 10, "(1 + 2) + (3 + 4)");

  printf("Goodbye, cruel world.\n");
}
