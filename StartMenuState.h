// StartMenuState.h
#ifndef STARTMENUSTATE_H
#define STARTMENUSTATE_H

#include "GameState.h"

class StartMenuState : public GameState {
public:
    void init() override;
    void update(Arduboy2 &arduboy) override;
    void draw(Arduboy2 &arduboy) override;
};

#endif
