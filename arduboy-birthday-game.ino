#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "GameState_Titlescreen.h"
#include "GameState_CharacterSelection.h"
#include "GameState_Play.h"
#include "Vars.h"
#include "Sound.h"

Arduboy2 arduboy;
#ifdef SOUND_ENABLED
ArduboyTones sound(arduboy.audio.enabled);
#endif

//states
GameState *currentState;
GameState_Titlescreen* startMenuState = new GameState_Titlescreen();
GameState_CharacterSelection* characterSelectionState = new GameState_CharacterSelection();
GameState_Play* gamePlayState = new GameState_Play();

#ifdef CHEAT_MODE_ENABLED
int cheatMode = CheatMode::Disabled;
#endif

uint8_t screenWidth = 128;

int highScoreBaseAddress = 0x50;
int highScoreAddressMultiplier = 5;

const int fixedSeedValue = 12345; // Example fixed seed value

uint8_t getTextWidthInPixels(char* text)
{
  return strlen(text) * CHAR_WIDTH;
}

void setup() {
  
  Serial.begin(9600);

  randomSeed(fixedSeedValue); // Seed the random number generator with a fixed value

  //arduboy.begin();
  arduboy.boot();
  //arduboy.display();
  //arduboy.systemButtons();
#ifdef SOUND_ENABLED
  arduboy.audio.begin();
#endif
  arduboy.setFrameRate(60);

  startMenuState->setStateChangeCallback(changeGameState);
  characterSelectionState->setStateChangeCallback(changeGameState);
  gamePlayState->setStateChangeCallback(changeGameState);

  currentState = startMenuState;
  currentState->init();
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

  currentState->update(arduboy);
  currentState->draw(arduboy);

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
  currentState->cleanup();

  switch (newState) {
    case STATE_START_MENU:
      currentState = startMenuState;
      break;
    case STATE_CHARACTER_SELECTION:
      currentState = characterSelectionState;
      break;
    case STATE_GAME_PLAY:
      currentState = gamePlayState;
      break;
  }

  currentState->init();
}
