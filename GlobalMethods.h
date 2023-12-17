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


void saveHighScore(int addr, int highScore);

inline void saveHighScore(int addr, int highScore) {
    byte checksum = (byte)(highScore & 0xFF) ^ (byte)((highScore >> 8) & 0xFF);
    EEPROM.put(addr, highScore);
    EEPROM.write(addr + sizeof(highScore), checksum);
}

int loadHighScore(int addr, int highScore);

inline int loadHighScore(int addr, int highScore) {
    EEPROM.get(addr, highScore);
    byte checksum = EEPROM.read(addr + sizeof(highScore));
    byte calculatedChecksum = (byte)(highScore & 0xFF) ^ (byte)((highScore >> 8) & 0xFF);

    if (checksum != calculatedChecksum) {
        highScore = 0; // Reset to default value or handle accordingly
    }
    return highScore;
}


#endif //GLOBALMETHODS_H
