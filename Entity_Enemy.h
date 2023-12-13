// Entity_Ground.h
#ifndef ENTITY_ENEMY_H
#define ENTITY_ENEMY_H

#include "Vars.h"
#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"

class Entity_Enemy : public Entity {

public:
    Entity_Enemy();
    void setData(const EnemyDefinition& enemyDefinition, float segmentX);

    void update(float newX);
    void draw(Arduboy2 &arduboy) override;

    int getCollisionX();
    int getCollisionY();

    const EnemyTypeDefinition& getEnemyTypeDefinition() { return enemyTypeDefinitions[enemyType]; }
    int getColliderX() { return getEnemyTypeDefinition().colliderX; }
    int getColliderY() { return getEnemyTypeDefinition().colliderY; }
    int getColliderRadius() { return getEnemyTypeDefinition().colliderRadius; }

    EnemyType enemyType;

    bool enabled;

private:
    int positionInSegmentX;
};

#endif // ENTITY_ENEMY_H
