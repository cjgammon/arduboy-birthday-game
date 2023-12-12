// Entity_Ground.h
#ifndef ENTITY_ENEMY_H
#define ENTITY_ENEMY_H

#include "Vars.h"
#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"

class Entity_Enemy : public Entity {

public:
    Entity_Enemy(uint8_t initialEnemyType, uint8_t initialX, uint8_t initialY);

    void update(int newOffsetX);
    void draw(Arduboy2 &arduboy) override;
    int getAbsoluteX();

    int getCollisionX();
    int getCollisionY();

    EnemyDefinition getEnemyDefinition() { return enemyDefinitions[enemyType]; }
    int getColliderX() { return getEnemyDefinition().colliderX; }
    int getColliderY() { return getEnemyDefinition().colliderY; }
    int getColliderRadius() { return getEnemyDefinition().colliderRadius; }

    EnemyType enemyType;

private:
    int offsetX;
};

#endif // ENTITY_ENEMY_H
