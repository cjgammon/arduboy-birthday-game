// GameState_Titlescreen.h
#ifndef CHARACTERSELECTIONSTATE_H
#define CHARACTERSELECTIONSTATE_H

#include "sprites.h"
#include "Vars.h"
#include "GameState.h"
#include "Character.h"

class GameState_CharacterSelection : public GameState {
public:
    void init() override;
    void update() override;
    void draw() override;
    void cleanup() override;

private:
    void changeCharacter(uint8_t newIndex);
};

#endif
