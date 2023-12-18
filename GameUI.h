#ifndef GAME_UI_H
#define GAME_UI_H

#include "Vars.h"
#include "sprites.h"
#include <Arduboy2.h>
#include "Sound.h"

class GameUI {
public:
    GameUI(); // Constructor

    void init(char *initialName
#ifdef LIVES_ENABLED
              , int initialLives, int initialMaxLives
#endif
    );

    void draw(); // Drawing method

    void setName(char *newName) {name = newName;};

    void incScore() {
      score += 1;
#ifdef SOUND_ENABLED
      sound.tone(score %2 == 0 ? NOTE_B7 : NOTE_AS7, 40);// coin collect
#endif
    };
    void setScore(int newScore) {score = newScore;};
    int getScore() {return score;};

#ifdef LIVES_ENABLED
    void setLives(int newLives) {lives = newLives;};
    void setMaxLives(int newMaxLives) {maxLives = newMaxLives;};
#endif

private:
    char *name;
    int lives;
    int maxLives;
    
    // Define UI element drawing functions here
    void drawName();
    void drawScore();
    void drawLives();
    void drawSpeed();
};

#endif // GAME_UI_H
