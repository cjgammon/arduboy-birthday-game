#include "Character_RobotSteve.h"

#include "sprites.h"

Character_RobotSteve::Character_RobotSteve(int initialX, int initialY) : Character(initialX, initialY) {
  this->name = "ROBOT STEVE";

  this->idleSprite = character_robotsteve_idle;
  this->walkSprite = character_robotsteve_run;
  this->jumpSprite = character_robotsteve_jump;
  this->fallSprite = character_robotsteve_fall;

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

Character_RobotSteve::~Character_RobotSteve() {
  // Add any necessary cleanup code here
}


//