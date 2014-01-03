#ifndef __ISTATEMENT_H__
#define __ISTATEMENT_H__

#include <string>
#include "interface.environment.h"
#include "interface.evaluable.h"


class IStatement
{
public:

  static const IEnvironment::map_key KEY_LAST_RESULT;

  virtual ~IStatement(void) {}

  virtual IEnvironment *execute(IEnvironment *env) = 0;

};


#endif  // __ISTATEMENT_H__
