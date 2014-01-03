#ifndef __OPERATOR_ASSIGN_H__
#define __OPERATOR_ASSIGN_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorAssign : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorAssign(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEvaluable::environment *env);


};


#endif  // __OPERATOR_ASSIGN_H__
