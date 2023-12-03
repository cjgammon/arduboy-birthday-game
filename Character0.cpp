// Character0.cpp
#include "sprites.h"
#include "Character0.h"

Character0::Character0(int initialX, int initialY) : Character(initialX, initialY) {
    this->idleSprite = character0idle;
    this->idleFrameCount = 2;

    this->walkSprite = character0walk;
    this->walkFrameCount = 9;

    this->frameChangeInterval = 10;
    this->state = CharacterState::IDLE;
}

Character0::~Character0() {
    // Add any necessary cleanup code here
}
