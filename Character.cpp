#include "Character.h"
#include "sprites.h"

Character::Character() {}

Character::~Character() {}

int frameCounter = 0;

void Character::init(const uint8_t* sprite, int frameCount, int frameChangeInterval) {
    this->sprite = sprite;
    this->frameCount = frameCount;
    this->frameChangeInterval = frameChangeInterval;
}

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
    state = newState;
}

void Character::draw(Arduboy2 &arduboy) {
    Sprites::drawOverwrite(0, 0, sprite, currentFrame);
}

