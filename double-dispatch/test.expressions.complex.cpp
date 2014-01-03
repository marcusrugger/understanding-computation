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
#include "operator.multiply.h"


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


IEvaluable *create_boolean(bool a)
{
  return new ObjectBoolean(a);
}


IEvaluable *create_integer(int a)
{
  return new ObjectInteger(a);
}


IEvaluable *create_or(bool x, bool y)
{
  return new OperatorBooleanOr(create_boolean(x), create_boolean(y));
}


IEvaluable *create_and(bool x, bool y)
{
  return new OperatorBooleanAnd(create_boolean(x), create_boolean(y));
}


IEvaluable *create_complex_or(bool a, bool b, bool c, bool d)
{
  return new OperatorBooleanOr(create_and(a, b), create_and(c, d));
}


IEvaluable *create_complex_and(bool a, bool b, bool c, bool d)
{
  return new OperatorBooleanAnd(create_or(a, b), create_or(c, d));
}


IEvaluable *create_add(int x, int y)
{
  return new OperatorAdd(create_integer(x), create_integer(y));
}


IEvaluable *create_multiply(int x, int y)
{
  return new OperatorMultiply(create_integer(x), create_integer(y));
}


IEvaluable *create_complex_add(int a, int b, int c, int d)
{
  return new OperatorAdd(create_multiply(a, b), create_multiply(c, d));
}


IEvaluable *create_complex_multiply(int a, int b, int c, int d)
{
  return new OperatorMultiply(create_add(a, b), create_add(c, d));
}


bool test_boolean_expression(IEvaluable *expression)
{
  IEvaluable::environment env;
  std::unique_ptr<IOperable> result(expression->evaluate(&env));
  return result->to_boolean();
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

  expression.reset(create_complex_multiply(1, 2, 3, 4));
  should_eq(test_integer_expression(expression.get()), 21, "(1 + 2) * (3 + 4)");

  expression.reset(create_complex_add(1, 2, 3, 4));
  should_eq(test_integer_expression(expression.get()), 14, "(1 * 2) + (3 * 4)");

  expression.reset(create_complex_or(true, false, false, true));
  should_eq(test_boolean_expression(expression.get()), false, "(true && false) || (false && true)");

  expression.reset(create_complex_and(true, false, false, true));
  should_eq(test_boolean_expression(expression.get()), true, "(true || false) && (false || true)");

  printf("Goodbye, cruel world.\n");
}
