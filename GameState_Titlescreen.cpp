// GameState_Titlescreen.cpp
#include "GameState_Titlescreen.h"
#include "sprites.h"

unsigned long lastBlinkTime = 0;
bool showText = true; // Initial state is to show the text

void GameState_Titlescreen::init() {
    // Initialization code
    showText = true;
    lastBlinkTime = millis(); // Reset lastBlinkTime to the current time
}

void GameState_Titlescreen::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(A_BUTTON)) {
        Serial.println("A Button Pressed");

        if (stateChangeCallback != nullptr) {
            stateChangeCallback(STATE_CHARACTER_SELECTION);
        }
    }
}

void GameState_Titlescreen::draw(Arduboy2 &arduboy) {
    // Drawing code
  Sprites::drawOverwrite (0, 0, titlescreensuper, 0);

  const char* startText = "PRESS A TO START"; // Change type to const char*
  int textWidthInPixels = strlen(startText) * CHAR_WIDTH; 

  int height = 12;

  int textX = (SCREEN_WIDTH / 2) - (textWidthInPixels / 2);
  int textY = SCREEN_HEIGHT - height + 3;

  unsigned long currentTime = millis();
  if (currentTime - lastBlinkTime >= 500) { // Adjust the blinking speed as needed
    showText = !showText; // Toggle visibility
    lastBlinkTime = currentTime; // Update the last blink time
  }

  arduboy.fillRoundRect(textX - 2, textY, textWidthInPixels + 4, 12, 2, BLACK);
  arduboy.drawRoundRect(textX - 2, textY, textWidthInPixels + 4, 12, 2, WHITE);

  if (showText) {
    arduboy.setCursor(textX + 1, textY + 2);
    arduboy.print(startText);
  }
}
