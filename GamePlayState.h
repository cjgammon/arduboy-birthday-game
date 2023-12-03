// GamePlayState.h
#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include "GameState.h"

class GamePlayState : public GameState {
public:
    void init() override;
    void update(Arduboy2 &arduboy) override;
    void draw(Arduboy2 &arduboy) override;
    void cleanup() override;
};

#endif
