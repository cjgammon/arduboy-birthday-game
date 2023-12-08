#include "EntityManager_Ground.h"

EntityManager_Ground::EntityManager_Ground() : EntityManager() {
    // Additional initialization for ground entities, if needed
}

void EntityManager_Ground::update(Arduboy2 &arduboy, int xDelta) {
    // Override update method to specifically handle ground entities
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr && entities[i]->getType() == EntityType::GROUND) {
            entities[i]->move(xDelta, 0);

            if (entities[i]->getX() + entities[i]->getWidth() < 0) {
                recycleGroundEntity(i);
            }

            entities[i]->update();
        }
    }
}

void EntityManager_Ground::recycleGroundEntity(int index) {
    // Specific logic to recycle ground entities
    // This can include repositioning the entity and rearranging it in the array
}

bool EntityManager_Ground::isGroundAt(int x) {
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr) {
            if (entities[i] -> getType() == EntityType::GROUND) {
              Entity_Ground* groundEntity = static_cast<Entity_Ground*>(entities[i]);

              if (groundEntity -> isGroundAt(x)) {
                return true;
              }
            }
        }
    }
    return false;
}
 

// Implement other methods specific to ground entities if needed
