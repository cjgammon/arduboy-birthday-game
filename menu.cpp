
#include <WString.h>
#include "menu.h"

const int menuitemcount = 10;
const String menuitems[menuitemcount] = {"FEED", "PLAY", "PET", "NAP", "JOKE", "TALK", "TEACH", "IGNORE", "VACCINATE", "BATHE"};

int menuY = 55;
int current = 0;

Menu::Menu(Arduboy2 arduboy)
{
  _arduboy = arduboy;
}

void Menu::next()
{
  if (current < menuitemcount - 1) {
    current ++;
  } else {
    current = 0;
  }
}

void Menu::prev()
{
  if (current > 0) {
    current --;
  } else {
    current = menuitemcount - 1;
  }
}

int Menu::value()
{
  return current;
}

void Menu::draw()
{
  _arduboy.fillRect(0, menuY - 3, 128, 1);
  
  int menuX = (128 / 2) - ((menuitems[current].length() * 5) / 2);
  
  _arduboy.setCursor(menuX, menuY);
  _arduboy.print(menuitems[current]);

  //arrows
  _arduboy.fillTriangle(0, menuY + 3, 3, menuY, 3, menuY + 6);
  _arduboy.fillTriangle(127, menuY + 3, 127 - 3, menuY, 127 - 3, menuY + 6);
}
