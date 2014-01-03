#include "machine.environment.h"
#include "interface.operable.h"


MachineEnvironment::MachineEnvironment(void)
{}


MachineEnvironment::storage_map &MachineEnvironment::map(void)
{
  return _map;
}


MachineEnvironment::operand_stack &MachineEnvironment::stack(void)
{
  return _stack;
}
