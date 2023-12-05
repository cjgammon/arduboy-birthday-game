// EntityManager.cpp
#include "EntityManager.h"

#define SCREEN_WIDTH 128 // character width in pixels including inter-character spacing

EntityManager::EntityManager() {
    init();
}

void EntityManager::init() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        entities[i] = nullptr;
    }
    numEntities = 0;
}

void EntityManager::update(Arduboy2 &arduboy, int xDelta) {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - lastUpdateTime;

    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr) {
          entities[i]->move(xDelta, 0);
          
          if (entities[i]->getX() + entities[i]->getWidth() < 0) {
            entities[i]->setX(entities[i]->getX() + entities[i]->getWidth() + SCREEN_WIDTH);
            //recycleEntity(i); // Recycle the entity if it goes off-screen
          }
          
          entities[i]->update();
        }
    }

    lastUpdateTime = currentTime;
}

void EntityManager::draw(Arduboy2 &arduboy) {
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr) {
            entities[i]->draw(arduboy);
        }
    }
}

void EntityManager::addEntity(Entity* entity) {
    if (numEntities < MAX_ENTITIES) {
        entities[numEntities] = entity;
        numEntities++;
    }
}

bool EntityManager::isGroundAt(int x) {
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr) {
            if (entities[i] -> getType() == EntityType::GROUND) {
                //check if x position is within the ground x and width
                if (x >= entities[i]->getX() && x <= entities[i]->getX() + entities[i]->getWidth()) {
                  return true;
                }
            }
        }
    }
    return false;
}

void EntityManager::cleanup() {
    // Iterate through the array of entity pointers
    for (int i = 0; i < numEntities; i++) {
        // Check if the pointer is not null
        if (entities[i] != nullptr) {
            // Delete the entity object
            delete entities[i];

            // Set the pointer to null to avoid dangling references
            entities[i] = nullptr;
        }
    }

    // Reset the number of entities to 0
    numEntities = 0;
}
