#ifndef GAMEMODEL_H
#define GAMEMODEL_H

class GameModel {
public:
    // Public methods to access and manipulate game data
    static GameModel& getInstance();

private:
    // Private constructors to prevent instantiation
    GameModel();

    // Private data members to store game state, variables, and character selection
    // Add your game data members here
    int selectedCharacter;

public:
    // Define accessor and mutator methods for game data
    // Example:
    // int getScore() const;
    // void setScore(int score);

    // Character selection methods and data
    // Example:
    int getSelectedCharacter();
    void setSelectedCharacter(int);
};

#endif
