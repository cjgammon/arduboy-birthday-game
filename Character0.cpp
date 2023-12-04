// Character0.cpp
#include "sprites.h"
#include "Character0.h"

Character0::Character0(int initialX, int initialY) : Character(initialX, initialY) {
    this->name = "JONAS";

    this->idleSprite = character0idle;
    this->walkSprite = character0walk;

    this->frameCount_Idle = 2;
    this->frameCount_Walking = 9;
    this->frameCount_Jump = 1;

    this->frameChangeInterval_Idle = 10;
    this->frameChangeInterval_Walking = 6;
    this->frameChangeInterval_Jump = 1;

    setState(CharacterState::IDLE);
}

Character0::~Character0() {
    // Add any necessary cleanup code here
}
