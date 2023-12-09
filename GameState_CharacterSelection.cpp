// GameState_CharacterSelection.cpp
#include "GameState_CharacterSelection.h"
#include "GlobalMethods.h"

int numCharacters = 6;
Character* playerCharacter;

int currentCharacter = 0;

void GameState_CharacterSelection::init() {
    int x = (SCREEN_WIDTH / 2) - (16 / 2);
    int y = 28;
    playerCharacter = new Character(x, y, currentCharacter);
}

void GameState_CharacterSelection::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justReleased(A_BUTTON)) {
      gameModel.setSelectedCharacter(currentCharacter);
      stateChangeCallback(STATE_GAME_PLAY);
    }

    if (arduboy.justPressed(RIGHT_BUTTON)) {
      if (currentCharacter < numCharacters - 1) {
        currentCharacter++;
      } else {
        currentCharacter = 0;
      }
      changeCharacter();
    }

    if (arduboy.justPressed(LEFT_BUTTON)) {
      if (currentCharacter > 0) {
        currentCharacter--;
      } else {
        currentCharacter = numCharacters - 1;
      }
      changeCharacter();
    }

    // don't update the character here unless you want them to handle input and process physics.
    //playerCharacter->update(arduboy);
}

void GameState_CharacterSelection::changeCharacter() {
  playerCharacter->setType(currentCharacter); 
}

void GameState_CharacterSelection::draw(Arduboy2 &arduboy) {
    // Drawing code

    size_t name = playerCharacter->getName();
    int textWidthInPixels = strlen(name) * CHAR_WIDTH; 
    int textX = (SCREEN_WIDTH / 2) - (textWidthInPixels / 2);
    int textY = 0;
    arduboy.setCursor(textX, textY);
    arduboy.print(playerCharacter->getName());

    name = playerCharacter->getDescription();
    textWidthInPixels = strlen(name) * CHAR_WIDTH;
    textX = (SCREEN_WIDTH / 2) - (textWidthInPixels / 2);
    textY = 11;
    arduboy.setCursor(textX, textY);
    arduboy.print(playerCharacter->getDescription());

    playerCharacter->draw(arduboy);

    //draw ground
    int x = 0;
    for (int i = 0; i < 21; i++) {
      const uint8_t* sprite;

      drawRandomGround(i, x, 60);

      //Sprites::drawOverwrite(x, 60, environmentgroundmiddle, 0);
      x += 6;
    }
}

void GameState_CharacterSelection::cleanup() {
    // Drawing code
     if (playerCharacter != nullptr) {
        delete playerCharacter;
        playerCharacter = nullptr; // Set to nullptr to avoid dangling pointer
    }
}
