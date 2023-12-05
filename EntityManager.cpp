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

void EntityManager::update(Arduboy2 &arduboy, int xDelta) {
    for (int i = 0; i < numEntities; i++) {
        if (entities[i] != nullptr) {
          entities[i]->move(xDelta, 0);
          
          if (entities[i]->getX() + entities[i]->getWidth() < 0) {
            //entities[i]->setX(entities[i]->getX() + entities[i]->getWidth() + SCREEN_WIDTH);
            //recycleEntity(i); // Recycle the entity if it goes off-screen
          }
          
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
