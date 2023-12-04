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

void EntityManager::update() {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - lastUpdateTime;

    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr) {
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
