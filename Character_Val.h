//
// Created by chase on 12/4/23.
//

#ifndef ARDUBOY_BIRTHDAY_GAME_CHARACTER_VAL_H
#define ARDUBOY_BIRTHDAY_GAME_CHARACTER_VAL_H


#include <Arduboy2.h>
#include "Character.h"

class Character_Val : public Character {
public:
    Character_Val(int initialX, int initialY);
    ~Character_Val();
};


#endif //ARDUBOY_BIRTHDAY_GAME_CHARACTER_VAL_H
