#ifndef SEGMENTDEFINITION_H
#define SEGMENTDEFINITION_H

#define GROUND_DEFINITION_SIZE 24
#define MAX_ENEMIES_PER_SEGMENT 3  // Adjust as needed
#define MAX_COINS_PER_SEGMENT 5   // Adjust as needed

struct EnemyDefinition {
    uint8_t enemyType;
    uint8_t x;
    uint8_t y;
};

struct EnemyTypeDefinition {
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

const EnemyTypeDefinition enemyTypeDefinitions[EnemyType::TOTAL] = {
        {
        },// first one is NONE, intentionally left empty.
        {
                // 0 - troll
                32, // sprite width
                32, // sprite height
                14, // collider x
                20, // collider y
                10// collider radius
        },
        {
                // 1 - spider
                32, // sprite width
                32, // sprite height
                12, // collider x
                20, // collider y
                10// collider radius
        },
};

struct CoinDefinition {
    uint8_t show;  
    uint8_t x;
    uint8_t y;
};

struct SegmentDefinition {
    uint8_t groundArray[GROUND_DEFINITION_SIZE];
    EnemyDefinition enemies[MAX_ENEMIES_PER_SEGMENT];  // Define MAX_ENEMIES_PER_SEGMENT as needed
    CoinDefinition coins[MAX_COINS_PER_SEGMENT];       // Define MAX_COINS_PER_SEGMENT as needed
};

// change this if you add/remove groundDefinitions.
#define GROUND_DEFINITION_COUNT 5
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
         {2, 20, 0}, // Enemy 1
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

#endif // SEGMENTDEFINITION_H

