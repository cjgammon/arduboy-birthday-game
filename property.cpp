#include "property.h"

Property::Property(String _name, int _max, int _min, float _mid, float _value, float _inc)
{
  name = _name;
  max = _max;
  min = _min;
  mid = _mid;
  value = _value;
  inc = _inc;
}
