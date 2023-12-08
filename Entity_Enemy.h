// Entity_Ground.h
#ifndef ENTITY_ENEMY_H
#define ENTITY_ENEMY_H

#include "Vars.h"
#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"

enum EnemyType {
    TROLL,
    SPIDER,
};

class Entity_Enemy : public Entity {

public:
    Entity_Enemy();

    void update() override;
    void draw(Arduboy2 &arduboy) override;
};

#endif // ENTITY_ENEMY_H
