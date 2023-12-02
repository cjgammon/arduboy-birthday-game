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

    void init(const uint8_t* sprite, int frameCount, int frameChangeInterval);
    void update(Arduboy2 &arduboy);
    void setState(CharacterState newState);
    void draw(Arduboy2 &arduboy);
        // Getter methods for x and y
    int getX() const { return x; }
    int getY() const { return y; }

    // Setter methods for x and y
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

protected:
    const uint8_t* sprite;
    int frameCount;
    int frameCounter;
    int currentFrame;
    int frameChangeInterval;
    CharacterState state;
    int x; // X coordinate
    int y; // Y coordinate
};

#endif // CHARACTER_H

