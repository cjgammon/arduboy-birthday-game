#include "GameUI.h"
#include "GameModel.h"
#include "sprites.h"

#define CHAR_WIDTH 6 // character width in pixels including inter-character spacing

GameUI::GameUI() {

}

void GameUI::init() {

}

void GameUI::draw(Arduboy2 &arduboy) {
    // Drawing method - Called to draw UI elements
    drawName(arduboy);
    drawLives(arduboy);
    //drawScore(arduboy);
    // ...
}

void GameUI::drawName(Arduboy2 &arduboy) {
  Character *currentCharacter = gameModel.getSelectedCharacter();
  arduboy.print(currentCharacter->getName());
}

void GameUI::drawScore(Arduboy2 &arduboy) {
    // Draw the score on the screen
    arduboy.setCursor(10, 0);
    arduboy.print("Score: ");
}

void GameUI::drawLives(Arduboy2 &arduboy) {
    // Draw the number of lives on the screen
  Character *currentCharacter = gameModel.getSelectedCharacter();
  char *name = currentCharacter->getName();
  int textWidthInPixels = strlen(name) * CHAR_WIDTH; 
  int startX = textWidthInPixels;

  int totalLives = currentCharacter->getLives();
  int currentLives = gameModel.getLives();

  int x = startX;
  for (int i = 0; i < totalLives; i++) {
    Sprites::drawOverwrite(x, 0, uiheartfull, 0);
    x += 6;
  }
}
