#ifndef __OPERATOR_TERNARY_H__
#define __OPERATOR_TERNARY_H__

#include <memory>
#include "interface.evaluable.h"


class OperatorTernary : public IEvaluable
{
private:

  std::unique_ptr<IEvaluable> _condition;
  std::unique_ptr<IEvaluable> _true_expression;
  std::unique_ptr<IEvaluable> _false_expression;


public:

  OperatorTernary(IEvaluable *condition, IEvaluable *true_expression, IEvaluable *false_expression);


public: // IEvaluable

  virtual IOperable *evaluate(IEnvironment *env);


};


#endif  // __OPERATOR_TERNARY_H__
