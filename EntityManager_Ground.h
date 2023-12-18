#ifndef ENTITYMANAGER_GROUND_H
#define ENTITYMANAGER_GROUND_H

#include "Entity_Ground.h"
#include "Vars.h"

class EntityManager_Ground {
public:
    EntityManager_Ground();
    void init(); // Initialize the entities
    void update();
    void draw(); // Draw all entities
    void cleanup();

    void addEntity(Entity* entity);
    bool isGroundAt(int x); // Check if there is ground at the given coordinates
    Entity_Enemy* enemyCollision(int playerX, int playerY, int playerRadius);
    Coin* coinCollision(int playerX, int playerY, int playerRadius);

    static const int MAX_ENTITIES = 10; // Maximum number of entities (adjust as needed)
    Entity* entities[MAX_ENTITIES]; // Store all entities
    int numEntities; // Number of currently added entities
    int calculateDifficultyLevel();

private:
    void recycleGroundEntity(int index);
    int findMaxRightX();
};

#endif // ENTITYMANAGER_GROUND_H
