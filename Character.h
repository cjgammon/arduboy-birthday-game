#ifndef CHARACTER_H
#define CHARACTER_H

#include "Vars.h"
#include "sprites.h"
#include <Arduboy2.h>

enum CharacterType : uint8_t {
  JONAS,
  HENRY,
  MASON,
  RUHAAN,
  JAXON,
  NOLA,

  TOTAL_CHARACTERS
};

enum CharacterState : uint8_t {
    IDLE,
    WALK,
    JUMP,
    DESCEND,
    FALL,
};

class Character {
public:
    Character(int initialX, int initialY, CharacterType initialType);
    virtual ~Character();

    void setState(CharacterState newState);
    bool isAlive() { return state != CharacterState::FALL; }

    CharacterType getCharacterType() const { return characterType; };
    void setType(CharacterType newType);

    void update(Arduboy2 &arduboy);
    void draw(Arduboy2 &arduboy);

    int getX() const { return x; }
    int getY() const { return y; }
    int getCenterX() { return x + getHalfSpriteWidth(); }
    int getCenterY() { return y + getHalfSpriteHeight(); }
    int getRadius() { return radius; }

    int getSpriteWidth() { return PLAYER_W; }// todo :: make variable?
    int getHalfSpriteWidth() { return PLAYER_HALF_W; }// todo :: make variable/cache?
    int getHalfSpriteHeight() { return PLAYER_HALF_H; }// todo :: make variable/cache?

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void setGround(int newGround) {groundLevel = newGround;}

    const char* getName() const { return name; } // Getter for the character's name
    const char* getDescription() const { return description; }
    int getLives() const { return lives; }

    bool isJumping() { return state == CharacterState::JUMP || state == CharacterState::DESCEND; }
    float velocityY = 0;

protected:

    const uint8_t* currentSprite;
    const uint8_t* idleSprite;
    const uint8_t* walkSprite;
    const uint8_t* jumpSprite;
    const uint8_t* fallSprite;
    const uint8_t* descendSprite;

    int frameCount;
    int frameCount_Idle;
    int frameCount_Walking;
    int frameCount_Jump;
    int frameCount_Descend;
    int frameCount_Fall;

    int groundLevel;
    

    float frameCounterRaw;
    int currentFrame;
    int frameChangeInterval;
    int frameChangeInterval_Idle;
    int frameChangeInterval_Walking;
    int frameChangeInterval_Jump;
    int frameChangeInterval_Descend;
    int frameChangeInterval_Fall;

    CharacterType characterType;
    CharacterState state;
    float x; // X coordinate
    float y; // Y coordinate
    float radius;
    
    int lives;
public:
    const char* name; // Character's name
    const char* description;

private:
    float gravity = 0.3;
    float currentGravity = 0.3;
    float jumpPower = -5.0;
    float extraJumpPower = -5.0;
// jump damping - this controls how much your jump speed is reduced when you release the jump button.
    float stopJumpDamping = 0.5;
// jump buffer - this provides a little bit of a window before we hit the ground for a second jump to register.
// this is a lot more user friendly because people always mis-time when your character is actually 'on the ground'
    float jumpBufferLengthInFrames = 30.0;
    float jumpBufferCountRaw = 0.0;
// how many jumps do they have
// this is like double jumps in awesomenauts (i.e. lonestar) - the ability to jump again while in mid air.
    int jumpCount = 1;
    int jumpsRemaining = 1;
    bool canHover = false;
};

#endif // CHARACTER_H

