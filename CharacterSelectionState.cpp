// CharacterSelectionState.cpp
#include "CharacterSelectionState.h"
#include "sprites.h"

void CharacterSelectionState::init() {
    // Initialization code
}

void CharacterSelectionState::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.pressed(A_BUTTON)) {
        if (stateChangeCallback != nullptr) {
            stateChangeCallback(STATE_START_MENU);
        }
    }
}

void CharacterSelectionState::draw(Arduboy2 &arduboy) {
    // Drawing code
    Sprites::drawOverwrite (0, 0, kid, 0);
}
