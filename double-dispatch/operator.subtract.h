#ifndef __OPERATOR_SUBTRACT_H__
#define __OPERATOR_SUBTRACT_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorSubtract : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorSubtract(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


};


#endif  // __OPERATOR_SUBTRACT_H__
