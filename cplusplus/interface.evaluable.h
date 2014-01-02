#ifndef __IEVALUATABLE_H__
#define __IEVALUATABLE_H__

#include <map>
#include <string>

#include "interface.operable.h"


class IEvaluable
{
public:

  typedef std::map<std::string, ICastable *> environment;

  virtual ~IEvaluable(void) {}

  virtual IOperable *evaluate(environment *env) = 0;

};


#endif  // __IEVALUATABLE_H__
