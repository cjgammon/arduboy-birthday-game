// Character1.cpp
#include "sprites.h"
#include "Character1.h"

Character1::Character1(int initialX, int initialY) : Character(initialX, initialY) {
    this->sprite = character0walk;
    this->frameCount = 9;
    this->frameChangeInterval = 10;
    this->state = CharacterState::IDLE;
}

Character1::~Character1() {
    // Add any necessary cleanup code here
}
