
#ifndef VARS_H
#define VARS_H

#include <avr/pgmspace.h>

#define SCREEN_WIDTH 128 // character width in pixels including inter-character spacing
#define SCREEN_HEIGHT 64
#define CHAR_WIDTH 6 // character width in pixels including inter-character spacing
#define GROUND_SIZE 6 

#define GROUND_DEFINITION_COUNT 4
#define GROUND_DEFINITION_SIZE 24
#define MAX_ENEMIES_PER_SEGMENT 5  // Adjust as needed
#define MAX_COINS_PER_SEGMENT 10   // Adjust as needed

struct Enemy {
    uint8_t type;
    uint8_t x;
    uint8_t y;
    uint8_t width;
    uint8_t height;
};

struct Coin {
    uint8_t x;
    uint8_t y;
};

struct SegmentDefinition {
    uint8_t groundArray[GROUND_DEFINITION_SIZE];
    Enemy enemies[MAX_ENEMIES_PER_SEGMENT];  // Define MAX_ENEMIES_PER_SEGMENT as needed
    Coin coins[MAX_COINS_PER_SEGMENT];       // Define MAX_COINS_PER_SEGMENT as needed
};
/*
const uint8_t groundDefinitions[GROUND_DEFINITION_COUNT][GROUND_DEFINITION_SIZE] PROGMEM = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1}, 
};
*/

const SegmentDefinition groundDefinitions[GROUND_DEFINITION_COUNT] PROGMEM = {
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
        {0, 0, 0, 10, 10}, // Enemy 1
        // ... other enemies
      },
        // Coins for segment 0
      {
        {10, 10}, // Coin 1
        // ... other coins
      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
        {0, 0, 0, 10, 10}, // Enemy 1
        // ... other enemies
      },
      // Coins for segment 0
      {
        {10, 10}, // Coin 1
        // ... other coins
      }
    },
        {
      // Ground array for segment 0
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
        {0, 0, 0, 10, 10}, // Enemy 1
        // ... other enemies
      },
      // Coins for segment 0
      {
        {10, 10}, // Coin 1
        // ... other coins
      }
    },
        {
      // Ground array for segment 0
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
        {0, 0, 0, 10, 10}, // Enemy 1
        // ... other enemies
      },
      // Coins for segment 0
      {
        {10, 10}, // Coin 1
        // ... other coins
      }
    },
};


#endif // VARS_H

