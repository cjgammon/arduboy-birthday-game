#ifndef Menu_h
#define Menu_h

#include <Arduboy2.h>

class Menu
{
  public:
  Menu(Arduboy2 arduboy);
  void draw();
  void next();
  void prev();
  int value();
  
  private:
  Arduboy2 _arduboy;
};
#endif
