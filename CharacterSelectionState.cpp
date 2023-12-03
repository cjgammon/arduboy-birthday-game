// CharacterSelectionState.cpp
#include "sprites.h"
#include "CharacterSelectionState.h"
#include "Character.h"
#include "Character0.h"
#include "Character1.h"

#define CHAR_WIDTH 6 // character width in pixels including inter-character spacing
#define SCREEN_WIDTH 128 // character width in pixels including inter-character spacing

int numCharacters = 5;
Character** playerCharacters; // Declare an array of character pointers

int currentCharacter = 0;

void CharacterSelectionState::init() {
    // Initialization code
    playerCharacters = new Character*[numCharacters]; // Allocate memory for the array

    for (int i = 0; i < numCharacters; i++) {
      int x = (SCREEN_WIDTH / 2) - 16;
      int y = 30;
      if (i == 0) {
        playerCharacters[i] = new Character0(x, y);
      } else {
        playerCharacters[i] = new Character1(x, y);
      }
    }
}

void CharacterSelectionState::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(A_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          stateChangeCallback(STATE_GAME_PLAY);
      }
    }

    if (arduboy.justPressed(RIGHT_BUTTON)) {
      if (currentCharacter < numCharacters - 1) {
        currentCharacter++;
      } else {
        currentCharacter = 0;
      }
    }

    if (arduboy.justPressed(LEFT_BUTTON)) {
      if (currentCharacter > 0) {
        currentCharacter--;
      } else {
        currentCharacter = numCharacters - 1;
      }
    }

    playerCharacters[currentCharacter]->update(arduboy);

}

void CharacterSelectionState::draw(Arduboy2 &arduboy) {
    // Drawing code

    size_t name = playerCharacters[currentCharacter]->getName();
    int textWidthInPixels = strlen(name) * CHAR_WIDTH; 
    int textX = (SCREEN_WIDTH / 2) - (textWidthInPixels / 2);
    int textY = 0;
    arduboy.setCursor(textX, textY);
    arduboy.print(playerCharacters[currentCharacter]->getName());

    playerCharacters[currentCharacter]->draw(arduboy);

    //draw ground
    int x = 0;
    for (int i = 0; i < 21; i++) {
      Sprites::drawOverwrite(x, 60, environmentgroundmiddle, 0);
      x += 6;
    }
}

void CharacterSelectionState::cleanup() {
    // Drawing code
    for (int i = 0; i < numCharacters; i++) {
        delete playerCharacters[i]; // Delete each character instance
    }
    delete[] playerCharacters; // Delete the array of character pointers
}