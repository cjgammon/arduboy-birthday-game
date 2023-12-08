#include "EntityManager_Enemy.h"

EntityManager_Enemy::EntityManager_Enemy() : EntityManager() {
    // Additional initialization for ground entities, if needed
}

void EntityManager_Enemy::update(Arduboy2 &arduboy, int xDelta) {
    // Override update method to specifically handle ground entities
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr && entities[i]->getType() == EntityType::ENEMY) {
            entities[i]->move(xDelta, 0);
            entities[i]->update();
        }
    }
}



// Implement other methods specific to ground entities if needed
