#include "Character.h"

Character::Character(int initialX, int initialY) {
    x = initialX;
    y = initialY;
    currentFrame = 0;
}

Character::~Character() {}

int frameCounter = 0;

void Character::init(const uint8_t* sprite, int frameCount, int frameChangeInterval) {
    this->sprite = sprite;
    this->frameCount = frameCount;
    this->frameChangeInterval = frameChangeInterval;
    this->state = CharacterState::IDLE; // Use '::' instead of '.'
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
    //Sprites::drawOverwrite(x, y, sprite, currentFrame);
    Sprites::drawSelfMasked(x, y, sprite, currentFrame);
}

