#include "Character_Ruhaan.h"

#include "sprites.h"

Character_Ruhaan::Character_Ruhaan(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "RUHAAN";

  this->idleSprite = character_ruhaan_idle;
  this->walkSprite = character_ruhaan_run;
  this->jumpSprite = character_ruhaan_jump;
  this->fallSprite = character_ruhaan_fall;

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

Character_Ruhaan::~Character_Ruhaan() {
  // Add any necessary cleanup code here
}


//