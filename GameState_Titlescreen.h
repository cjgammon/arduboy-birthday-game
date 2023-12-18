// GameState_Titlescreen.h
#ifndef STARTMENUSTATE_H
#define STARTMENUSTATE_H

#include "Vars.h"
#include "GameState.h"

class GameState_Titlescreen : public GameState {
public:
    void init() override;
    void update() override;
    void draw() override;
};

#endif
