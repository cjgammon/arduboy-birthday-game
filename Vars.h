
#ifndef VARS_H
#define VARS_H

#include <avr/pgmspace.h>

#define DEBUG_DRAW_HITBOXES

#define PLAYER_W 16
#define PLAYER_H 32
#define PLAYER_HALF_W 8
#define PLAYER_HALF_H 16


#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define HALF_SCREEN_WIDTH SCREEN_WIDTH / 2
#define CHAR_WIDTH 6 // character width in pixels including inter-character spacing
#define GROUND_SIZE 6 

#define GROUND_DEFINITION_SIZE 24
#define MAX_ENEMIES_PER_SEGMENT 3  // Adjust as needed
#define MAX_COINS_PER_SEGMENT 5   // Adjust as needed

struct EnemyDefinition {
    uint8_t type;
    uint8_t x;
    uint8_t y;
};

struct EnemyTypeDefinition {
    uint8_t id;
    uint8_t spriteWidth;
    uint8_t spriteHeight;
    uint8_t colliderX;
    uint8_t colliderY;
    uint8_t colliderRadius;
};

// !!! the EnemyType enum and the enemyDefinitions must be in the same order!
enum EnemyType {
    NONE,
    TROLL,
    SPIDER,
    // leave this.
    TOTAL
};

const EnemyTypeDefinition enemyTypeDefinitions[EnemyType::TOTAL] PROGMEM = {
        {69},// first one is NONE, intentionally left empty.
        {
                123,// 0 - troll
                32, // sprite width
                32, // sprite height
                14, // collider x
                20, // collider y
                10// collider radius
        },
        {
                456,// 1 - spider
                32, // sprite width
                32, // sprite height
                12, // collider x
                20, // collider y
                10// collider radius
        },
};

struct Coin {
    uint8_t show;  
    uint8_t x;
    uint8_t y;
};

struct SegmentDefinition {
    uint8_t groundArray[GROUND_DEFINITION_SIZE];
    EnemyDefinition enemies[MAX_ENEMIES_PER_SEGMENT];  // Define MAX_ENEMIES_PER_SEGMENT as needed
    Coin coins[MAX_COINS_PER_SEGMENT];       // Define MAX_COINS_PER_SEGMENT as needed
};

// change this if you add/remove groundDefinitions.
#define GROUND_DEFINITION_COUNT 6
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
        {1, 20, 28}, // Enemy 1
      },
      {

      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
         //{2, 20, 0}, // Enemy 1
      },
      {

      }
    },
    {
      // Ground array for segment 0
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      // Enemies for segment 0
      {
        //{1, 50, 28}, // Enemy 1
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

#endif // VARS_H

