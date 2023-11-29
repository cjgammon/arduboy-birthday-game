// GameStateManager.h
#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "GameState.h"

class GameStateManager {
private:
    GameState *currentState;

public:
    void setState(GameState *state);
    void update(Arduboy2 &arduboy);
    void draw(Arduboy2 &arduboy);
};

#endif
