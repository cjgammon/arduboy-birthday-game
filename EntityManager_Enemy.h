#ifndef ENTITYMANAGER_ENEMY_H
#define ENTITYMANAGER_ENEMY_H

#include "EntityManager.h"
#include "Entity_Enemy.h"

class EntityManager_Enemy : public EntityManager {
public:
    EntityManager_Enemy();
    void update(Arduboy2 &arduboy, int xDelta) override;

private:

};

#endif // ENTITYMANAGER_ENEMY_H
