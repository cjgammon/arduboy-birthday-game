// GamePlayState.h
#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include "GameState.h"
#include "GameUI.h"

class GamePlayState : public GameState {
public:
    void init() override;
    void update(Arduboy2 &arduboy) override;
    void draw(Arduboy2 &arduboy) override;
    void cleanup() override;
private:
    GameUI gameUI; // Create an instance of the GameUI class 
};



#endif
