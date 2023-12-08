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
