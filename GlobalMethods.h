//
// Created by chase on 12/9/23.
//

#ifndef GLOBALMETHODS_H
#define GLOBALMETHODS_H

#include "sprites.h"

void drawRandomGround(int i, uint8_t x, uint8_t y);

inline void drawRandomGround(int i, int x, int y)
{
  if (i % 23 == 0) {
    Sprites::drawOverwrite(x, y, environmentgroundmiddle_alt4, 0);
  } else if (i % 17 == 0) {
    Sprites::drawOverwrite(x, y, environmentgroundmiddle_alt5, 0);
  } else if (i % 12 == 0) {
    Sprites::drawOverwrite(x, y, environmentgroundmiddle_alt3, 0);
  } else if (i % 8 == 0) {
    Sprites::drawOverwrite(x, y, environmentgroundmiddle_alt2, 0);
  } else if (i % 7 == 0) {
    Sprites::drawOverwrite(x, y, environmentgroundmiddle_alt1, 0);
  } else {
    Sprites::drawOverwrite(x, y, environmentgroundmiddle, 0);
  }
}

#endif //GLOBALMETHODS_H
