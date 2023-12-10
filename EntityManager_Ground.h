#ifndef ENTITYMANAGER_GROUND_H
#define ENTITYMANAGER_GROUND_H

#include "EntityManager.h"
#include "Entity_Ground.h"

class EntityManager_Ground : public EntityManager {
public:
    EntityManager_Ground();
    void update(Arduboy2 &arduboy, float xDelta) override;
    bool isGroundAt(int x); // Check if there is ground at the given coordinates
    bool enemyCollision(int playerX, int playerY, int playerRadius);

private:
    void recycleGroundEntity(int index);
    int findMaxRightX();
};

#endif // ENTITYMANAGER_GROUND_H
