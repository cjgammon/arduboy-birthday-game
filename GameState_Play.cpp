// GameState_Play.cpp
#include "GameState_Play.h"
#include "Vars.h"

int lives = 3;
float scrollX = 1; // Offset for scrolling
float speed = 2;
int groundLevel = 28;

float globalSpeedMultiplier = 0.85;
float maxSpeed = 1.6;
float timeToReachMaxSpeedInSeconds = 60.0;
float speedMultiplierIncreasePerFrame = (maxSpeed - globalSpeedMultiplier) / (timeToReachMaxSpeedInSeconds * 60.0);
bool autoSpeedupEnabled = true;

bool godModeEnabled = false;

void GameState_Play::init() {
    godModeEnabled = false;

    // Initialization code
    globalSpeedMultiplier = 0.85;
    scrollX = 0;
    speed = 2;

    int playerType = selectedCharacter;
    playerCharacter = new Character(0, 28, playerType);

    char* name = playerCharacter->getName();
    int maxLives = playerCharacter->getLives();

    playerCharacter->setX(0);
    playerCharacter->setY(groundLevel);
    playerCharacter->setGround(groundLevel);
    playerCharacter->setState(CharacterState::WALK);
    lives = maxLives;

    gameUI.init(name, maxLives, maxLives);

    groundManager.init();

    GameState_Play::createGroundEntities();
}

void GameState_Play::update(Arduboy2 &arduboy) {
    // manage speed up
    if (arduboy.justPressed(RIGHT_BUTTON))
    {
      globalSpeedMultiplier += 0.25;
    }

    if (arduboy.justPressed(LEFT_BUTTON))
    {
      globalSpeedMultiplier -= 0.25;
    }

    if (arduboy.justPressed(UP_BUTTON))
    {
      autoSpeedupEnabled = !autoSpeedupEnabled;
    }

    if (arduboy.justPressed(DOWN_BUTTON))
    {
      godModeEnabled = !godModeEnabled;
    }

    if (autoSpeedupEnabled)
    {
      globalSpeedMultiplier += speedMultiplierIncreasePerFrame;
      if (globalSpeedMultiplier > maxSpeed)
      {
        globalSpeedMultiplier = maxSpeed;
      }
    }


    // Update logic
    if (arduboy.justPressed(B_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          stateChangeCallback(STATE_START_MENU);
      }
    }

    scrollX = -speed * globalSpeedMultiplier;
    groundManager.update(arduboy, scrollX);

    int characterCenterPosY = playerCharacter->getCenterY();
    int characterCenterPosX = playerCharacter->getCenterX();

    //CHECK IF CHARACTER Y IS ON GROUND POSITION AND NO GROUND IS PRESENT AT setX
    if (playerCharacter->getY() == groundLevel) {
      // todo :: account for different character width?
      if (!godModeEnabled && !groundManager.isGroundAt(characterCenterPosX - 3) && ! groundManager.isGroundAt(characterCenterPosX + 3))
      {
        playerCharacter->setState(CharacterState::FALL);
        speed = 0;
      }
    }

    if (!godModeEnabled && groundManager.enemyCollision(playerCharacter->getCenterX(), playerCharacter->getCenterY(), playerCharacter->getRadius()))
    {
      //explosion???
      speed = 0;
    }

    playerCharacter->update(arduboy);
}

void GameState_Play::createGroundEntities() {
  
  int lastX = 0;
  for (int i = 0; i < GROUND_DEFINITION_COUNT; i++) {
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
