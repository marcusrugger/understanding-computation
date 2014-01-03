#ifndef __ISTATEMENT_WHILE_H__
#define __ISTATEMENT_WHILE_H__

#include <memory>
#include "interface.statement.h"


class StatementWhile : public IStatement
{
private:

  std::unique_ptr<IEvaluable> _condition;
  std::unique_ptr<IStatement> _body;
  

public:

  StatementWhile(IEvaluable *condition, IEvaluable *body_expression)
  : _condition(condition), _body(new StatementSingle(body_expression)) {}

  StatementWhile(IEvaluable *condition, IStatement *body_statement)
  : _condition(condition), _body(body_statement) {}


public: // IStatement

  virtual IEvaluable::environment *execute(IEvaluable::environment *env)
  {
    while (_condition->evaluate(env)->to_boolean())
      _body->execute(env);

    return env;
  }

};


#endif  // __ISTATEMENT_WHILE_H__
