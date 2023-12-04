// Character1.cpp
#include "sprites.h"
#include "Character1.h"

Character1::Character1(int initialX, int initialY) : Character(initialX, initialY) {
    this->name = "HENRY";

    this->idleSprite = character1idle;
    this->walkSprite = character1walk;

    this->frameCount_Idle = 2;
    this->frameCount_Walking = 9;
    this->frameCount_Jump = 1;

    this->frameChangeInterval_Idle = 10;
    this->frameChangeInterval_Walking = 6;
    this->frameChangeInterval_Jump = 1;

    setState(CharacterState::IDLE);
}

Character1::~Character1() {
    // Add any necessary cleanup code here
}
