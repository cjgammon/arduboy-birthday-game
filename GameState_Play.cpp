// GameState_Play.cpp
#include "GameState_Play.h"
#include "GameModel.h"

float scrollX = 0; // Offset for scrolling
float speed = 2;
int groundLevel = 28;

void GameState_Play::init() {
    // Initialization code
    scrollX = 0;
    speed = 2;

    CharacterType playerType = gameModel.getSelectedCharacter();
    playerCharacter = new Character(0, 28, playerType);

    char* name = playerCharacter->getName();
    int maxLives = playerCharacter->getLives();

    playerCharacter->setX(0);
    playerCharacter->setY(groundLevel);
    playerCharacter->setGround(groundLevel);
    playerCharacter->setState(CharacterState::WALK);
    gameModel.setLives(maxLives);

    
    gameUI.init(name, maxLives, maxLives);

    groundManager.init();

    GameState_Play::createGroundEntities();
}

void GameState_Play::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(B_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          stateChangeCallback(STATE_START_MENU);
      }
    }

    scrollX = -speed;
    groundManager.update(arduboy, scrollX);

    //CHECK IF CHARACTER Y IS ON GROUND POSITION AND NO GROUND IS PRESENT AT setX
    if (playerCharacter->getY() == groundLevel) {
      int characterCenterPos = playerCharacter->getCenterX();
      // todo :: account for different character width?
      if (!groundManager.isGroundAt(characterCenterPos - 3) && ! groundManager.isGroundAt(characterCenterPos + 3))
      {
        playerCharacter->setState(CharacterState::FALL);
        speed = 0;
      }
    }

    playerCharacter->update(arduboy);
}

void GameState_Play::createGroundEntities() {
  
  int lastX = 0;
  for (int i = 0; i < GROUND_DEFINITION_COUNT; i++) {
    //int groundDef = pgm_read_byte(&(groundDefinitions[i]));
    Entity_Ground* newGround = new Entity_Ground(lastX, 60, i);
    groundManager.addEntity(newGround);
    lastX += GROUND_DEFINITION_SIZE * GROUND_SIZE;
  }
  
}

void GameState_Play::draw(Arduboy2 &arduboy) {
    gameUI.draw(arduboy);
    groundManager.draw(arduboy);
    playerCharacter->draw(arduboy);
}

void GameState_Play::cleanup() {
     if (playerCharacter != nullptr) {
        delete playerCharacter;
        playerCharacter = nullptr; // Set to nullptr to avoid dangling pointer
    }
    // Drawing code
    groundManager.cleanup();
}
