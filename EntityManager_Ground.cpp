#include "EntityManager_Ground.h"

EntityManager_Ground::EntityManager_Ground() {
  init();
}

void EntityManager_Ground::init() {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    entities[i] = nullptr;
  }
  numEntities = 0;
}


void EntityManager_Ground::update(Arduboy2 &arduboy) {
    // Override update method to specifically handle ground entities
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr && entities[i]->getEntityType() == EntityType::GROUND) {
            entities[i]->move(cameraX, 0.0);
            if (entities[i]->getX() + entities[i]->getWidth() < 0) {
                recycleGroundEntity(i);
            }
            entities[i]->update();
        }
    }
}

void EntityManager_Ground::draw(Arduboy2 &arduboy) {
  for (int i = 0; i < numEntities; i++) {
    if (entities[i] != nullptr) {
      entities[i]->draw(arduboy);
    }
  }
}

void EntityManager_Ground::cleanup() {
  // Iterate through the array of entity pointers
  for (int i = 0; i < numEntities; i++) {
    // Check if the pointer is not null
    if (entities[i] != nullptr) {
      // Delete the entity object
      //delete entities[i];// don't delete, these are managed elsewhere!

      // Set the pointer to null to avoid dangling references
      entities[i] = nullptr;
    }
  }

  // Reset the number of entities to 0
  numEntities = 0;
}

void EntityManager_Ground::addEntity(Entity* entity) {
  if (numEntities < MAX_ENTITIES) {
    entities[numEntities] = entity;
    numEntities++;
  }
}

void EntityManager_Ground::recycleGroundEntity(int index) {
    // Find the rightmost position of the current ground segments
    int maxRightX = findMaxRightX();

    // Move the recycled entity to the right of the rightmost ground entity
    if (entities[index] != nullptr && entities[index]->getEntityType() == EntityType::GROUND) {
        Entity_Ground* groundEntity = static_cast<Entity_Ground*>(entities[index]);
        groundEntity->setX(maxRightX);

        // pick a new random section
        groundEntity->setData(&groundDefinitions[random(0, GROUND_DEFINITION_COUNT)]);
    }
}

int EntityManager_Ground::findMaxRightX() {
    int maxRightX = 0;
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr && entities[i]->getEntityType() == EntityType::GROUND) {
            Entity_Ground* groundEntity = static_cast<Entity_Ground*>(entities[i]);
            int rightEdgeX = groundEntity->getX() + GROUND_DEFINITION_SIZE * GROUND_SIZE;
            if (rightEdgeX > maxRightX) {
                maxRightX = rightEdgeX;
            }
        }
    }
    return maxRightX;
}

bool EntityManager_Ground::isGroundAt(int x) {
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr) {
            if (entities[i] -> getEntityType() == EntityType::GROUND) {
              Entity_Ground* groundEntity = static_cast<Entity_Ground*>(entities[i]);

              if (groundEntity -> isGroundAt(x)) {
                return true;
              }
            }
        }
    }
    return false;
}
 
Entity_Enemy* EntityManager_Ground::enemyCollision(int playerX, int playerY, int playerRadius) {
  for (int i = 0; i < numEntities; i++) {
    if (entities[i] != nullptr) {
      Entity_Ground* groundEntity = static_cast<Entity_Ground*>(entities[i]);
      int entityX = groundEntity->getX();
      int entityWidth = groundEntity->getWidth();
      if (playerX >= entityX && playerX <= entityX + entityWidth) {
        return groundEntity->enemyCollision(playerX, playerY, playerRadius);
      }
    }
  }
  return nullptr;
}


// Implement other methods specific to ground entities if needed
