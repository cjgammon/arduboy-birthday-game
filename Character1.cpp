// Character1.cpp
#include "sprites.h"
#include "Character1.h"

Character1::Character1(int initialX, int initialY) : Character(initialX, initialY) {
    this->predefinedSprite = character0walk;
    // You can add any additional initialization specific to Character0 here
    this->sprite = character0walk;
    this->frameCount = 9;
    this->frameChangeInterval = 10;
    this->state = CharacterState::IDLE; // Use '::' instead of '.'
}

Character1::~Character1() {
    // Add any necessary cleanup code here
}
