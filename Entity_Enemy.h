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
    Entity_Enemy(uint8_t initialEnemyType, uint8_t initialX, uint8_t initialY, uint8_t initialWidth, uint8_t initialHeight, uint8_t cx, uint8_t cy, uint8_t cr);

    void update(int newOffsetX);
    void draw(Arduboy2 &arduboy) override;
    int getAbsoluteX();

    int getCollisionX();
    int getCollisionY();
    int getCollisionR();

    EnemyType enemyType;

private:
    int offsetX;
    int collisionX;
    int collisionY;
    int collisionR;
};

#endif // ENTITY_ENEMY_H
