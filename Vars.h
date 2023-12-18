
#ifndef VARS_H
#define VARS_H

#include <avr/pgmspace.h>
#include "SegmentDefinition.h"
#include <Arduboy2.h>

extern Arduboy2 arduboy;

#define DEBUG_DRAW_VARS
//#define DEBUG_DRAW_HITBOXES

#define SOUND_ENABLED

#define PLAYER_W 16
#define PLAYER_HALF_W 8
#define PLAYER_HALF_H 16

extern uint8_t screenWidth;
#define SCREEN_HEIGHT 64
#define SCREEN_WIDTH 128
#define CHAR_WIDTH 6
#define GROUND_SIZE 6


extern uint8_t selectedCharacter;

#define LIVES_ENABLED
#ifdef LIVES_ENABLED
extern int lives;
#endif

extern int score;
extern float globalSpeedMultiplier;

#define CHEAT_MODE_ENABLED

#ifdef CHEAT_MODE_ENABLED
enum CheatMode : uint8_t {
    Disabled,
    GodMode,
    NoFalling,
    NoCollisions,
    Total
};
extern int cheatMode;
#endif

extern float cameraX;
extern float cameraY;

extern int highScoreBaseAddress;
extern int highScoreAddressMultiplier;


uint8_t getTextWidthInPixels(char* text);

#endif // VARS_H

