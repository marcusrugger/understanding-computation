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


int test_add(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorAdd(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_integer();
}


int test_multiply(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorMultiply(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_integer();
}


bool test_boolean_or(bool x, bool y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectBoolean(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectBoolean(y));
  std::unique_ptr<IEvaluable> expression(new OperatorBooleanOr(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_boolean_or(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorBooleanOr(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_boolean_or(bool x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectBoolean(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorBooleanOr(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_boolean_or(int x, bool y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectBoolean(y));
  std::unique_ptr<IEvaluable> expression(new OperatorBooleanOr(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_boolean_and(bool x, bool y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectBoolean(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectBoolean(y));
  std::unique_ptr<IEvaluable> expression(new OperatorBooleanAnd(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_boolean_and(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorBooleanAnd(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_boolean_and(bool x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectBoolean(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorBooleanAnd(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_boolean_and(int x, bool y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectBoolean(y));
  std::unique_ptr<IEvaluable> expression(new OperatorBooleanAnd(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_is_equal(bool x, bool y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectBoolean(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectBoolean(y));
  std::unique_ptr<IEvaluable> expression(new OperatorIsEqual(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_is_equal(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorIsEqual(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_is_less_than(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorIsLessThan(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


bool test_is_greater_than(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));
  std::unique_ptr<IEvaluable> expression(new OperatorIsGreaterThan(x_value.release(), y_value.release()));
  std::unique_ptr<IOperable> result(expression->evaluate(&env));

  return result->to_boolean();
}


int main(int argc, char **argv)
{
  printf("Hello world!\n");

  should_eq(test_add(0, 0), 0, "Add 0 + 0");
  should_eq(test_add(0, 5), 5, "Add 0 + 5");
  should_eq(test_add(3, 0), 3, "Add 3 + 0");
  should_eq(test_add(3, 5), 8, "Add 3 + 5");

  should_eq(test_multiply(0, 0),  0, "Multiply 0 + 0");
  should_eq(test_multiply(0, 5),  0, "Multiply 0 + 5");
  should_eq(test_multiply(3, 0),  0, "Multiply 3 + 0");
  should_eq(test_multiply(3, 5), 15, "Multiply 3 + 5");

  should_eq(test_boolean_or(false, false), false, "boolean or (false, false)");
  should_eq(test_boolean_or(false, true), true, "boolean or (false, true)");
  should_eq(test_boolean_or(true, false), true, "boolean or (true, false)");
  should_eq(test_boolean_or(true, true), true, "boolean or (true, true)");

  should_eq(test_boolean_or(0, 0), false, "boolean or (0, 0)");
  should_eq(test_boolean_or(0, 5), true, "boolean or (0, 5)");
  should_eq(test_boolean_or(3, 0), true, "boolean or (3, 0)");
  should_eq(test_boolean_or(3, 5), true, "boolean or (3, 5)");

  should_eq(test_boolean_or(false, 0), false, "boolean or (false, 0)");
  should_eq(test_boolean_or(false, 5), true, "boolean or (false, 5)");
  should_eq(test_boolean_or(true, 0), true, "boolean or (true, 0)");
  should_eq(test_boolean_or(true, 5), true, "boolean or (true, 5)");

  should_eq(test_boolean_or(0, false), false, "boolean or (0, false)");
  should_eq(test_boolean_or(0, true), true, "boolean or (0, true)");
  should_eq(test_boolean_or(3, false), true, "boolean or (3, false)");
  should_eq(test_boolean_or(3, true), true, "boolean or (3, true)");

  should_eq(test_boolean_and(false, false), false, "boolean and (false, false)");
  should_eq(test_boolean_and(false, true), false, "boolean and (false, true)");
  should_eq(test_boolean_and(true, false), false, "boolean and (true, false)");
  should_eq(test_boolean_and(true, true), true, "boolean and (true, true)");

  should_eq(test_boolean_and(0, 0), false, "boolean and (0, 0)");
  should_eq(test_boolean_and(0, 5), false, "boolean and (0, 5)");
  should_eq(test_boolean_and(3, 0), false, "boolean and (3, 0)");
  should_eq(test_boolean_and(3, 5), true, "boolean and (3, 5)");

  should_eq(test_boolean_and(false, 0), false, "boolean and (false, 0)");
  should_eq(test_boolean_and(false, 5), false, "boolean and (false, 5)");
  should_eq(test_boolean_and(true, 0), false, "boolean and (true, 0)");
  should_eq(test_boolean_and(true, 5), true, "boolean and (true, 5)");

  should_eq(test_boolean_and(0, false), false, "boolean and (0, false)");
  should_eq(test_boolean_and(0, true), false, "boolean and (0, true)");
  should_eq(test_boolean_and(3, false), false, "boolean and (3, false)");
  should_eq(test_boolean_and(3, true), true, "boolean and (3, true)");

  should_eq(test_is_equal(false, false), true, "is equal (false, false)");
  should_eq(test_is_equal(false, true), false, "is equal (false, true)");
  should_eq(test_is_equal(true, false), false, "is equal (true, false)");
  should_eq(test_is_equal(true, true), true, "is equal (true, true)");

  should_eq(test_is_equal(0, 0), true, "is equal (0, 0)");
  should_eq(test_is_equal(0, 5), false, "is equal (0, 5)");
  should_eq(test_is_equal(3, 0), false, "is equal (3, 0)");
  should_eq(test_is_equal(3, 5), false, "is equal (3, 5)");
  should_eq(test_is_equal(3, 3), true, "is equal (3, 3)");
  should_eq(test_is_equal(5, 5), true, "is equal (5, 5)");

  should_eq(test_is_less_than(0, 0), false, "is less than (0, 0)");
  should_eq(test_is_less_than(0, 5), true, "is less than (0, 5)");
  should_eq(test_is_less_than(3, 0), false, "is less than (3, 0)");
  should_eq(test_is_less_than(3, 5), true, "is less than (3, 5)");

  should_eq(test_is_greater_than(0, 0), false, "is greater than (0, 0)");
  should_eq(test_is_greater_than(0, 5), false, "is greater than (0, 5)");
  should_eq(test_is_greater_than(3, 0), true, "is greater than (3, 0)");
  should_eq(test_is_greater_than(3, 5), false, "is greater than (3, 5)");
  should_eq(test_is_greater_than(5, 3), true, "is greater than (5, 3)");

  printf("Goodbye, cruel world.\n");
}
