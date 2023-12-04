// GamePlayState.cpp
#include "GamePlayState.h"
#include "Character0.h"
#include "Character1.h"
#include "GameModel.h"


void GamePlayState::init() {
    // Initialization code

    //playerCharacter = new Character0(0, 30);
    playerCharacter = gameModel.getSelectedCharacter();
    playerCharacter->setX(0);
    playerCharacter->setState(Character::WALKING);
    gameModel.setLives(playerCharacter->getLives());

    gameUI.init();

    entityManager.init();

    Ground* groundObject = new Ground(0, 60, 40, 1);
    entityManager.addEntity(groundObject);

    //entityManager.addEntity(playerCharacter);
}

void GamePlayState::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(B_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          stateChangeCallback(STATE_START_MENU);
      }
    }

    if (arduboy.justPressed(A_BUTTON)) {

    }

    entityManager.update();
    playerCharacter->update(arduboy);
}

void GamePlayState::draw(Arduboy2 &arduboy) {

    entityManager.draw(arduboy);
    playerCharacter->draw(arduboy);
    gameUI.draw(arduboy);
}

void GamePlayState::cleanup() {
    // Drawing code
}