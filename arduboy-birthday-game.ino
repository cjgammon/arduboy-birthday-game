#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "GameStateManager.h"
#include "GameState_Titlescreen.h"
#include "GameState_CharacterSelection.h"
#include "GameState_Play.h"
#include "Vars.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

GameStateManager stateManager;

//states
GameState_Titlescreen startMenuState;
GameState_CharacterSelection characterSelectionState;
GameState_Play gamePlayState;

#ifdef CHEAT_MODE_ENABLED
int cheatMode = CheatMode::Disabled;
#endif

uint8_t screenWidth = 128;

uint8_t getTextWidthInPixels(char* text)
{
  return strlen(text) * CHAR_WIDTH;
}

void setup() {
  
  Serial.begin(9600);

  arduboy.boot();
  arduboy.setFrameRate(60);

  startMenuState.setStateChangeCallback(changeGameState);
  characterSelectionState.setStateChangeCallback(changeGameState);
  gamePlayState.setStateChangeCallback(changeGameState);

  stateManager.setState(&startMenuState);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();
  arduboy.pollButtons();

#ifdef CHEAT_MODE_ENABLED
  // update cheat mode.
  if (arduboy.justPressed(DOWN_BUTTON))
  {
    cheatMode = (cheatMode + 1) % CheatMode::Total;
  }
#endif

  stateManager.update(arduboy);
  stateManager.draw(arduboy);

#ifdef CHEAT_MODE_ENABLED
  // draw cheat mode.
  arduboy.setCursor(30, 0);
  if (cheatMode == CheatMode::GodMode)
  {
    arduboy.print("G");
  }
  else if (cheatMode == CheatMode::NoCollisions)
  {
    arduboy.print("xC");
  }
  else if (cheatMode == CheatMode::NoFalling)
  {
    arduboy.print("xF");
  }
#endif

  arduboy.display();
}

void changeGameState(GameStateID newState) {
  stateManager.getCurrentState()->cleanup();

  switch (newState) {
    case STATE_START_MENU:
      stateManager.setState(&startMenuState);
      break;
    case STATE_CHARACTER_SELECTION:
      stateManager.setState(&characterSelectionState);
      break;
    case STATE_GAME_PLAY:
      stateManager.setState(&gamePlayState);
      break;
  }
}
