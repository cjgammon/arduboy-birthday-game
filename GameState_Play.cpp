// GameState_Play.cpp
#include "GameState_Play.h"
#include "Vars.h"


float cameraX = 0;
float cameraY = 0;

int lives = 3;
float speed = 2;
int groundLevel = 28;

float globalSpeedMultiplier = 0.85;
float maxSpeed = 1.6;
float timeToReachMaxSpeedInSeconds = 60.0;
float speedMultiplierIncreasePerFrame = (maxSpeed - globalSpeedMultiplier) / (timeToReachMaxSpeedInSeconds * 60.0);
bool autoSpeedupEnabled = true;

#define MAX_VISIBLE_GROUND_PIECES 3
Entity_Ground groundPieces[MAX_VISIBLE_GROUND_PIECES];

void GameState_Play::init() {

    // Initialization code
    globalSpeedMultiplier = 0.85;
    cameraX = 0;
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
      stateChangeCallback(STATE_START_MENU);
    }

    cameraX = -speed * globalSpeedMultiplier;
    groundManager.update(arduboy);

    int characterCenterPosY = playerCharacter->getCenterY();
    int characterCenterPosX = playerCharacter->getCenterX();

    //CHECK IF CHARACTER Y IS ON GROUND POSITION AND NO GROUND IS PRESENT AT setX
    if (playerCharacter->getY() == groundLevel) {
      // todo :: account for different character width?
      if (
#ifdef CHEAT_MODE_ENABLED
              (cheatMode != CheatMode::GodMode && cheatMode != CheatMode::NoFalling) &&
#endif
              !groundManager.isGroundAt(characterCenterPosX - 3)
              && ! groundManager.isGroundAt(characterCenterPosX + 3)
          )
      {
        playerCharacter->setState(CharacterState::FALL);
        speed = 0;
        globalSpeedMultiplier = 0.8;
      }
    }

    if (
            playerCharacter->isAlive()
#ifdef CHEAT_MODE_ENABLED
            && (cheatMode != CheatMode::GodMode && cheatMode != CheatMode::NoCollisions)
#endif
            && groundManager.enemyCollision(playerCharacter->getCenterX(), playerCharacter->getCenterY(), playerCharacter->getRadius()))
    {
      playerCharacter->velocityY = -3.6;
      playerCharacter->setState(CharacterState::FALL);
      speed = 0;
      globalSpeedMultiplier = 0.8;
    }

    playerCharacter->update(arduboy);
}

void GameState_Play::createGroundEntities()
{
  // create as many ground entities as can possibly be visible at once.
  int lastX = 0;
  for (int i = 0; i < MAX_VISIBLE_GROUND_PIECES; i++)
  {
    Entity_Ground* groundEntity = &groundPieces[i];
    groundEntity->init(lastX, 60);
    groundManager.addEntity(groundEntity);
    lastX += GROUND_DEFINITION_SIZE * GROUND_SIZE;
    groundEntity->setData(
            i == 0
            ? &flatGround
            : &groundDefinitions[random(0, GROUND_DEFINITION_COUNT)]
      );
  }
  
}

void GameState_Play::draw(Arduboy2 &arduboy) {
    gameUI.draw(arduboy);
    groundManager.draw(arduboy);
    playerCharacter->draw(arduboy);
}

void GameState_Play::cleanup()
{
  if (playerCharacter != nullptr)
  {
    delete playerCharacter;
    playerCharacter = nullptr; // Set to nullptr to avoid dangling pointer
  }

  groundManager.cleanup();
}
