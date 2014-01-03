#ifndef __IEVALUATABLE_H__
#define __IEVALUATABLE_H__


class IOperable;
class IEnvironment;


class IEvaluable
{
public:

  virtual ~IEvaluable(void) {}

  virtual IOperable *evaluate(IEnvironment *env) = 0;

};


#endif  // __IEVALUATABLE_H__
