#include "Character_Mason.h"

#include "sprites.h"

Character_Mason::Character_Mason(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "MASON";

  this->idleSprite = character_mason_idle;
  this->walkSprite = character_mason_run;
  this->jumpSprite = character_mason_jump;
  this->fallSprite = character_mason_fall;

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

Character_Mason::~Character_Mason() {
  // Add any necessary cleanup code here
}


//