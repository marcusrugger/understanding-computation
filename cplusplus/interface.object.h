#ifndef __IOBJECT_H__
#define __IOBJECT_H__

#include <string>


class IObject
{
public:

  virtual ~IObject(void) {}

  virtual std::string to_string(void) = 0;

};


#endif  // __IOBJECT_H__
