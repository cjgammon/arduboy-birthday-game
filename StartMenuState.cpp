// StartMenuState.cpp
#include "StartMenuState.h"
#include "sprites.h"

void StartMenuState::init() {
    // Initialization code
}

void StartMenuState::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.pressed(A_BUTTON)) {
        if (stateChangeCallback != nullptr) {
            stateChangeCallback(STATE_CHARACTER_SELECTION);
        }
    }
}

void StartMenuState::draw(Arduboy2 &arduboy) {
    // Drawing code
      Sprites::drawOverwrite (0, 0, title, 0);
}
