// CharacterSelectionState.cpp
#include "CharacterSelectionState.h"
#include "sprites.h"
#include "Character.h"

Character* playerCharacter; // Declare a pointer to a character object

/*
const int frameChangeInterval = 10;  // Adjust this for a slower animation
int frameCounter = 0;
int currentFrame = 0;
*/

void CharacterSelectionState::init() {
    // Initialization code
    
    // Create an instance of MyCharacter
    playerCharacter = new Character();
    playerCharacter->init(character0idle, 2, 10);
}

void CharacterSelectionState::update(Arduboy2 &arduboy) {
    // Update logic
    
    if (arduboy.justPressed(A_BUTTON)) {
        if (stateChangeCallback != nullptr) {
            stateChangeCallback(STATE_START_MENU);
        }
    }

  /*
    frameCounter++;
    if (frameCounter >= frameChangeInterval) {
      currentFrame+=1;
      if (currentFrame > 1) {
        currentFrame = 0;
      }
      frameCounter = 0;
    }
    */
    playerCharacter->update(arduboy);

}

void CharacterSelectionState::draw(Arduboy2 &arduboy) {
    // Drawing code
    playerCharacter->draw(arduboy);
    //Sprites::drawOverwrite(0, 0, character0idle, currentFrame);
}
