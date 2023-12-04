// GamePlayState.cpp
#include "GamePlayState.h"
#include "Character0.h"
#include "Character1.h"
#include "GameModel.h"


void GamePlayState::init() {
    // Initialization code

    //playerCharacter = new Character0(0, 30);
    playerCharacter = gameModel.getSelectedCharacter();
    playerCharacter->setX(0);
    playerCharacter->setState(Character::WALKING);
    gameModel.setLives(playerCharacter->getLives());

    gameUI.init();

    
   // Initialize Ground objects
    numGroundObjects = 3; // Adjust as needed

    // Define Ground objects' positions, widths, and speeds here
    groundObjects[0] = Ground(0, 60, 40, 1);
    groundObjects[1] = Ground(50, 60, 30, 2);
    groundObjects[2] = Ground(90, 60, 40, 3);
    
}

void GamePlayState::update(Arduboy2 &arduboy) {
    // Update logic
    if (arduboy.justPressed(B_BUTTON)) {
      if (stateChangeCallback != nullptr) {
          stateChangeCallback(STATE_START_MENU);
      }
    }

    if (arduboy.justPressed(A_BUTTON)) {

    }


    playerCharacter->update(arduboy);

        // Update Ground objects
    for (int i = 0; i < numGroundObjects; i++) {
        groundObjects[i].update();
    }
    
}

void GamePlayState::draw(Arduboy2 &arduboy) {

    // Drawing code
    playerCharacter->draw(arduboy);
    gameUI.draw(arduboy);

        // Draw Ground objects
    for (int i = 0; i < numGroundObjects; i++) {
        groundObjects[i].draw(arduboy);
    }
    
}

void GamePlayState::cleanup() {
    // Drawing code
}