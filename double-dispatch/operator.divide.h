#ifndef __OPERATOR_DIVIDE_H__
#define __OPERATOR_DIVIDE_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorDivide : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorDivide(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEvaluable::environment *env);


};


#endif  // __OPERATOR_DIVIDE_H__
