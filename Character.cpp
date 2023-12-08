#include "Character.h"
#include "Vars.h"

// todo :: all this stuff should be properties on the character probably.  but adding it here is a little easier rn
float gravity = 0.3;
float jumpPower = -5.0;
float extraJumpPower = -5.0;
// jump damping - this controls how much your jump speed is reduced when you release the jump button.
float stopJumpDamping = 0.5;
// jump buffer - this provides a little bit of a window before we hit the ground for a second jump to register.
// this is a lot more user friendly because people always mis-time when your character is actually 'on the ground'
int jumpBufferLengthInFrames = 30;
int jumpBufferCount = 0;
// how many jumps do they have
// this is like double jumps in awesomenauts (i.e. lonestar) - the ability to jump again while in mid air.
int jumpCount = 1;
int jumpsRemaining = 1;

Character::Character(int initialX, int initialY, CharacterType initialType) {
  x = initialX;
  y = initialY;

  groundLevel = initialY;

  velocityY = 0;
  currentFrame = 0;
  lives = 3;

  setType(initialType);
  setState(CharacterState::IDLE);
}

Character::~Character() {}

void Character::update(Arduboy2 &arduboy) {
  bool jumpJustPressed = arduboy.justPressed(A_BUTTON);
  bool jumpJustReleased = arduboy.justReleased(A_BUTTON);

  // manage jump buffer
  if (jumpJustPressed)
  {
    jumpBufferCount = jumpBufferLengthInFrames;
  }
  else if (jumpJustReleased)
  {
    jumpBufferCount = 0;
  }
  else
  {
    jumpBufferCount--;
  }

  if (jumpsRemaining > 0)
  {
    if (
        // if not jumping, and the player is trying to jump, jump!
        ((!isJumping() && state != CharacterState::FALL) && jumpBufferCount > 0)
        // if jumping, and we still have jumps remaining, and the player is trying to jump, and the player is still kinda jumping upward, jump!
        || (isJumping() && jumpJustPressed)
        )
    {
      jumpBufferCount = 0;
      velocityY = (jumpsRemaining == jumpCount) ? jumpPower : extraJumpPower;
      jumpsRemaining--;
      setState(CharacterState::JUMP);
    }
  }

  // releasing the jump button should dampen your jump.
  if (isJumping() && velocityY < 0.0 && jumpJustReleased) {
    velocityY *= stopJumpDamping;
  }

  // update physics
  switch (state)
  {
    case CharacterState::IDLE:
      break;
    case CharacterState::WALK:
      break;
    case CharacterState::JUMP:
    case CharacterState::DESCEND:
      y += velocityY * globalSpeedMultiplier;          // Move the character up or down
      velocityY += gravity * globalSpeedMultiplier;    // Apply gravity
      if (y >= groundLevel) {  // Check if character lands
        y = groundLevel;       // Reset position to ground
        setState(CharacterState::WALK);
      }
      else if (velocityY > 0 && state != CharacterState::DESCEND)
      {
        setState(CharacterState::DESCEND);
      }
      break;
    case CharacterState::FALL:
      y += velocityY * globalSpeedMultiplier;
      velocityY += gravity * globalSpeedMultiplier;
      break;
  }
}

void Character::setType(CharacterType newType) {
  type = newType;

  frameCount_Idle = 2;
  frameCount_Walking = 9;
  frameCount_Jump = 1;
  frameCount_Descend = 1;
  frameCount_Fall = 1;
  frameChangeInterval_Idle = 10;
  frameChangeInterval_Walking = 6;
  frameChangeInterval_Jump = 1;
  frameChangeInterval_Descend = 1;
  frameChangeInterval_Fall = 1;
  gravity = 0.3;
  jumpPower = -5.0;
  extraJumpPower = -5.0;
  stopJumpDamping = 0.5;
  jumpCount = 1;
  jumpsRemaining = 1;

  switch (type) {
    case CharacterType::JONAS:
      name = "JONAS";
      description = "ABILITY: Hover";
      frameCount_Walking = 10;
      idleSprite = character_jonas_idle;
      walkSprite = character_jonas_run;
      jumpSprite = character_jonas_jump;
      descendSprite = character_jonas_jump;
      fallSprite = character_jonas_fall;
      jumpPower = -4.0;
      gravity = 0.2;
      stopJumpDamping = 0.3;
      jumpCount = 8;
      jumpsRemaining = 8;
      extraJumpPower = -0.5;
      // notes: kinda normal single jump, then you can press the butotn a bunch to sorta hover.
    break;
    case CharacterType::HENRY:
      name = "HENRY";
      description = "ABILITY: Double Ollie";
      frameCount_Walking = 6;
      idleSprite = character_skaterboy_idle;
      walkSprite = character_skaterboy_run;
      jumpSprite = character_skaterboy_jump;
      descendSprite = character_skaterboy_jump;
      fallSprite = character_skaterboy_fall;
      jumpPower = -4.0;
      gravity = 0.35;
      jumpCount = 2;
      jumpsRemaining = 2;
      extraJumpPower = -5.0;
      // notes: pretty basic double jump
    break;
    case CharacterType::JAXON:
      name = "JAXON";
      description = "ABILITY: Butt Stomp";
      frameCount_Idle = 4;
      frameChangeInterval_Idle = 16;
      idleSprite = character_caliban_idle;
      walkSprite = character_caliban_run;
      jumpSprite = character_caliban_jump;
      descendSprite = character_caliban_jump;
      fallSprite = character_caliban_fall;
      jumpPower = -4.9;
      gravity = 0.22;
      jumpCount = 2;
      jumpsRemaining = 2;
      extraJumpPower = 9;// positive on purpose!
      stopJumpDamping = 0.1;
      // notes: big floaty jump, pressing the button again sends you downward quickly, like a butt stomp/ground pound.
    break;
    case CharacterType::MASON:
      name = "MASON";
      description = "ABILITY: Double Jump";
      idleSprite = character_calvin_idle;
      walkSprite = character_calvin_run;
      jumpSprite = character_calvin_jump;
      descendSprite = character_calvin_jump;
      fallSprite = character_calvin_fall;
      jumpPower = -1.7;
      extraJumpPower = -3.2;
      gravity = 0.18;
      jumpCount = 2;
      jumpsRemaining = 2;
      // notes: weak single jump, nice double jump
    break;
    case CharacterType::RUHAAN:
      name = "RUHAAN";
      description = "ABILITY: Dragon Punch";
      idleSprite = character_lyle_idle;
      walkSprite = character_lyle_run;
      jumpSprite = character_lyle_jump;
      descendSprite = character_lyle_jump;
      fallSprite = character_lyle_fall;
      frameChangeInterval_Idle = 20;
      jumpPower = -4.0;
      gravity = 0.25;
      stopJumpDamping = 0.2;
      // notes: very basic single jump.  perhaps he can punch through enemies while he's jumping??
    break;
    case CharacterType::NOLA:
      name = "NOLA";
      description = "ABILITY: Triple Jump";
      idleSprite = character_nola_idle;
      walkSprite = character_nola_run;
      jumpSprite = character_nola_jump;
      descendSprite = character_nola_descend;
      fallSprite = character_nola_fall;
      frameCount_Walking = 8;
      frameCount_Idle = 3;
      frameCount_Descend = 2;
      frameChangeInterval_Descend = 5;
      jumpPower = -3.5;
      gravity = 0.18;
      stopJumpDamping = 0.5;
      jumpCount = 3;
      jumpsRemaining = 3;
      extraJumpPower = -2.5;
      // notes: floaty jump, with a couple additional flutters
    break;
  }

  setState(state);
}

void Character::setState(CharacterState newState) {
  currentFrame = 0;
  frameCounter = 0;
  state = newState;
  switch (state) {
    case CharacterState::IDLE:
      currentSprite = idleSprite;
      frameCount = frameCount_Idle;
      frameChangeInterval = frameChangeInterval_Idle;
      jumpsRemaining = jumpCount;
      break;
    case CharacterState::WALK:
      currentSprite = walkSprite;
      frameCount = frameCount_Walking;
      frameChangeInterval = frameChangeInterval_Walking;
      jumpsRemaining = jumpCount;
      break;
    case CharacterState::JUMP:
      currentSprite = jumpSprite;
      frameCount = frameCount_Jump;
      frameChangeInterval = frameChangeInterval_Jump;
      break;
    case CharacterState::DESCEND:
      currentSprite = descendSprite;
      frameCount = frameCount_Descend;
      frameChangeInterval = frameChangeInterval_Descend;
      break;
    case CharacterState::FALL:
      currentSprite = fallSprite;
      frameCount = frameCount_Fall;
      frameChangeInterval = frameChangeInterval_Fall;
      break;
  }
}

void Character::draw(Arduboy2 &arduboy)
{
  // calculate new animation frame.
  frameCounter += 1 * globalSpeedMultiplier;
  if (frameCounter >= frameChangeInterval) {
    currentFrame++;
    if (currentFrame >= frameCount) {
      currentFrame = 0;
    }
    frameCounter = 0;
  }

  if (currentSprite != nullptr) {
    Sprites::drawSelfMasked(x, y, currentSprite, currentFrame);
  }
}
