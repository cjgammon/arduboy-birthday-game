// GameState_Titlescreen.h
#ifndef CHARACTERSELECTIONSTATE_H
#define CHARACTERSELECTIONSTATE_H

#include "Vars.h"
#include "GameState.h"

class GameState_CharacterSelection : public GameState {
public:
    void init() override;
    void update(Arduboy2 &arduboy) override;
    void draw(Arduboy2 &arduboy) override;
    void cleanup() override;

private:
    void changeCharacter();
};

#endif
