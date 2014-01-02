#ifndef __IMPLEMENT_CASTABLE_H__
#define __IMPLEMENT_CASTABLE_H__


#include "interface.castable.h"
#include <stdexcept>


class ImplementCastable : public ICastable
{
public:

  virtual ObjectBoolean *as_boolean(void)
  { throw std::runtime_error("as_boolean is not supported"); }

  virtual ObjectInteger *as_integer(void)
  { throw std::runtime_error("as_integer is not supported"); }

};


#endif  // __IMPLEMENT_CASTABLE_H__
