// Implementation of GameModel class
#import "GameModel.h"

GameModel::GameModel() {
    // Initialize your game data members here
    selectedCharacter = 0;
}

GameModel& GameModel::getInstance() {
    static GameModel instance; // Create a single instance
    return instance;
}

// Implementation of GameModel class

// Example data members and methods
// int GameModel::getScore() const {
//     return score;
// }
//
// void GameModel::setScore(int newScore) {
//     score = newScore;
// }
//
int GameModel::getSelectedCharacter() {
  return selectedCharacter;
}

void GameModel::setSelectedCharacter(int characterIndex) {
  selectedCharacter = characterIndex;
}
