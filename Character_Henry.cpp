#include "Character_Henry.h"

#include "sprites.h"

Character_Henry::Character_Henry(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "HENRY";

  this->idleSprite = character_Henry_idle;
  this->walkSprite = character_Henry_run;
  this->jumpSprite = character_Henry_jump;
  this->fallSprite = character_Henry_fall;

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

Character_Henry::~Character_Henry() {
  // Add any necessary cleanup code here
}


//