#ifndef __OPERATOR_MULTIPLY_H__
#define __OPERATOR_MULTIPLY_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorMultiply : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorMultiply(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


};


#endif  // __OPERATOR_MULTIPLY_H__
