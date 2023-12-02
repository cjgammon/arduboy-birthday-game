// CharacterSelectionState.cpp
#include "CharacterSelectionState.h"
#include "Character.h"
#include "Character0.h"
//#include "Character1.h"

int numCharacters = 1;
Character** playerCharacters; // Declare an array of character pointers


void CharacterSelectionState::init() {
    // Initialization code
    playerCharacters = new Character*[numCharacters]; // Allocate memory for the array

    for (int i = 0; i < numCharacters; i++) {
      int initialX = i * 20; // Adjust the X position as needed
      int initialY = 20;    // Set the Y position as needed
      playerCharacters[i] = new Character0(initialX, initialY);
    }
}

void CharacterSelectionState::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(A_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          stateChangeCallback(STATE_START_MENU);
      }
    }

    for (int i = 0; i < numCharacters; i++) {
      playerCharacters[i]->update(arduboy);
    }

}

void CharacterSelectionState::draw(Arduboy2 &arduboy) {
    // Drawing code
    for (int i = 0; i < numCharacters; i++) {
        playerCharacters[i]->draw(arduboy);
    }
}

void CharacterSelectionState::cleanup() {
    // Drawing code
    for (int i = 0; i < numCharacters; i++) {
        delete playerCharacters[i]; // Delete each character instance
    }
    delete[] playerCharacters; // Delete the array of character pointers
}