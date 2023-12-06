// GameState_Play.cpp
#include "GameState_Play.h"
#include "GameModel.h"

int scrollX = 0; // Offset for scrolling
int speed = 2;
int groundLevel = 28;

void GameState_Play::init() {
    // Initialization code
    scrollX = 0;
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

    GameState_Play::createGroundEntities();

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

    scrollX = -speed;
    entityManager.update(arduboy, scrollX);
    playerCharacter->update(arduboy);

    
    //CHECK IF CHARACTER Y IS ON GROUND POSITION AND NO GROUND IS PRESENT AT setX
    if (playerCharacter->getY() == groundLevel && !entityManager.isGroundAt(playerCharacter->getX())) {
      playerCharacter->setState(Character::FALL);
      speed = 0;
    }
    
}

void GameState_Play::createGroundEntities() {
  //TODO:: reference the array by index..

  int lastX = 0;
  for (int i = 0; i < GROUND_DEFINITION_COUNT; i++) {
    Entity_Ground* newGround = new Entity_Ground(lastX, 60, i);
    entityManager.addEntity(newGround);
    lastX += GROUND_DEFINITION_SIZE * GROUND_SIZE;
  }
  
  /*
  Entity_Ground* groundObject = new Entity_Ground(0, 60, 200);
  entityManager.addEntity(groundObject);

  Entity_Ground* groundObject2 = new Entity_Ground(200, 60, 200);
  entityManager.addEntity(groundObject2);

    Entity_Ground* groundObject3 = new Entity_Ground(400, 60, 200);
  entityManager.addEntity(groundObject3);
  */
  
  /*
  int lastX = 0;
  for (int i = 0; i < GROUND_DEFINITION_COUNT; i++) {
    //int groundDef = pgm_read_byte(&(groundDefinitions[i]));
    const int* groundDef = groundDefinitions[i];

    Entity_Ground* newGround = new Entity_Ground(lastX, 60, groundDef);
    entityManager.addEntity(newGround);
    lastX += GROUND_DEFINITION_SIZE * GROUND_SIZE;
  }
  */
  
  /*
  int lastX = 0;
  for (int i = 0; i < GROUND_DEFINITION_COUNT; i++) {
      int groundDef[GROUND_DEFINITION_SIZE];

      // Read each element of the ground definition array from program memory
      for (int j = 0; j < GROUND_DEFINITION_SIZE; j++) {
          groundDef[j] = pgm_read_byte(&(groundDefinitions[i][j]));
      }

      Entity_Ground* newGround = new Entity_Ground(lastX, 60, groundDef);
      entityManager.addEntity(newGround);
      lastX += GROUND_DEFINITION_SIZE * GROUND_SIZE;
  }
  */
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
