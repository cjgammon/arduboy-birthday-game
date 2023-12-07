#include "Character.h"

float gravity = 0.3;
float jumpPower = -5.0;
// jump damping - this controls how much your jump speed is reduced when you release the jump button.
float stopJumpDamping = 0.5;
// jump buffer - this provides a little bit of a window before we hit the ground for a second jump to register.
// this is a lot more user friendly because people always mis-time when your character is actually 'on the ground'
int jumpBufferLengthInFrames = 30;
int jumpBufferCount = 0;

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

  // manage jump buffer
  if (arduboy.justPressed(A_BUTTON)) {
    jumpBufferCount = jumpBufferLengthInFrames;
  }
  else if (arduboy.justReleased(A_BUTTON))
  {
    jumpBufferCount = 0;
  }
  else
  {
    jumpBufferCount--;
  }

  if (jumpBufferCount > 0 && state != JUMP) {
    jumpBufferCount = 0;
    velocityY = jumpPower;  // Negative value for upward movement
    setState(JUMP);
  }

  if (state == JUMP && velocityY < 0.0 && arduboy.justReleased(A_BUTTON)) {
    velocityY *= stopJumpDamping;
  }

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
  gravity = 0.3;
  jumpPower = -5.0;
  stopJumpDamping = 0.5;

  switch (type) {
    case CharacterType::JONAS:
      name = "JONAS";
      frameCount_Walking = 10;
      idleSprite = character_jonas_idle;
      walkSprite = character_jonas_run;
      jumpSprite = character_jonas_jump;
      fallSprite = character_jonas_fall;
      jumpPower = -4.0;
      gravity = 0.2;
      stopJumpDamping = 0.3;
    break;
    case CharacterType::HENRY:
      name = "HENRY";
      frameCount_Walking = 6;
      idleSprite = character_skaterboy_idle;
      walkSprite = character_skaterboy_run;
      jumpSprite = character_skaterboy_jump;
      fallSprite = character_skaterboy_fall;
      jumpPower = -6.0;
      gravity = 0.35;
    break;
    case CharacterType::JAXON:
      name = "JAXON";
      frameCount_Idle = 4;
      frameChangeInterval_Idle = 16;
      idleSprite = character_caliban_idle;
      walkSprite = character_caliban_run;
      jumpSprite = character_caliban_jump;
      fallSprite = character_caliban_fall;
      jumpPower = -4.9;
      gravity = 0.22;
      stopJumpDamping = 0.1;
    break;
    case CharacterType::MASON:
      name = "MASON";
      idleSprite = character_calvin_idle;
      walkSprite = character_calvin_run;
      jumpSprite = character_calvin_jump;
      fallSprite = character_calvin_fall;
      jumpPower = -2.5;
      gravity = 0.18;
    break;
    case CharacterType::RUHAAN:
      name = "RUHAAN";
      idleSprite = character_lyle_idle;
      walkSprite = character_lyle_run;
      jumpSprite = character_lyle_jump;
      fallSprite = character_lyle_fall;
      frameChangeInterval_Idle = 50;
      jumpPower = -4.0;
      gravity = 0.25;
      stopJumpDamping = 0.2;
    break;
    case CharacterType::NOLA:
      name = "NOLA";
      idleSprite = character_nola_idle;
      walkSprite = character_nola_run;
      jumpSprite = character_nola_jump;
      fallSprite = character_nola_fall;
      frameCount_Walking = 9;
      jumpPower = -4.5;
      gravity = 0.18;
      stopJumpDamping = 0.5;
    break;
    case CharacterType::PINEAPPLE_MURPHY:
      name = "PINEAPPLE MURPHY";
      idleSprite = character_pineappleMurphy_idle;
      walkSprite = character_pineappleMurphy_run;
      jumpSprite = character_pineappleMurphy_jump;
      fallSprite = character_pineappleMurphy_fall;
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
