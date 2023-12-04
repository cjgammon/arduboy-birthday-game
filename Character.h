#ifndef CHARACTER_H
#define CHARACTER_H

#include <Arduboy2.h>

class Character {
public:
    Character(int initialX, int initialY);
    virtual ~Character();

    enum CharacterState {
        IDLE,
        WALKING,
        JUMPING,
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
    
    const char* getName() const { return name; } // Getter for the character's name
    int getLives() const { return lives; }

    void startJump();

protected:

    const uint8_t* idleSprite;
    const uint8_t* walkSprite;

    int idleFrameCount;
    int walkFrameCount;

    int groundLevel;
    float velocityY = 0;

    //int frameCount;
    int frameCounter;
    int currentFrame;
    int frameChangeInterval;
    CharacterState state;
    int x; // X coordinate
    int y; // Y coordinate
    const char* name; // Character's name
    int lives;
};

#endif // CHARACTER_H

