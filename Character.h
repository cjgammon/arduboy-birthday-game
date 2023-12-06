#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprites.h"
#include <Arduboy2.h>

enum CharacterType {
  JONAS,
  HENRY,
  MASON,
  RUHAAN,
  JAXON
};

class Character {
public:
    Character(int initialX, int initialY, CharacterType initialType);
    virtual ~Character();

    enum CharacterState {
        IDLE,
        WALK,
        JUMP,
        FALL,
    };

    void setState(CharacterState newState);

    CharacterType getType() const { return type; };
    void setType(CharacterType newType);

    void update(Arduboy2 &arduboy);
    void draw(Arduboy2 &arduboy);

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void setGround(int newGround) {groundLevel = newGround;}
    
    const char* getName() const { return name; } // Getter for the character's name
    int getLives() const { return lives; }

    void startJump();

protected:

    const uint8_t* idleSprite;
    const uint8_t* walkSprite;

    int frameCount;
    int frameCount_Idle;
    int frameCount_Walking;
    int frameCount_Jump;

    int groundLevel;
    float velocityY = 0;

    int frameCounter;
    int currentFrame;
    int frameChangeInterval;
    int frameChangeInterval_Idle;
    int frameChangeInterval_Walking;
    int frameChangeInterval_Jump;

    CharacterType type;
    CharacterState state;
    int x; // X coordinate
    int y; // Y coordinate
    const char* name; // Character's name
    int lives;
};

#endif // CHARACTER_H

