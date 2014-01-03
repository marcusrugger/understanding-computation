#ifndef __OPERATOR_PULL_H__
#define __OPERATOR_PULL_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorPull : public IEvaluable
{
public:

  OperatorPull(void);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


};


#endif  // __OPERATOR_PULL_H__
