// GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <Arduboy2.h>
#include "GameStateID.h"

class GameState {
public:
    virtual void init() = 0;
    virtual void update(Arduboy2 &arduboy) = 0;
    virtual void draw(Arduboy2 &arduboy) = 0;
    virtual void setStateChangeCallback(void (*callback)(GameStateID newState)) {
        stateChangeCallback = callback;
    }
    virtual void cleanup() {} // Add a cleanup method
protected:
    void (*stateChangeCallback)(GameStateID newState);
};



#endif
