
#ifndef VARS_H
#define VARS_H

#include <avr/pgmspace.h>

#include "SegmentDefinition.h"

#define PLAYER_W 16
#define PLAYER_HALF_W 8
#define PLAYER_H 32
#define PLAYER_HALF_H 16


#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define HALF_SCREEN_WIDTH SCREEN_WIDTH / 2
#define CHAR_WIDTH 6 // character width in pixels including inter-character spacing
#define GROUND_SIZE 6 

#define GROUND_DEFINITION_COUNT 6
#define GROUND_DEFINITION_SIZE 24
#define MAX_ENEMIES_PER_SEGMENT 3  // Adjust as needed
#define MAX_COINS_PER_SEGMENT 5   // Adjust as needed


extern int selectedCharacter;
extern int lives;
extern int score;
extern float globalSpeedMultiplier;
extern bool godModeEnabled;
extern bool debugDraw;

extern int cameraX;
extern int cameraY;

#endif // VARS_H

