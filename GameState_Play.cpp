// GameState_Play.cpp
#include "GameState_Play.h"
#include "Vars.h"
#include "Sound.h"
#include "GlobalMethods.h"

float cameraX = 0;
float cameraY = 0;
int score = 0;

#ifdef LIVES_ENABLED
int lives = 3;
#endif
float speed = 2;
int groundLevel = 28;

float globalSpeedMultiplier = 0.95;
float maxSpeed = 2.2;
float timeToReachMaxSpeedInSeconds = 80.0;
float speedMultiplierIncreasePerFrame = (maxSpeed - globalSpeedMultiplier) / (timeToReachMaxSpeedInSeconds * 60.0);
bool autoSpeedupEnabled = true;
bool gameover = false;

#define MAX_VISIBLE_GROUND_PIECES 3
Entity_Ground groundPieces[MAX_VISIBLE_GROUND_PIECES];

void GameState_Play::init() {

    // Initialization code
    globalSpeedMultiplier = 0.95;
    cameraX = 0;
    speed = 2;
    gameover = false;
    score = 0;

    int playerType = selectedCharacter;
    playerCharacter = new Character(0, 28, playerType);

    char* name = playerCharacter->getName();

    playerCharacter->setX(0);
    playerCharacter->setY(groundLevel);
    playerCharacter->setGround(groundLevel);
    playerCharacter->setState(CharacterState::WALK);

#ifdef LIVES_ENABLED
    int maxLives = playerCharacter->getLives();
    lives = maxLives;
    gameUI.init(name, maxLives, maxLives);
#else
    gameUI.init(name);
#endif

    groundManager.init();

    GameState_Play::createGroundEntities();
}

void GameState_Play::update() {
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
#ifdef SOUND_ENABLED
      sound.tone(NOTE_B3, 80);// exit to title screen
#endif
    }

    cameraX = -speed * globalSpeedMultiplier;
    groundManager.update();

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
        playerDie();
      }
    }

    if (
            playerCharacter->isAlive()
#ifdef CHEAT_MODE_ENABLED
            && (cheatMode != CheatMode::GodMode && cheatMode != CheatMode::NoCollisions)
#endif
      )
    {
      Entity_Enemy* collidingEnemy = groundManager.enemyCollision(playerCharacter->getCenterX(), playerCharacter->getCenterY(), playerCharacter->getRadius());
      if (collidingEnemy != nullptr)
      {
        // todo :: enemy type switch?
        playerCharacter->velocityY = -3.6;
        playerDie();
      }
    }

    if (playerCharacter->isAlive())
    {
      Coin* collidingCoin = groundManager.coinCollision(playerCharacter->getCenterX(), playerCharacter->getCenterY(), playerCharacter->getRadius());
      if (collidingCoin != nullptr)
      {
        collidingCoin->enabled = false;
        gameUI.incScore();
      }
    }

    playerCharacter->update();
}

void GameState_Play::playerDie() {
    playerCharacter->setState(CharacterState::FALL);
    speed = 0;
    globalSpeedMultiplier = 0.8;
#ifdef SOUND_ENABLED
    sound.tone(NOTE_G4, 250);// die
#endif
    gameover = true;

    //check hiscore
    int score = gameUI.getScore();
    int playerHighScore = playerCharacter->getHighScore();
    if (score > playerHighScore) {

      int addr = highScoreBaseAddress + playerCharacter->getType() * highScoreAddressMultiplier;
      saveHighScore(addr, score);
    }
}

//TODO:: move this to entity ground manager?
void GameState_Play::createGroundEntities()
{
  // create as many ground entities as can possibly be visible at once.
  int lastX = 0;
  int eligibleSegments[GROUND_DEFINITION_COUNT];
  int eligibleCount = 0;
  int currentDifficultyLevel = groundManager.calculateDifficultyLevel();  

  for (int i = 0; i < GROUND_DEFINITION_COUNT; i++) {
    int segmentDifficulty = pgm_read_byte(&groundDefinitions[i].difficulty);

      if (segmentDifficulty <= currentDifficultyLevel) {
          eligibleSegments[eligibleCount++] = i;
      }
  }

  for (int i = 0; i < MAX_VISIBLE_GROUND_PIECES; i++)
  {
    Entity_Ground* groundEntity = &groundPieces[i];
    groundEntity->init(lastX, 60);
    groundManager.addEntity(groundEntity);
    lastX += GROUND_DEFINITION_SIZE * GROUND_SIZE;

    if (i == 0 || eligibleCount == 0) {
        groundEntity->setData(&flatGround);
    } else {
        int randomIndex = eligibleSegments[random(0, eligibleCount)];
        groundEntity->setData(&groundDefinitions[randomIndex]);
    }
  }
  
}

void GameState_Play::draw() {
    gameUI.draw();
    groundManager.draw();
    playerCharacter->draw();
    
#ifdef DEBUG_DRAW_VARS
    arduboy.setCursor(0, 10);
    arduboy.print(groundManager.calculateDifficultyLevel());
#endif

    if (gameover) {
      int x = SCREEN_WIDTH / 2 - (CHAR_WIDTH * 5);
      int y = SCREEN_HEIGHT / 2;
      arduboy.setCursor(x, y);
      arduboy.print("GAME OVER");
    }
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
