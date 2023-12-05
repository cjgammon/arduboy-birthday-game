#include "Character_PineappleMurphy.h"

#include "sprites.h"

Character_PineappleMurphy::Character_PineappleMurphy(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "PINEAPPLE MURPHY";

  this->idleSprite = character_pineappleMurphy_idle;
  this->walkSprite = character_pineappleMurphy_run;
  this->jumpSprite = character_pineappleMurphy_jump;
  this->fallSprite = character_pineappleMurphy_fall;

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

Character_PineappleMurphy::~Character_PineappleMurphy() {
  // Add any necessary cleanup code here
}


//