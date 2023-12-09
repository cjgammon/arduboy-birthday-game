// Entity_Ground.h
#ifndef ENTITY_ENEMY_H
#define ENTITY_ENEMY_H

#include "Vars.h"
#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"

enum EnemyType {
    NONE,
    TROLL,
    SPIDER,
};

class Entity_Enemy : public Entity {

public:
    Entity_Enemy(uint8_t initialEnemyType, uint8_t initialX, uint8_t initialY, uint8_t initialWidth, uint8_t initialHeight);

    void update() override;
    void draw(Arduboy2 &arduboy, int offsetX);

    EnemyType enemyType;
};

#endif // ENTITY_ENEMY_H