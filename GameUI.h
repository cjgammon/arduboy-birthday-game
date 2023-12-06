#ifndef GAME_UI_H
#define GAME_UI_H

#include "Vars.h"
#include "sprites.h"
#include <Arduboy2.h>

class GameUI {
public:
    GameUI(); // Constructor

    void init(char *initialName, int initialLives, int initialMaxLives); // Initialization method
    void draw(Arduboy2 &arduboy); // Drawing method

    void setName(char *newName) {name = newName;};
    void setLives(int newLives) {lives = newLives;};
    void setMaxLives(int newMaxLives) {maxLives = newMaxLives;};

private:
    char *name;
    int lives;
    int maxLives;
    
    // Define UI element drawing functions here
    void drawName(Arduboy2 &arduboy);
    void drawScore(Arduboy2 &arduboy);
    void drawLives(Arduboy2 &arduboy);
};

#endif // GAME_UI_H
