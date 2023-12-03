#ifndef GAME_UI_H
#define GAME_UI_H

#include <Arduboy2.h>

class GameUI {
public:
    GameUI(); // Constructor

    void init(); // Initialization method
    void draw(Arduboy2 &arduboy); // Drawing method

    // Add other methods to update UI elements as needed

private:
    // Define UI elements and properties here

    // Define UI element drawing functions here
    void drawName(Arduboy2 &arduboy);
    void drawScore(Arduboy2 &arduboy);
    void drawLives(Arduboy2 &arduboy);
    // ...
};

#endif // GAME_UI_H
