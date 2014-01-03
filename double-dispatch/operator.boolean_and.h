#ifndef __OPERATOR_BOOLEAN_AND_H__
#define __OPERATOR_BOOLEAN_AND_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorBooleanAnd : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorBooleanAnd(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


};


#endif  // __OPERATOR_BOOLEAN_AND_H__
