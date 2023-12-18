//
// Created by chase on 12/14/23.
//

#ifndef ARDUBOY_BIRTHDAY_GAME_COIN_H
#define ARDUBOY_BIRTHDAY_GAME_COIN_H

#include <Arduboy2.h>

class Coin {
public:
    Coin();
    void init(int segmentX, int localPositionX, int localPositionY);
    //void init(int x, int y);
    void update(int x);
    void draw();
    int x;
    int y;
    float xRaw;
    float yRaw;
    int positionInSegmentX;

    bool enabled;
};


#endif //ARDUBOY_BIRTHDAY_GAME_COIN_H
