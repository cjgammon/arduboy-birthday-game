#include "Character.h"

Character::Character(int initialX, int initialY) {
  x = initialX;
  y = initialY;
  currentFrame = 0;
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

void Character::draw(Arduboy2 &arduboy) {
    const uint8_t* currentSprite = nullptr;

    switch (state) {
        case IDLE:
            currentSprite = idleSprite;
            break;
        case WALKING:
            currentSprite = walkSprite;
            break;
    }

    if (currentSprite != nullptr) {
      Sprites::drawSelfMasked(x, y, currentSprite, currentFrame);
    }
}

