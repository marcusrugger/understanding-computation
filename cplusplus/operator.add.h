#ifndef __OPERATOR_ADD_H__
#define __OPERATOR_ADD_H__

#include "interface.evaluable.h"


class OperatorAdd : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorAdd(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEvaluable::environment *env);


};


#endif  // __OPERATOR_ADD_H__
