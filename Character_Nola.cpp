#include "Character_Nola.h"

#include "sprites.h"

Character_Nola::Character_Nola(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "NOLA";

  this->idleSprite = character_Nola_idle;
  this->walkSprite = character_Nola_run;
  this->jumpSprite = character_Nola_jump;
  this->fallSprite = character_Nola_fall;

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

Character_Nola::~Character_Nola() {
  // Add any necessary cleanup code here
}


//