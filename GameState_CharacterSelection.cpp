// GameState_CharacterSelection.cpp
#include "GameState_CharacterSelection.h"
#include "GlobalMethods.h"

int numCharacters = 6;
Character* playerCharacter;

uint8_t selectedCharacter = 0;

void GameState_CharacterSelection::init() {
    int x = (screenWidth / 2) - (16 / 2);
    int y = 28;
    playerCharacter = new Character(x, y, selectedCharacter);
}

void GameState_CharacterSelection::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(A_BUTTON)) {
      stateChangeCallback(STATE_GAME_PLAY);
    }

    if (arduboy.justPressed(RIGHT_BUTTON)) {
      changeCharacter((selectedCharacter + 1) % numCharacters);
    }

    if (arduboy.justPressed(LEFT_BUTTON)) {
      changeCharacter((selectedCharacter - 1 + numCharacters) % numCharacters);
    }

    // don't update the character here unless you want them to handle input and process physics.
    //playerCharacter->update(arduboy);
}

void GameState_CharacterSelection::changeCharacter(uint8_t newIndex) {
  selectedCharacter = newIndex;
  playerCharacter->setType(selectedCharacter);
}

void drawCenteredText(Arduboy2 &arduboy, char* text, uint8_t y)
{
  int textX = screenWidth/2 - (getTextWidthInPixels(text) / 2);
  arduboy.setCursor(textX, y);
  arduboy.print(text);
}

void GameState_CharacterSelection::draw(Arduboy2 &arduboy) {
    // Drawing code
    
    //highScore int to char* 
    int highScore = playerCharacter->getHighScore();
    char highScoreString[12]; // Buffer to hold the string representation of the integer
    sprintf(highScoreString, "HIGH: %d", highScore); // Convert the integer to a string


    drawCenteredText(arduboy, playerCharacter->getName(), 0);
    drawCenteredText(arduboy, playerCharacter->getDescription(), 11);
    drawCenteredText(arduboy, highScoreString, 21);

    playerCharacter->draw(arduboy);

    //draw ground
    int x = 0;
    for (int i = 0; i < 21; i++) {
      const uint8_t* sprite;
      drawRandomGround(i, x, 60);
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
