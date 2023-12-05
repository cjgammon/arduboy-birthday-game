#include "Character.h"

const float gravity = 0.3;
const float jumpPower = -5.0;

Character::Character(int initialX, int initialY) {
  x = initialX;
  y = initialY;

  groundLevel = initialY;

  velocityY = 0;
  currentFrame = 0;
  lives = 3;
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

void Character::setState(CharacterState newState) {
  currentFrame = 0;
  frameCounter = 0;
  state = newState;
  switch (state) {
      case IDLE:
          frameCount = frameCount_Idle;
          frameChangeInterval = frameChangeInterval_Idle;
          break;
      case WALK:
          frameCount = frameCount_Walking;
          frameChangeInterval = frameChangeInterval_Walking;
          break;
      case JUMP:
          frameCount = frameCount_Jump;
          frameChangeInterval = frameChangeInterval_Jump;
          break;
      case FALL:
          frameCount = frameCount_Jump;
          frameChangeInterval = frameChangeInterval_Jump;
          break;

  }
}

void Character::startJump() {
  if (state != JUMP) {
      velocityY = jumpPower; // Negative value for upward movement
      setState(JUMP);
    }
}

void Character::draw(Arduboy2 &arduboy) {
    const uint8_t* currentSprite = nullptr;

    switch (state) {
        case IDLE:
            currentSprite = idleSprite;
            break;
        case WALK:
            currentSprite = walkSprite;
            break;
        case JUMP:
          currentSprite = walkSprite;

          y += velocityY; // Move the character up or down
          velocityY += gravity; // Apply gravity
          if (y >= groundLevel) { // Check if character lands
            y = groundLevel; // Reset position to ground
            setState(WALK);
          }
          break;
        case FALL:
          currentSprite = walkSprite;
          y += velocityY;
          velocityY += gravity;
          break;
    }
  
    if (currentSprite != nullptr) {
      Sprites::drawSelfMasked(x, y, currentSprite, currentFrame);
    }
}

