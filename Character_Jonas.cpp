#include "Character_Jonas.h"

#include "sprites.h"

Character_Jonas::Character_Jonas(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "JONAS";

  this->idleSprite = character_jonas_idle;
  this->walkSprite = character_jonas_run;
  this->jumpSprite = character_jonas_jump;
  this->fallSprite = character_jonas_fall;

  this->frameCount_Idle = 2;
  this->frameCount_Walking = 9;
  this->frameCount_Jump = 1;
  this->frameCount_Fall = 1;

  this->frameChangeInterval_Idle = 10;
  this->frameChangeInterval_Walking = 6;
  this->frameChangeInterval_Jump = 1;
  this->frameChangeInterval_Fall = 1;

  setState(CharacterState::IDLE);
}

Character_Jonas::~Character_Jonas() {
  // Add any necessary cleanup code here
}


//