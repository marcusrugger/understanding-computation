#ifndef __IASSIGNABLE_H__
#define __IASSIGNABLE_H__


class IOperable;
class IEnvironment;


class IAssignable
{
public:

  virtual ~IAssignable(void) {}

  virtual IOperable *operator_assign(IEnvironment *env, IOperable *right_side) = 0;

};


#endif  // __IASSIGNABLE_H__
