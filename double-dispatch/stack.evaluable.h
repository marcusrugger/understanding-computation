#ifndef __STACK_EVALUABLE_H__
#define __STACK_EVALUABLE_H__

#include <stack>
#include "interface.environment.h"
#include "interface.evaluable.h"
#include "interface.operable.h"
#include "interface.statement.h"
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


class StackEvaluable
{
private:

  std::stack<IEvaluable *> stack;


protected:

  void push(IEvaluable *op)
  { stack.push(op); }

  IEvaluable *pop(void)
  { IEvaluable *rv = stack.top(); stack.pop(); return rv; }


public:

  void new_boolean(bool flag)
  { push(new ObjectBoolean(flag)); }

  void new_integer(int x)
  { push(new ObjectInteger(x)); }

  void new_variable(IEnvironment::map_key name)
  { push(new ObjectVariable(name)); }

  void new_boolean_or(void)
  { push(new OperatorBooleanOr(pop(), pop())); }

  void new_add(void)
  { push(new OperatorAdd(pop(), pop())); }

  void new_multiply(void)
  { push(new OperatorMultiply(pop(), pop())); }

  IStatement *new_statement(void)
  { return new StatementSingle(pop()); }

};


#endif  // __STACK_EVALUABLE_H__
