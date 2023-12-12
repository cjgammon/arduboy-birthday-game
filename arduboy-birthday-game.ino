#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "GameStateManager.h"
#include "GameState_Titlescreen.h"
#include "GameState_CharacterSelection.h"
#include "GameState_Play.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

GameStateManager stateManager;

//states
GameState_Titlescreen startMenuState;
GameState_CharacterSelection characterSelectionState;
GameState_Play gamePlayState;

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

  stateManager.update(arduboy);
  stateManager.draw(arduboy);

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
