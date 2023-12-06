// GameState_Play.cpp
#include "GameState_Play.h"
#include "GameModel.h"

int offset = 0; // Offset for scrolling
int speed = 2;
int groundLevel = 28;

void GameState_Play::init() {
    // Initialization code
    offset = 0;
    speed = 2;

    CharacterType playerType = gameModel.getSelectedCharacter();
    playerCharacter = new Character(0, 30, playerType);

    char* name = playerCharacter->getName();
    int maxLives = playerCharacter->getLives();

    playerCharacter->setX(0);
    playerCharacter->setY(groundLevel);
    playerCharacter->setGround(groundLevel);
    playerCharacter->setState(Character::WALK);
    gameModel.setLives(maxLives);

    
    gameUI.init(name, maxLives, maxLives);

    entityManager.init();

    Entity_Ground* groundObject = new Entity_Ground(0, 60, 200);
    entityManager.addEntity(groundObject);

    //entityManager.addEntity(playerCharacter);
}

void GameState_Play::update(Arduboy2 &arduboy) {
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

    //CHECK IF CHARACTER Y IS ON GROUND POSITION AND NO GROUND IS PRESENT AT setX
    if (playerCharacter->getY() == groundLevel && !entityManager.isGroundAt(playerCharacter->getX())) {
      playerCharacter->setState(Character::FALL);
      speed = 0;
    }
}

void GameState_Play::draw(Arduboy2 &arduboy) {

    entityManager.draw(arduboy);
    playerCharacter->draw(arduboy);
    gameUI.draw(arduboy);
}

void GameState_Play::cleanup() {
    // Drawing code
    entityManager.cleanup();
}
