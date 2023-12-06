#include "Character.h"

const float gravity = 0.3;
const float jumpPower = -5.0;

Character::Character(int initialX, int initialY, CharacterType initialType) {
  x = initialX;
  y = initialY;

  groundLevel = initialY;

  velocityY = 0;
  currentFrame = 0;
  lives = 3;

  state = CharacterState::IDLE;
  setType(initialType);
}

Character::~Character() {}

void Character::update(Arduboy2 &arduboy) {
  frameCounter++;
  if (frameCounter >= frameChangeInterval) {
    currentFrame++;
    if (currentFrame >= frameCount) {
      currentFrame = 0;
    }
    frameCounter = 0;
  }
}

void Character::setType(CharacterType newType) {
  type = newType;
  
  frameCount_Idle = 2;
  frameCount_Walking = 9;
  frameCount_Jump = 1;
  frameCount_Fall = 1;
  frameChangeInterval_Idle = 10;
  frameChangeInterval_Walking = 6;
  frameChangeInterval_Jump = 1;
  frameChangeInterval_Fall = 1;

  switch (type) {
    case CharacterType::JONAS:
      name = "JONAS";
      frameCount_Walking = 10;
      idleSprite = character_jonas_idle;
      walkSprite = character_jonas_run;
      jumpSprite = character_jonas_jump;
      fallSprite = character_jonas_fall;
    break;
    case CharacterType::HENRY:
      name = "HENRY";
      frameCount_Walking = 6;
      idleSprite = character_skaterboy_idle;
      walkSprite = character_skaterboy_run;
      jumpSprite = character_skaterboy_jump;
      fallSprite = character_skaterboy_fall;
    break;
    case CharacterType::JAXON:
      name = "JAXON";
      idleSprite = character_jaxon_idle;
      walkSprite = character_jaxon_run;
      jumpSprite = character_jaxon_jump;
      fallSprite = character_jaxon_fall;
    break;
    case CharacterType::MASON:
      name = "MASON";
      idleSprite = character_calvin_idle;
      walkSprite = character_calvin_run;
      jumpSprite = character_calvin_jump;
      fallSprite = character_calvin_fall;
    break;
    case CharacterType::RUHAAN:
      name = "RUHAAN";
      idleSprite = character_ruhaan_idle;
      walkSprite = character_ruhaan_run;
      jumpSprite = character_ruhaan_jump;
      fallSprite = character_ruhaan_fall;
    break;
    case CharacterType::NOLA:
      name = "NOLA";
      idleSprite = character_nola_idle;
      walkSprite = character_nola_run;
      jumpSprite = character_nola_jump;
      fallSprite = character_nola_fall;
    break;
    case CharacterType::PINEAPPLE_MURPHY:
      name = "PINEAPPLE MURPHY";
      idleSprite = character_pineappleMurphy_idle;
      walkSprite = character_pineappleMurphy_run;
      jumpSprite = character_pineappleMurphy_jump;
      fallSprite = character_pineappleMurphy_fall;
    break;
    case CharacterType::LYLE:
      name = "LYLE";
      idleSprite = character_lyle_idle;
      walkSprite = character_lyle_run;
      jumpSprite = character_lyle_jump;
      fallSprite = character_lyle_fall;
      frameChangeInterval_Idle = 50;
    break;
    case CharacterType::VAL:
      name = "VAL";
      idleSprite = character_val_idle;
      walkSprite = character_val_run;
      jumpSprite = character_val_jump;
      fallSprite = character_val_fall;
    break;
    case CharacterType::ROBOT_STEVE:
      name = "ROBOT STEVE";
      idleSprite = character_robotsteve_idle;
      walkSprite = character_robotsteve_run;
      jumpSprite = character_robotsteve_jump;
      fallSprite = character_robotsteve_fall;
    break;

  }

  setState(state);
}

void Character::setState(CharacterState newState) {
  currentFrame = 0;
  frameCounter = 0;
  state = newState;
  switch (state) {
    case IDLE:
      currentSprite = idleSprite;
      frameCount = frameCount_Idle;
      frameChangeInterval = frameChangeInterval_Idle;
      break;
    case WALK:
      currentSprite = walkSprite;
      frameCount = frameCount_Walking;
      frameChangeInterval = frameChangeInterval_Walking;
      break;
    case JUMP:
      currentSprite = jumpSprite;
      frameCount = frameCount_Jump;
      frameChangeInterval = frameChangeInterval_Jump;
      break;
    case FALL:
      currentSprite = fallSprite;
      frameCount = frameCount_Fall;
      frameChangeInterval = frameChangeInterval_Fall;
      break;
  }
}

void Character::startJump() {
  if (state != JUMP) {
    velocityY = jumpPower;  // Negative value for upward movement
    setState(JUMP);
  }
}

void Character::draw(Arduboy2 &arduboy) {

  switch (state) {
    case IDLE:
      break;
    case WALK:
      break;
    case JUMP:
      y += velocityY;          // Move the character up or down
      velocityY += gravity;    // Apply gravity
      if (y >= groundLevel) {  // Check if character lands
        y = groundLevel;       // Reset position to ground
        setState(WALK);
      }
      break;
    case FALL:
      y += velocityY;
      velocityY += gravity;
      break;
  }

  if (currentSprite != nullptr) {
    Sprites::drawSelfMasked(x, y, currentSprite, currentFrame);
  }
}
