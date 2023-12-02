#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "GameStateManager.h"
#include "StartMenuState.h"
#include "CharacterSelectionState.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

GameStateManager stateManager;
StartMenuState startMenuState;
CharacterSelectionState characterSelectionState;

void setup() {
  Serial.begin(9600);

  arduboy.begin();
  arduboy.setFrameRate(60);

  startMenuState.setStateChangeCallback(changeGameState);
  characterSelectionState.setStateChangeCallback(changeGameState);

  stateManager.setState(&startMenuState);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.pollButtons();
  arduboy.clear();

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
    }
}
