// GameStateManager.cpp
#include "GameStateManager.h"

void GameStateManager::setState(GameState *state) {
    currentState = state;
    currentState->init();
}

void GameStateManager::update(Arduboy2 &arduboy) {
    currentState->update(arduboy);
}

void GameStateManager::draw(Arduboy2 &arduboy) {
    currentState->draw(arduboy);
}

GameState* GameStateManager::getCurrentState() {
    return currentState;
}