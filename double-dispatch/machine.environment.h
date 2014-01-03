#ifndef __MACHINE_ENVIRONMENT_H__
#define __MACHINE_ENVIRONMENT_H__

#include "interface.environment.h"


class MachineEnvironment : public IEnvironment
{
private:

  IEnvironment::storage_map _map;
  IEnvironment::operand_stack _stack;


public:

  MachineEnvironment(void);


public: // IEnvironment

  virtual storage_map &map(void);
  virtual operand_stack &stack(void);

};


#endif  // __MACHINE_ENVIRONMENT_H__
