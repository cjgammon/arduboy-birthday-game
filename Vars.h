
#ifndef VARS_H
#define VARS_H

#include <avr/pgmspace.h>

#include "SegmentDefinition.h"

//#define DEBUG_DRAW_HITBOXES

#define PLAYER_W 16
#define PLAYER_H 32
#define PLAYER_HALF_W 8
#define PLAYER_HALF_H 16


#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define HALF_SCREEN_WIDTH SCREEN_WIDTH / 2
#define CHAR_WIDTH 6 // character width in pixels including inter-character spacing
#define GROUND_SIZE 6 


extern int selectedCharacter;
extern int lives;
extern int score;
extern float globalSpeedMultiplier;
extern bool godModeEnabled;

extern float cameraX;
extern float cameraY;

#endif // VARS_H

