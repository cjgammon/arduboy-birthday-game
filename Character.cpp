#include "Character.h"
#include "CharacterDefinition.h"
#include "Vars.h"

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
    jumpBufferCountRaw = jumpBufferLengthInFrames;
  }
  else if (jumpJustReleased)
  {
    jumpBufferCountRaw = 0.0;
  }
  else
  {
    jumpBufferCountRaw -= 1 * globalSpeedMultiplier;
  }

  if (jumpsRemaining > 0)
  {
    if (
        // if not jumping, and the player is trying to jump, jump!
        ((!isJumping() && state != CharacterState::FALL) && jumpBufferCountRaw > 0)
        // if jumping, and we still have jumps remaining, and the player is trying to jump, and the player is still kinda jumping upward, jump!
        || (isJumping() && jumpJustPressed)
        )
    {
      jumpBufferCountRaw = 0;
      velocityY = (jumpsRemaining == jumpCount) ? jumpPower : extraJumpPower;
      jumpsRemaining--;
      currentGravity = gravity;
      setState(CharacterState::JUMP);
    }
  }
  else if (canHover)
  {
    if (jumpJustPressed)
    {
      currentGravity = 0.0;
      velocityY = 0.33;
    }
    else if (jumpJustReleased)
    {
      currentGravity = gravity;
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
      y += velocityY * globalSpeedMultiplier;
      velocityY += currentGravity * globalSpeedMultiplier;
      if (y >= groundLevel)
      {
        y = groundLevel;
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
  characterType = newType;

  CharacterDefinition characterDefinition;

  if (characterType == CharacterType::JONAS)
  {
    memcpy_P(&characterDefinition, &CharacterDefinition_Jonas, sizeof(CharacterDefinition));
    idleSprite = character_jonas_idle;
    walkSprite = character_jonas_run;
    jumpSprite = character_jonas_jump;
    descendSprite = character_jonas_jump;
    fallSprite = character_jonas_fall;
  }
  else if (characterType == CharacterType::HENRY)
  {
    memcpy_P(&characterDefinition, &CharacterDefinition_Henry, sizeof(CharacterDefinition));
    idleSprite = character_skaterboy_idle;
    walkSprite = character_skaterboy_run;
    jumpSprite = character_skaterboy_jump;
    descendSprite = character_skaterboy_jump;
    fallSprite = character_skaterboy_fall;
  }
  else if (characterType == CharacterType::JAXON)
  {
    memcpy_P(&characterDefinition, &CharacterDefinition_Jaxon, sizeof(CharacterDefinition));
    idleSprite = character_caliban_idle;
    walkSprite = character_caliban_run;
    jumpSprite = character_caliban_jump;
    descendSprite = character_caliban_jump;
    fallSprite = character_caliban_fall;
  }
  else if (characterType == CharacterType::MASON)
  {
    memcpy_P(&characterDefinition, &CharacterDefinition_Mason, sizeof(CharacterDefinition));
    idleSprite = character_calvin_idle;
    walkSprite = character_calvin_run;
    jumpSprite = character_calvin_jump;
    descendSprite = character_calvin_jump;
    fallSprite = character_calvin_fall;
  }
  else if (characterType == CharacterType::RUHAAN)
  {
    memcpy_P(&characterDefinition, &CharacterDefinition_Ruhaan, sizeof(CharacterDefinition));
    idleSprite = character_lyle_idle;
    walkSprite = character_lyle_run;
    jumpSprite = character_lyle_jump;
    descendSprite = character_lyle_jump;
    fallSprite = character_lyle_fall;
  }
  else if (characterType == CharacterType::NOLA)
  {
    memcpy_P(&characterDefinition, &CharacterDefinition_Nola, sizeof(CharacterDefinition));
    idleSprite = character_nola_idle;
    walkSprite = character_nola_run;
    jumpSprite = character_nola_jump;
    descendSprite = character_nola_descend;
    fallSprite = character_nola_fall;
  }

  // copy character definition
  name = characterDefinition.name;
  description = characterDefinition.description;

  frameCount_Idle = characterDefinition.frameCount_Idle;
  frameCount_Walking = characterDefinition.frameCount_Walking;
  frameCount_Jump = characterDefinition.frameCount_Jump;
  frameCount_Descend = characterDefinition.frameCount_Descend;
  frameCount_Fall = characterDefinition.frameCount_Fall;

  frameChangeInterval_Idle = characterDefinition.frameChangeInterval_Idle;
  frameChangeInterval_Walking = characterDefinition.frameChangeInterval_Walking;
  frameChangeInterval_Jump = characterDefinition.frameChangeInterval_Jump;
  frameChangeInterval_Descend = characterDefinition.frameChangeInterval_Descend;
  frameChangeInterval_Fall = characterDefinition.frameChangeInterval_Fall;

  radius = characterDefinition.radius;
  gravity = characterDefinition.gravity;
  jumpPower = characterDefinition.jumpPower;
  extraJumpPower = characterDefinition.extraJumpPower;
  stopJumpDamping = characterDefinition.stopJumpDamping;
  jumpCount = characterDefinition.jumpCount;
  canHover = characterDefinition.canHover;



  setState(state);
}

void Character::setState(CharacterState newState) {
  currentFrame = 0;
  frameCounterRaw = 0.0;
  state = newState;
  switch (state) {
    case CharacterState::IDLE:
      currentSprite = idleSprite;
      frameCount = frameCount_Idle;
      frameChangeInterval = frameChangeInterval_Idle;
      jumpsRemaining = jumpCount;
      break;
    case CharacterState::WALK:
      frameCounterRaw = 2.0;// jonas looks better here than starting at 0 when landing from a jump. could re-order his animation?
      currentFrame = 2;
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
  frameCounterRaw += 1 * globalSpeedMultiplier;
  if (frameCounterRaw >= frameChangeInterval) {
    currentFrame++;
    if (currentFrame >= frameCount) {
      currentFrame = 0;
    }
    frameCounterRaw -= frameChangeInterval;
  }

  if (currentSprite != nullptr) {
    Sprites::drawSelfMasked(x, y, currentSprite, currentFrame);
  }

#ifdef DEBUG_DRAW_HITBOXES
    arduboy.drawCircle(getCenterX(), getCenterY(), radius);
#endif
}
