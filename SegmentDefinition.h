#ifndef SEGMENTDEFINITION_H
#define SEGMENTDEFINITION_H

#define GROUND_DEFINITION_SIZE 24
#define MAX_ENEMIES_PER_SEGMENT 3  // Adjust as needed
#define MAX_COINS_PER_SEGMENT 5   // Adjust as needed

struct EnemyDefinition {
    uint8_t enemyType;
    uint8_t x;
};

struct EnemyTypeDefinition {
    uint8_t y;// all enemies of a specific type are at the same 'y' position in this game.  this is what this y refers to.
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
                28, // y
                32, // sprite width
                32, // sprite height
                14, // collider x
                20, // collider y
                10// collider radius
        },
        {
                // 1 - spider
                0,  // y
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
    uint8_t groundArray[GROUND_DEFINITION_SIZE / 8];
    EnemyDefinition enemies[MAX_ENEMIES_PER_SEGMENT];  // Define MAX_ENEMIES_PER_SEGMENT as needed
    CoinDefinition coins[MAX_COINS_PER_SEGMENT];       // Define MAX_COINS_PER_SEGMENT as needed
};

// change this if you add/remove groundDefinitions.
#define GROUND_DEFINITION_COUNT 2
const SegmentDefinition groundDefinitions[GROUND_DEFINITION_COUNT] PROGMEM = {
        // segment 0
        {
                {255, 255, 195},
                {

                },
                {
                }
        },
        // segment 1
        {
                {127, 248, 176},
                {
                },
                {
                }
        },
};

#endif // SEGMENTDEFINITION_H

