
#ifndef VARS_H
#define VARS_H

#include <avr/pgmspace.h>


#define SCREEN_WIDTH 128 // character width in pixels including inter-character spacing
#define SCREEN_HEIGHT 64
#define CHAR_WIDTH 6 // character width in pixels including inter-character spacing
#define GROUND_SIZE 6 

#define GROUND_DEFINITION_COUNT 3
#define GROUND_DEFINITION_SIZE 4

const int groundDefinitions[GROUND_DEFINITION_COUNT][GROUND_DEFINITION_SIZE] PROGMEM = {
    {1, 1, 1, 1},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
};

#endif // VARS_H

