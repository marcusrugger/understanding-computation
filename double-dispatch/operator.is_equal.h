#ifndef __OPERATOR_IS_EQUAL_H__
#define __OPERATOR_IS_EQUAL_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorIsEqual : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _left_operand;
  std::unique_ptr<IEvaluable> _right_operand;


public:

  OperatorIsEqual(IEvaluable *left, IEvaluable *right);


public: // IEvaluable

  virtual IOperable *evaluate(IEvaluable::environment *env);


};


#endif  // __OPERATOR_IS_EQUAL_H__
