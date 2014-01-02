#ifndef __OPERATOR_IS_GREATER_THAN_H__
#define __OPERATOR_IS_GREATER_THAN_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorIsGreaterThan : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorIsGreaterThan(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEvaluable::environment *env);


};


#endif  // __OPERATOR_IS_GREATER_THAN_H__
