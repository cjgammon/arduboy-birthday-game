// EntityManager.h
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <Arduboy2.h>
#include "Entity.h"

class EntityManager {
public:
    EntityManager(); // Constructor
    void init(); // Initialize the entities
    void update(Arduboy2 &arduboy, int xDelta); // Update all entities
    void draw(Arduboy2 &arduboy); // Draw all entities

    // Add a new entity to the manager
    void addEntity(Entity* entity);

private:
    static const int MAX_ENTITIES = 10; // Maximum number of entities (adjust as needed)
    Entity* entities[MAX_ENTITIES]; // Store all entities
    int numEntities; // Number of currently added entities
    unsigned long lastUpdateTime; // Timestamp for the last update
};

#endif
