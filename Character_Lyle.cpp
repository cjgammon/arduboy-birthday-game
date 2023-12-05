#include "Character_Lyle.h"

#include "sprites.h"

Character_Lyle::Character_Lyle(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "LYLE";

  this->idleSprite = character_lyle_idle;
  this->walkSprite = character_lyle_run;
  this->jumpSprite = character_lyle_jump;
  this->fallSprite = character_lyle_fall;

  this->frameCount_Idle = 2;
  this->frameCount_Walking = 9;
  this->frameCount_Jump = 1;
  this->frameCount_Fall = 1;

  this->frameChangeInterval_Idle = 50;
  this->frameChangeInterval_Walking = 6;
  this->frameChangeInterval_Jump = 1;
  this->frameChangeInterval_Fall = 1;

  setState(CharacterState::IDLE);
}

Character_Lyle::~Character_Lyle() {
  // Add any necessary cleanup code here
}


//