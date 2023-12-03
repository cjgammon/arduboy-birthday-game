// GamePlayState.h
#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#import "Character.h"

class GameModel {
public:
    // Public methods to access and manipulate game data
    static GameModel& getInstance();

private:
    // Private constructors to prevent instantiation
  GameModel();

  // Private data members to store game state, variables, and character selection
  int score;
  int lives;
  Character* selectedCharacter; // Declare a pointer to Character

public:
    // Define accessor and mutator methods for game data
    int getScore() const;
    void setScore(int score);

    int getLives() const;
    void setLives(int score);

    Character* getSelectedCharacter();
    void setSelectedCharacter(Character* character);
};

extern GameModel& gameModel; // Declare the global instance

#endif
