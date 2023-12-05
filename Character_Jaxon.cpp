#include "Character_Jaxon.h"

#include "sprites.h"

Character_Jaxon::Character_Jaxon(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "JAXON";

  this->idleSprite = character_Jaxon_idle;
  this->walkSprite = character_Jaxon_run;
  this->jumpSprite = character_Jaxon_jump;
  this->fallSprite = character_Jaxon_fall;

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

Character_Jaxon::~Character_Jaxon() {
  // Add any necessary cleanup code here
}


//