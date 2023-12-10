
#ifndef VARS_H
#define VARS_H

#include <avr/pgmspace.h>

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

struct Enemy {
    uint8_t type;
    uint8_t x;
    uint8_t y;
    uint8_t width;
    uint8_t height;
    uint8_t cx;
    uint8_t cy;
    uint8_t cr;
};

struct Coin {
    uint8_t show;  
    uint8_t x;
    uint8_t y;
};

struct SegmentDefinition {
    uint8_t groundArray[GROUND_DEFINITION_SIZE];
    Enemy enemies[MAX_ENEMIES_PER_SEGMENT];  // Define MAX_ENEMIES_PER_SEGMENT as needed
    Coin coins[MAX_COINS_PER_SEGMENT];       // Define MAX_COINS_PER_SEGMENT as needed
};

const SegmentDefinition groundDefinitions[GROUND_DEFINITION_COUNT] PROGMEM = {
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {

      },
      {

      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
      },
      {

      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
      // Enemies for segment 0
      {
        {1, 20, 28, 32, 32, 14, 20, 10}, // Enemy 1
      },
      {

      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
         {2, 20, 0, 32, 32, 12, 20, 10}, // Enemy 1
      },
      {

      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
        {1, 50, 28, 32, 32, 14, 20, 10}, // Enemy 1
      },
      {

      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
      },
      {

      }
    },
};

extern int selectedCharacter;
extern int lives;
extern int score;
extern float globalSpeedMultiplier;
extern bool godModeEnabled;
extern bool debugDraw;

#endif // VARS_H

