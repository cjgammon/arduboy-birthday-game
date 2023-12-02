// CharacterSelectionState.cpp
#include "CharacterSelectionState.h"
#include "sprites.h"
#include "Character.h"

Character* playerCharacter; // Declare a pointer to a character object


void CharacterSelectionState::init() {
    // Initialization code
    
    // Create an instance of MyCharacter
    playerCharacter = new Character(0, 20);
    playerCharacter->init(character0idle, 2, 10);
}

void CharacterSelectionState::update(Arduboy2 &arduboy) {
    // Update logic
    
    if (arduboy.justPressed(A_BUTTON)) {
        if (stateChangeCallback != nullptr) {
            stateChangeCallback(STATE_START_MENU);
        }
    }

    playerCharacter->update(arduboy);

}

void CharacterSelectionState::draw(Arduboy2 &arduboy) {
    // Drawing code
    playerCharacter->draw(arduboy);
}
