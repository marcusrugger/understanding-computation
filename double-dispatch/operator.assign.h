#ifndef __OPERATOR_ASSIGN_H__
#define __OPERATOR_ASSIGN_H__

#include <memory>

#include "interface.assignable.h"
#include "interface.evaluable.h"


class OperatorAssign : public IEvaluable
{
private:

  std::unique_ptr<IAssignable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorAssign(IAssignable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


};


#endif  // __OPERATOR_ASSIGN_H__
