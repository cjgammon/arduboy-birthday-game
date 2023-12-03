// GamePlayState.cpp
#include "GamePlayState.h"
#include "Character.h"
#include "Character0.h"
#include "Character1.h"

Character* playerCharacter;

void GamePlayState::init() {
    // Initialization code

    //TODO:: define which character in a model somewhere to keep track of and use here.
    playerCharacter = new Character0(0, 0);
    playerCharacter->setState(Character::WALKING);
}

void GamePlayState::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(A_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          stateChangeCallback(STATE_START_MENU);
      }
    }

    playerCharacter->update(arduboy);
}

void GamePlayState::draw(Arduboy2 &arduboy) {
    //arduboy.clear();

    // Drawing code
    playerCharacter->draw(arduboy);
}

void GamePlayState::cleanup() {
    // Drawing code
    delete playerCharacter; // Delete character instance
}