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

    groundManager.init();
}

void GameState_Play::update() {
#ifdef DEBUG_SPEED_CONTROLS
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
#endif

    if (autoSpeedupEnabled)
    {
      globalSpeedMultiplier += speedMultiplierIncreasePerFrame;
      if (globalSpeedMultiplier > maxSpeed)
      {
        globalSpeedMultiplier = maxSpeed;
      }
    }

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
        score ++;
#ifdef SOUND_ENABLED
      sound.tone(score %2 == 0 ? NOTE_B7 : NOTE_AS7, 40);// coin collect
#endif

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
    int playerHighScore = playerCharacter->getHighScore();
    if (score > playerHighScore) {

      int addr = highScoreBaseAddress + playerCharacter->getType() * highScoreAddressMultiplier;
      saveHighScore(addr, score);
    }
}

void GameState_Play::draw() {
    groundManager.draw();
    playerCharacter->draw();

    if (gameover) {
      int x = SCREEN_WIDTH / 2 - (CHAR_WIDTH * 5);
      int y = SCREEN_HEIGHT / 2;
      arduboy.setCursor(x, y);
      arduboy.print("GAME OVER");
    }

    //draw score
    if (score < 99999) {
      char scoreStr[6]; // 5 digits + 1 for the null terminator
      snprintf(scoreStr, sizeof(scoreStr), "%05d", score); // Format the score as a 5-digit number, padding with zeros
      arduboy.setCursor(screenWidth - getTextWidthInPixels(scoreStr), 0);
      arduboy.print(scoreStr);
    } else {
      int numDigits = 0;
      int tempScore = score;
      while (tempScore > 0) {
          tempScore /= 10;
          numDigits++;
      }
      arduboy.setCursor(screenWidth - (numDigits * CHAR_WIDTH), 0);
      arduboy.print(score);
    }

#ifdef DEBUG_DRAW_VARS
    arduboy.setCursor(0, 0);
    arduboy.print(globalSpeedMultiplier);
    arduboy.setCursor(0, 8);
    arduboy.print(groundManager.calculateDifficultyLevel());
#endif
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
