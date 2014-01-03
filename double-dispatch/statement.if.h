#ifndef __ISTATEMENT_IF_H__
#define __ISTATEMENT_IF_H__

#include <memory>
#include "interface.statement.h"


class StatementIf : public IStatement
{
private:

  std::unique_ptr<IEvaluable> _condition;
  std::unique_ptr<IStatement> _true_statement;
  std::unique_ptr<IStatement> _false_statement;
  

public:

  StatementIf(IEvaluable *condition, IEvaluable *true_expression, IEvaluable *false_expression)
  : _condition(condition),
    _true_statement(new StatementSingle(true_expression)),
    _false_statement(new StatementSingle(false_expression))
  {}

  StatementIf(IEvaluable *condition, IStatement *true_statement, IStatement *false_statement)
  : _condition(condition),
    _true_statement(true_statement),
    _false_statement(false_statement)
  {}


public: // IStatement

  virtual IEnvironment *execute(IEnvironment *env)
  {
    if (_condition->evaluate(env)->to_boolean())
      return _true_statement->execute(env);
    else
      return _false_statement->execute(env);
  }

};


#endif  // __ISTATEMENT_IF_H__
