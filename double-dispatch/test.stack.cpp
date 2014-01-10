#include <cstdio>
#include <memory>

#include "stack.evaluable.h"


const IEnvironment::map_key IStatement::KEY_LAST_RESULT = "last_result";


class Tests : public StackEvaluable
{
public:

  void add_integers(int x, int y)
  {
    new_integer(y);
    new_integer(x);
    new_add();
  }

  void add_variables(std::string x, std::string y)
  {
    new_variable(y);
    new_variable(x);
    new_add();
  }

  void test_multiply(void)
  {
    MachineEnvironment env;

    add_integers(2, 3);
    add_integers(5, 7);
    new_multiply();

    std::unique_ptr<IStatement> statement(new_statement());
    statement->execute(&env);

    IOperable *last_result(env.map().at(IStatement::KEY_LAST_RESULT).get());
    printf("last_result: %d\n", last_result->to_integer());
  }

  void x_times_y_plus_z(std::string x, std::string y, std::string z)
  {
    new_variable(z);
    new_variable(y);
    new_variable(x);
    new_multiply();
    new_add();
  }
};


int main(int argc, char **argv)
{
  Tests tests;

  tests.test_multiply();
}