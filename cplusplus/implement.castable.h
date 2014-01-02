#ifndef __IMPLEMENT_CASTABLE_H__
#define __IMPLEMENT_CASTABLE_H__


#include "interface.castable.h"
#include <stdexcept>


class ImplementCastable : public ICastable
{
public:

  virtual ObjectBoolean *as_boolean(void)
  { return (ObjectBoolean *) NULL; }

  virtual ObjectInteger *as_integer(void)
  { return (ObjectInteger *) NULL; }

};


#endif  // __IMPLEMENT_CASTABLE_H__
