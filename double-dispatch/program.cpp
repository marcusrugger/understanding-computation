#include <cstdio>
#include <memory>
#include <stdexcept>
#include <sstream>

#include "interface.evaluable.h"
#include "interface.operable.h"
#include "interface.object.h"
#include "object.boolean.h"
#include "object.integer.h"
#include "operator.boolean_or.h"
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
}


void should_eq(int test, int value, std::string description)
{
  if (test != value)
  {
    std::ostringstream ss;
    ss << description << ": was (" << test << "), should be (" << value << ")";
    throw std::runtime_error(ss.str());
  }
}


int test_add_with_integers(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));

  std::unique_ptr<IEvaluable> expression(new OperatorAdd(x_value.release(), y_value.release()));

  std::unique_ptr<IObject> result(dynamic_cast<IObject *>(expression->evaluate(&env)));

  printf("test_add_with_integers: %s\n", result->to_string().c_str());
  return result->to_integer();
}


bool test_boolean_or(bool x, bool y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectBoolean(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectBoolean(y));

  std::unique_ptr<IEvaluable> expression(new OperatorBooleanOr(x_value.release(), y_value.release()));

  std::unique_ptr<IObject> result(dynamic_cast<IObject *>(expression->evaluate(&env)));

  printf("test_boolean_or: %s\n", result->to_string().c_str());
  return result->to_boolean();
}


bool test_boolean_or_with_integers(int x, int y)
{
  IEvaluable::environment env;

  std::unique_ptr<IEvaluable> x_value(new ObjectInteger(x));
  std::unique_ptr<IEvaluable> y_value(new ObjectInteger(y));

  std::unique_ptr<IEvaluable> expression(new OperatorBooleanOr(x_value.release(), y_value.release()));

  std::unique_ptr<IObject> result(dynamic_cast<IObject *>(expression->evaluate(&env)));

  printf("test_boolean_or_with_integers: %s\n", result->to_string().c_str());
  return result->to_boolean();
}


int main(int argc, char **argv)
{
  printf("Hello world!\n");

  should_eq(test_add_with_integers(0, 0), 0, "Add 0 + 0");
  should_eq(test_add_with_integers(0, 5), 5, "Add 0 + 5");
  should_eq(test_add_with_integers(3, 0), 3, "Add 3 + 0");
  should_eq(test_add_with_integers(3, 5), 8, "Add 3 + 5");

  should_eq(test_boolean_or(false, false), false, "boolean or (false, false)");
  should_eq(test_boolean_or(false, true), true, "boolean or (false, true)");
  should_eq(test_boolean_or(true, false), true, "boolean or (true, false)");
  should_eq(test_boolean_or(true, true), true, "boolean or (true, true)");

  should_eq(test_boolean_or_with_integers(0, 0), false, "boolean or with integers (0, 0)");
  should_eq(test_boolean_or_with_integers(0, 5), true, "boolean or with integers (0, 5)");
  should_eq(test_boolean_or_with_integers(3, 0), true, "boolean or with integers (3, 0)");
  should_eq(test_boolean_or_with_integers(3, 5), true, "boolean or with integers (3, 5)");

  printf("Goodbye cruel world.\n");
}
