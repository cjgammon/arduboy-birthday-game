// Implementation of GameModel class
#import "GameModel.h"

GameModel::GameModel() {
    // Initialize your game data members here
}

GameModel& GameModel::getInstance() {
    static GameModel instance; // Create a single instance
    return instance;
}

// Implementation of GameModel class

int GameModel::getLives() const {
  return lives;
}

void GameModel::setLives(int newLives) {
  lives = newLives;
}

int GameModel::getScore() const {
  return score;
}

void GameModel::setScore(int newScore) {
  score = newScore;
}

Character* GameModel::getSelectedCharacter() {
  return selectedCharacter;
}

void GameModel::setSelectedCharacter(Character* character) {
  selectedCharacter = character;
}

GameModel& gameModel = GameModel::getInstance(); // Define the global instance

