#include "GameUI.h"
#include "Vars.h"

GameUI::GameUI() {

}

void GameUI::init(char *initialName, int initialLives, int initialMaxLives) {
  name = initialName;
  lives = initialLives;
  maxLives = initialMaxLives;
}

void GameUI::draw(Arduboy2 &arduboy) {
    drawName(arduboy);
    //drawLives(arduboy);
    //drawScore(arduboy);
    // ...
    drawSpeed(arduboy);
    drawGodMode(arduboy);
}

void GameUI::drawName(Arduboy2 &arduboy) {
  byte textWidthInPixels = strlen(name) * CHAR_WIDTH;
  arduboy.setCursor(SCREEN_WIDTH - textWidthInPixels, 0);
  arduboy.print(name);
}

void GameUI::drawScore(Arduboy2 &arduboy) {
    // Draw the score on the screen
    arduboy.setCursor(10, 0);
    arduboy.print("Score: ");
}

void GameUI::drawLives(Arduboy2 &arduboy) {
  // Draw the number of lives on the screen
  byte textWidthInPixels = strlen(name) * CHAR_WIDTH;
  byte startX = textWidthInPixels;

  byte totalLives = maxLives;
  byte currentLives = lives;

  byte x = startX;
  for (short i = 0; i < totalLives; i++) {
    if (i < currentLives) {
      Sprites::drawOverwrite(x, 0, uiheartfull, 0);
    } else {
      Sprites::drawOverwrite(x, 0, uiheartempty, 0);
    }
    x += 6;
  }
}

void GameUI::drawSpeed(Arduboy2 &arduboy) {
  arduboy.setCursor(0, 0);
  arduboy.print(globalSpeedMultiplier);
}

void GameUI::drawGodMode(Arduboy2 &arduboy) {
  if (godModeEnabled)
  {
    arduboy.setCursor(30, 0);
    arduboy.print("G");
  }
}
