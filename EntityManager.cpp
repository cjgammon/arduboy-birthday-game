// EntityManager.cpp
#include "EntityManager.h"

EntityManager::EntityManager() {
    init();
}

void EntityManager::init() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        entities[i] = nullptr;
    }
    numEntities = 0;
}

void EntityManager::update(Arduboy2 &arduboy) {
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr) {
          entities[i]->move(cameraX, 0.0);
          entities[i]->update();
        }
    }
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
