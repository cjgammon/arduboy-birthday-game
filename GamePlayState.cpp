// GamePlayState.cpp
#include "GamePlayState.h"
#include "Character0.h"
#include "Character1.h"
#include "GameModel.h"

int offset = 0;
int speed = 2;
int groundLevel = 30;

void GamePlayState::init() {
    // Initialization code
    offset = 0;

    //playerCharacter = new Character0(0, 30);
    playerCharacter = gameModel.getSelectedCharacter();
    playerCharacter->setX(0);
    playerCharacter->setY(groundLevel);
    playerCharacter->setGround(groundLevel);
    playerCharacter->setState(Character::WALKING);
    gameModel.setLives(playerCharacter->getLives());

    gameUI.init();

    entityManager.init();

    Ground* groundObject = new Ground(0, 60, 200);
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
      playerCharacter->startJump();
    }

    offset = -speed;
    entityManager.update(arduboy, offset);
    playerCharacter->update(arduboy);

    //CHECK IF CHARACTER Y IS ON GROUND POSITION AND NO GROUND IS PRESENT AT X
}

void GamePlayState::draw(Arduboy2 &arduboy) {

    entityManager.draw(arduboy);
    playerCharacter->draw(arduboy);
    gameUI.draw(arduboy);
}

void GamePlayState::cleanup() {
    // Drawing code
}