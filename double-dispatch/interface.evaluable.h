#ifndef __IEVALUATABLE_H__
#define __IEVALUATABLE_H__

#include <map>
#include <string>
#include <memory>

#include "interface.operable.h"


class IEvaluable
{
public:

  typedef std::string environment_key;
  typedef std::map<std::string, std::unique_ptr<IOperable>> environment;

  virtual ~IEvaluable(void) {}

  virtual IOperable *evaluate(environment *env) = 0;

};


#endif  // __IEVALUATABLE_H__
