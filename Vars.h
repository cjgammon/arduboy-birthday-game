
#ifndef VARS_H
#define VARS_H

#include <avr/pgmspace.h>

#define SCREEN_WIDTH 128 // character width in pixels including inter-character spacing
#define SCREEN_HEIGHT 64
#define CHAR_WIDTH 6 // character width in pixels including inter-character spacing
#define GROUND_SIZE 6 


#define GROUND_DEFINITION_COUNT 4
#define GROUND_DEFINITION_SIZE 24
#define MAX_ENEMIES_PER_SEGMENT 3  // Adjust as needed
#define MAX_COINS_PER_SEGMENT 5   // Adjust as needed

struct Enemy {
    uint8_t type;
    uint8_t x;
    uint8_t y;
    uint8_t width;
    uint8_t height;
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
        {1, 0, 28, 32, 32}, // Enemy 1
      },
      {

      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
      // Enemies for segment 0
      {
      },
      {

      }
    },
        {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
         {2, 20, 0, 32, 32}, // Enemy 1
      },
      {

      }
    },
};


#endif // VARS_H

