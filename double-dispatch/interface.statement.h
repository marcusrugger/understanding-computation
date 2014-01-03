#ifndef __ISTATEMENT_H__
#define __ISTATEMENT_H__

#include <string>
#include "interface.evaluable.h"


class IStatement
{
public:

  static const std::string KEY_LAST_RESULT;

  virtual ~IStatement(void) {}

  virtual IEvaluable::environment *execute(IEvaluable::environment *env) = 0;

};


#endif  // __ISTATEMENT_H__
