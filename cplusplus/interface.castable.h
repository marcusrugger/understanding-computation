#ifndef __ICASTABLE_H__
#define __ICASTABLE_H__


class ObjectBoolean;
class ObjectInteger;


class ICastable
{
public:

  virtual ~ICastable(void) {}

  virtual ObjectBoolean *as_boolean(void) = 0;
  virtual ObjectInteger *as_integer(void) = 0;

};


#endif  // __ICASTABLE_H__
