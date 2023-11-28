#ifndef Property_h
#define Property_h

#include <WString.h>


class Property
{
  public:
  Property(String _name, int _max, int _min, float mid, float _value, float _inc);
  String name;
  int max;
  int min;
  float mid;
  float value;
  float inc;
  
  private:
};
#endif
