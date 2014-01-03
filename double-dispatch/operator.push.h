#ifndef __OPERATOR_PUSH_H__
#define __OPERATOR_PUSH_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorPush : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _operand;


public:

  OperatorPush(IEvaluable *operand);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


};


#endif  // __OPERATOR_PUSH_H__
