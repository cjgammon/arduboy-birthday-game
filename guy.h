#ifndef Guy_h
#define Guy_h

#include <Arduboy2.h>
#include "sprites.h"

class Guy
{
  public:
  Guy(Arduboy2 arduboy);
  void draw();
  void update();
  void apply(int action);
  
  private:
  Arduboy2 _arduboy;
  int _mood = 0;
  int _exression;
  void checkMood();
};
#endif
