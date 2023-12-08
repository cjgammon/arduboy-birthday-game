#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprites.h"
#include <Arduboy2.h>

enum CharacterType {
  JONAS,
  HENRY,
  MASON,
  RUHAAN,
  JAXON,
  NOLA,
  ROBOT_STEVE,
  PINEAPPLE_MURPHY,
  VAL,
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
    int getCenterX() { return x + getHalfSpriteWidth(); }
    int getSpriteWidth() { return 16; }// todo :: make variable?
    int getHalfSpriteWidth() { return 8; }// todo :: make variable/cache?

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void setGround(int newGround) {groundLevel = newGround;}

    const char* getName() const { return name; } // Getter for the character's name
    const char* getDescription() const { return description; }
    int getLives() const { return lives; }

protected:

    const uint8_t* currentSprite;
    const uint8_t* idleSprite;
    const uint8_t* walkSprite;
    const uint8_t* jumpSprite;
    const uint8_t* fallSprite;

    int frameCount;
    int frameCount_Idle;
    int frameCount_Walking;
    int frameCount_Jump;
    int frameCount_Fall;

    int groundLevel;
    float velocityY = 0;

    int frameCounter;
    int currentFrame;
    int frameChangeInterval;
    int frameChangeInterval_Idle;
    int frameChangeInterval_Walking;
    int frameChangeInterval_Jump;
    int frameChangeInterval_Fall;

    CharacterType type;
    CharacterState state;
    int x; // X coordinate
    int y; // Y coordinate
    
    int lives;
public:
    const char* name; // Character's name
    const char* description;
};

#endif // CHARACTER_H

