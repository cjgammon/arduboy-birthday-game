// StartMenuState.h
#ifndef CHARACTERSELECTIONSTATE_H
#define CHARACTERSELECTIONSTATE_H

#include "GameState.h"

class CharacterSelectionState : public GameState {
public:
    void init() override;
    void update(Arduboy2 &arduboy) override;
    void draw(Arduboy2 &arduboy) override;
    void cleanup() override;
};

#endif
