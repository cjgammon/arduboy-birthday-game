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

int frameCounter = 0;

void Character::update(Arduboy2 &arduboy) {
  int frameCount = 0;
  switch (state) {
    case IDLE:
      frameCount = idleFrameCount;
      break;
    case WALKING:
      frameCount = walkFrameCount;
      break;
    case JUMPING:
      frameCount = walkFrameCount;
      break;
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

void Character::setState(CharacterState newState) {
  currentFrame = 0;
  frameCounter = 0;
  state = newState;
}

void Character::startJump() {
  if (state != JUMPING) {
      velocityY = jumpPower; // Negative value for upward movement
      setState(JUMPING);
    }
}

void Character::draw(Arduboy2 &arduboy) {
    const uint8_t* currentSprite = nullptr;

    switch (state) {
        case IDLE:
            currentSprite = idleSprite;
            break;
        case WALKING:
            currentSprite = walkSprite;
            break;
        case JUMPING:
          currentSprite = walkSprite;

          y += velocityY; // Move the character up or down
          velocityY += gravity; // Apply gravity
          if (y >= groundLevel) { // Check if character lands
            y = groundLevel; // Reset position to ground
            setState(WALKING);
          }
          break;
        case FALL:
          y += gravity;
          break;
    }

    if (currentSprite != nullptr) {
      Sprites::drawSelfMasked(x, y, currentSprite, currentFrame);
    }
}

