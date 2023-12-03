// GamePlayState.cpp
#include "GamePlayState.h"
#include "Character.h"
#include "Character0.h"
#include "Character1.h"
#include "GameModel.h"

Character* playerCharacter;

void GamePlayState::init() {
    // Initialization code

    //playerCharacter = new Character0(0, 30);
    playerCharacter = gameModel.getSelectedCharacter();
    playerCharacter->setState(Character::WALKING);

    gameModel.setLives(playerCharacter->getLives());

    gameUI.init();
}

void GamePlayState::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(A_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          stateChangeCallback(STATE_START_MENU);
      }
    }

    playerCharacter->update(arduboy);
}

void GamePlayState::draw(Arduboy2 &arduboy) {

    // Drawing code
    playerCharacter->draw(arduboy);
    gameUI.draw(arduboy);
}

void GamePlayState::cleanup() {
    // Drawing code
}