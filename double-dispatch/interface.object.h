#ifndef __IOBJECT_H__
#define __IOBJECT_H__

#include <string>


class IObject
{
public:

  virtual ~IObject(void) {}

  virtual std::string to_string(void) = 0;
  virtual bool to_boolean(void) = 0;
  virtual int to_integer(void) = 0;

};


#endif  // __IOBJECT_H__
