#ifndef CHARACTER_H
#define CHARACTER_H

#include <Arduboy2.h>

class Character {
public:
    Character();
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

protected:
    const uint8_t* sprite;
    int frameCount;
    int frameCounter;
    int currentFrame;
    int frameChangeInterval;
    CharacterState state;
};

#endif // CHARACTER_H

