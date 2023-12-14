//
// Created by chase on 12/14/23.
//

#ifndef ARDUBOY_BIRTHDAY_GAME_COIN_H
#define ARDUBOY_BIRTHDAY_GAME_COIN_H

#include <Arduboy2.h>

class Coin {
public:
    Coin();
    void init(int x, int y);
    void draw(Arduboy2 &arduboy);
    int x;
    int y;
    float xRaw;
    float yRaw;
    int positionInSegmentX;
};


#endif //ARDUBOY_BIRTHDAY_GAME_COIN_H
