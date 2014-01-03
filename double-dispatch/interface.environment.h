#ifndef __IENVIRONMENT_H__
#define __IENVIRONMENT_H__

#include <string>
#include <map>
#include <stack>
#include <memory>


class IOperable;


class IEnvironment
{
public:

  virtual ~IEnvironment(void) {}


  typedef std::string map_key;
  typedef std::map<std::string, std::unique_ptr<IOperable>> storage_map;

  virtual storage_map &map(void) = 0;


  typedef std::stack<std::unique_ptr<IOperable>> operand_stack;

  virtual operand_stack &stack(void) = 0;

};


#endif  // __IENVIRONMENT_H__
