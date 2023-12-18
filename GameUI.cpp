#include "GameUI.h"
#include "Vars.h"

GameUI::GameUI() {

}

void GameUI::init(char *initialName
#ifdef LIVES_ENABLED
                  , int initialLives, int initialMaxLives
#endif
                  ) {
  name = initialName;

#ifdef LIVES_ENABLED
  lives = initialLives;
  maxLives = initialMaxLives;
#endif
}

void GameUI::draw() {
    //drawName();

#ifdef LIVES_ENABLED
    //drawLives();
#endif

    drawScore();

#ifdef DEBUG_DRAW_VARS
    drawSpeed();
#endif
}

void GameUI::drawName() {
  arduboy.setCursor(screenWidth - getTextWidthInPixels(name), 0);
  arduboy.print(name);
}

void GameUI::drawScore() {
    char scoreStr[6]; // 5 digits + 1 for the null terminator
    sprintf(scoreStr, "%05d", score); // Format the score as a 5-digit number, padding with zeros

    arduboy.setCursor(screenWidth - getTextWidthInPixels(name), 0);
    arduboy.print(scoreStr);
}

#ifdef LIVES_ENABLED
void GameUI::drawLives() {
  // Draw the number of lives on the screen
  byte textWidthInPixels = getTextWidthInPixels(name);
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
#endif

void GameUI::drawSpeed() {
  arduboy.setCursor(0, 20);
  arduboy.print(globalSpeedMultiplier);
}
