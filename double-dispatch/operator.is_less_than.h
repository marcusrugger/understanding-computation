#ifndef __OPERATOR_IS_LESS_THAN_H__
#define __OPERATOR_IS_LESS_THAN_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorIsLessThan : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorIsLessThan(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


};


#endif  // __OPERATOR_IS_LESS_THAN_H__
