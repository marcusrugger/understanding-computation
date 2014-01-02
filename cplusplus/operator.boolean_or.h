#ifndef __OPERATOR_BOOLEAN_OR_H__
#define __OPERATOR_BOOLEAN_OR_H__

#include "interface.evaluable.h"


class OperatorBooleanOr : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorBooleanOr(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEvaluable::environment *env);


};


#endif  // __OPERATOR_BOOLEAN_OR_H__
