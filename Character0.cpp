// Character0.cpp
#include "sprites.h"
#include "Character0.h"

Character0::Character0(int initialX, int initialY) : Character(initialX, initialY) {
    this->sprite = character0idle;
    this->frameCount = 2;
    this->frameChangeInterval = 10;
    this->state = CharacterState::IDLE;
}

Character0::~Character0() {
    // Add any necessary cleanup code here
}
