// Entity_Ground.h
#ifndef ENTITY_GROUND_H
#define ENTITY_GROUND_H

#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"

class Entity_Ground : public Entity {
public:
    Entity_Ground();
    Entity_Ground(int initialX, int initialY, int initialWidth);
    void update() override;
    void draw(Arduboy2 &arduboy) override;
};

#endif // ENTITY_GROUND_H
