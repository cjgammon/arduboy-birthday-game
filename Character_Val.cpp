#include "Character_Val.h"

#include "sprites.h"

Character_Val::Character_Val(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "VAL";

  this->idleSprite = character_Val_idle;
  this->walkSprite = character_Val_run;
  this->jumpSprite = character_Val_jump;
  this->fallSprite = character_Val_fall;

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

Character_Val::~Character_Val() {
  // Add any necessary cleanup code here
}


//