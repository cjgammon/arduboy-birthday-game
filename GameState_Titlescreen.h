// GameState_Titlescreen.h
#ifndef STARTMENUSTATE_H
#define STARTMENUSTATE_H

#include "GameState.h"

class GameState_Titlescreen : public GameState {
public:
    void init() override;
    void update(Arduboy2 &arduboy) override;
    void draw(Arduboy2 &arduboy) override;
};

#endif
