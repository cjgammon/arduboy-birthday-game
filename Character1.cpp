// Character1.cpp
#include "sprites.h"
#include "Character1.h"

Character1::Character1(int initialX, int initialY) : Character(initialX, initialY) {
    this->name = "HENRY";

    this->idleSprite = character1idle;
    this->idleFrameCount = 2;

    this->walkSprite = character1walk;
    this->walkFrameCount = 9;
    
    this->frameChangeInterval = 6;
    this->state = CharacterState::IDLE;
}

Character1::~Character1() {
    // Add any necessary cleanup code here
}
