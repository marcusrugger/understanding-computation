#ifndef __ISTATEMENT_PAIR_H__
#define __ISTATEMENT_PAIR_H__

#include <memory>
#include "interface.statement.h"


class StatementPair : public IStatement
{
private:

  std::unique_ptr<IEvaluable> _first;
  std::unique_ptr<IEvaluable> _second;

public:

  StatementPair(IEvaluable *first, IEvaluable *second) : _first(first), _second(second) {}


public: // IStatement

  virtual IEvaluable::environment *execute(IEvaluable::environment *env)
  {
    (*env)[KEY_LAST_RESULT] = _first->evaluate(env);
    (*env)[KEY_LAST_RESULT] = _second->evaluate(env);
    return env;
  }

};


#endif  // __ISTATEMENT_PAIR_H__
