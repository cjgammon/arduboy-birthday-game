// Entity_Ground.h
#ifndef ENTITY_GROUND_H
#define ENTITY_GROUND_H

#include "Vars.h"
#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"

class Entity_Ground : public Entity {
private:
    int groundArray[GROUND_DEFINITION_SIZE]; // Member array

public:
    Entity_Ground();
    Entity_Ground(int initialX, int initialY, int arrayIndex);
    //Entity_Ground(int initialX, int initialY, const int inputArray[GROUND_DEFINITION_SIZE]);
    //Entity_Ground(int initialX, int initialY, int (&array)[groundDefinitionSize]);

    void update() override;
    void draw(Arduboy2 &arduboy) override;
};

#endif // ENTITY_GROUND_H
