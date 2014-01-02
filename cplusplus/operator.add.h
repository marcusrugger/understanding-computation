#ifndef __OPERATOR_ADD_H__
#define __OPERATOR_ADD_H__

#include "interface.evaluable.h"


class OperatorAdd : public IEvaluable
{
private:

  IEvaluable *_left_operand;
  IEvaluable *_right_operand;
public:

  OperatorAdd(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEvaluable::environment *env);


};


#endif  // __OPERATOR_ADD_H__
