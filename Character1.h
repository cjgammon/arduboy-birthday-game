#ifndef CHARACTER1_H
#define CHARACTER1_H

#include <Arduboy2.h>
#include "Character.h"

class Character1 : public Character {
public:
    Character1(int initialX, int initialY);
    ~Character1();

    // You can add any additional methods or properties specific to Character0 here

private:
    const uint8_t* predefinedSprite;
};

#endif // CHARACTER1_H
