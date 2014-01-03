#ifndef __ISTATEMENT_PAIR_H__
#define __ISTATEMENT_PAIR_H__

#include <memory>
#include "interface.statement.h"


class StatementPair : public IStatement
{
private:

  std::unique_ptr<IStatement> _first_statement;
  std::unique_ptr<IStatement> _second_statement;
  

public:

  StatementPair(IEvaluable *first, IEvaluable *second)
  : _first_statement(new StatementSingle(first)), _second_statement(new StatementSingle(second))
  {}

  StatementPair(IStatement *first, IStatement *second)
  : _first_statement(first), _second_statement(second)
  {}


public: // IStatement

  virtual IEnvironment *execute(IEnvironment *env)
  {
    return _second_statement->execute(_first_statement->execute(env));
  }

};


#endif  // __ISTATEMENT_PAIR_H__
