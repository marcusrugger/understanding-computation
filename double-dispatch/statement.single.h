#ifndef __ISTATEMENT_SINGLE_H__
#define __ISTATEMENT_SINGLE_H__

#include <memory>
#include "interface.statement.h"


class StatementSingle : public IStatement
{
private:

  std::unique_ptr<IEvaluable> _expression;

public:

  StatementSingle(IEvaluable *expression) : _expression(expression) {}


public: // IStatement

  virtual IEvaluable::environment *execute(IEvaluable::environment *env)
  {
    (*env)[KEY_LAST_RESULT] = _expression->evaluate(env);
    return env;
  }

};


#endif  // __ISTATEMENT_SINGLE_H__
