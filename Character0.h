#ifndef CHARACTER0_H
#define CHARACTER0_H

#include <Arduboy2.h>
#include "Character.h"

class Character0 : public Character {
public:
    Character0(int initialX, int initialY);
    ~Character0();

    // You can add any additional methods or properties specific to Character0 here

private:
    const uint8_t* predefinedSprite;
};

#endif // CHARACTER0_H
