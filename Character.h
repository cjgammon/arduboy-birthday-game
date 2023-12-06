#ifndef CHARACTER_H
#define CHARACTER_H

#include <Arduboy2.h>

class Character {
public:
    Character(int initialX, int initialY);
    virtual ~Character();

    enum CharacterState {
        IDLE,
        WALK,
        JUMP,
        FALL,
    };

    void update(Arduboy2 &arduboy);
    void setState(CharacterState newState);
    void draw(Arduboy2 &arduboy);
        // Getter methods for x and y
    int getX() const { return x; }
    int getY() const { return y; }

    // Setter methods for x and y
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void setGround(int newGround) {groundLevel = newGround;}
    
    const char* getName() const { return name; } // Getter for the character's name
    int getLives() const { return lives; }

    void startJump();

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

    CharacterState state;
    int x; // X coordinate
    int y; // Y coordinate
    
    int lives;
public:
    const char* name; // Character's name
};

#endif // CHARACTER_H

