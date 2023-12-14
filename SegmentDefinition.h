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
enum EnemyType : uint8_t {
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
                44, // y
                19, // sprite width
                16, // sprite height
                7, // collider x
                8, // collider y
                7// collider radius
        },
        {
                // 1 - spider
                0,  // y
                32, // sprite width
                32, // sprite height
                12, // collider x
                21, // collider y
                6// collider radius
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

const SegmentDefinition flatGround PROGMEM = {
        {255, 255, 255}, {}, {}
};

// change this if you add/remove groundDefinitions.
#define GROUND_DEFINITION_COUNT 40
const SegmentDefinition groundDefinitions[GROUND_DEFINITION_COUNT] PROGMEM = {
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
        // segment 0
        {
                {255, 255, 255},
                {
                        {2, 48}, // Enemy
                        {1, 113}, // Enemy
                },
                {
                }
        },
        // segment 1
        {
                {255, 7, 224},
                {
                },
                {
                }
        },
        // segment 2
        {
                {255, 255, 255},
                {
                        {2, 12}, // Enemy
                        {2, 36}, // Enemy
                },
                {
                }
        },
        // segment 3
        {
                {255, 255, 255},
                {
                },
                {
                }
        },
};

#endif // SEGMENTDEFINITION_H

