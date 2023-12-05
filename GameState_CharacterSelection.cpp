// GameState_CharacterSelection.cpp
#include "sprites.h"
#include "GameState_CharacterSelection.h"
#include "Character.h"
#include "Character_Henry.h"
#include "Character_Jaxon.h"
#include "Character_Jonas.h"
#include "Character_Lyle.h"
#include "Character_Mason.h"
#include "Character_Nola.h"
#include "Character_PineappleMurphy.h"
#include "Character_RobotSteve.h"
#include "Character_Ruhaan.h"
#include "Character_Val.h"
#include "GameModel.h"

int numCharacters = 7;
Character** playerCharacters; // Declare an array of character pointers

int currentCharacter = 0;

void GameState_CharacterSelection::init() {
    // Initialization code
    playerCharacters = new Character*[numCharacters]; // Allocate memory for the array

    int wideCharacterX = (SCREEN_WIDTH / 2) - 16;
    int skinnyCharacterX = (SCREEN_WIDTH / 2) - 8;
    int y = 28;
    playerCharacters[0] = new Character_Jonas(skinnyCharacterX, y);
    playerCharacters[1] = new Character_Henry(skinnyCharacterX, y);
    playerCharacters[2] = new Character_Jaxon(skinnyCharacterX, y);
    playerCharacters[3] = new Character_Lyle(skinnyCharacterX, y);
    playerCharacters[4] = new Character_Mason(skinnyCharacterX, y);
    playerCharacters[5] = new Character_Nola(skinnyCharacterX, y);
    playerCharacters[6] = new Character_PineappleMurphy(skinnyCharacterX, y);
    //playerCharacters[7] = new Character_RobotSteve(skinnyCharacterX, y);
    //playerCharacters[8] = new Character_Ruhaan(skinnyCharacterX, y);
    //playerCharacters[9] = new Character_Val(skinnyCharacterX, y);
}

void GameState_CharacterSelection::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(A_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          gameModel.setSelectedCharacter(playerCharacters[currentCharacter]);
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

void GameState_CharacterSelection::draw(Arduboy2 &arduboy) {
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

void GameState_CharacterSelection::cleanup() {
    // Drawing code
    for (int i = 0; i < numCharacters; i++) {
        delete playerCharacters[i]; // Delete each character instance
    }
    delete[] playerCharacters; // Delete the array of character pointers
}
