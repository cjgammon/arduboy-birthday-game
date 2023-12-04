// GamePlayState.h
#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include "GameState.h"
#include "GameUI.h"
#include "Character.h"
#include "Ground.h" // Include the Ground header


class GamePlayState : public GameState {
public:
    void init() override;
    void update(Arduboy2 &arduboy) override;
    void draw(Arduboy2 &arduboy) override;
    void cleanup() override;
private:
    GameUI gameUI; // Create an instance of the GameUI class 
    Character* playerCharacter;


    // Use an array to store Ground objects
    static const int maxGroundObjects = 10; // Adjust the maximum number as needed
    Ground groundObjects[maxGroundObjects]; // Store multiple Ground objects

    int numGroundObjects; // Keep track of the number of ground objects

};



#endif
