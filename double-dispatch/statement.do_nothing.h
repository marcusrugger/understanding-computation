#ifndef __ISTATEMENT_DO_NOTHING_H__
#define __ISTATEMENT_DO_NOTHING_H__

#include "interface.statement.h"


class StatementDoNothing : public IStatement
{
public:

  StatementDoNothing(void) {}


public: // IStatement

  virtual IEnvironment *execute(IEnvironment *env)
  { return env; }

};


#endif  // __ISTATEMENT_DO_NOTHING_H__
