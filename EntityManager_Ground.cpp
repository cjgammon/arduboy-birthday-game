#include "EntityManager_Ground.h"


const int fixedSeedValue = 122; // Example fixed seed value

EntityManager_Ground::EntityManager_Ground() {
  init();
}

void EntityManager_Ground::init() {
  randomSeed(fixedSeedValue); // Seed the random number generator with a fixed value
                              //
  for (int i = 0; i < MAX_ENTITIES; i++) {
    entities[i] = nullptr;
  }
  numEntities = 0;
}


void EntityManager_Ground::update() {
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

void EntityManager_Ground::draw() {
  for (int i = 0; i < numEntities; i++) {
    if (entities[i] != nullptr) {
      entities[i]->draw();
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

        int currentDifficultyLevel = calculateDifficultyLevel();

       // Create an array of eligible segments based on the current difficulty
        int eligibleSegments[GROUND_DEFINITION_COUNT];
        int eligibleCount = 0;
        for (int i = 0; i < GROUND_DEFINITION_COUNT; i++) {
              int segmentDifficulty = pgm_read_word_near(&groundDefinitions[i].difficulty);

            if (segmentDifficulty <= currentDifficultyLevel) {
                eligibleSegments[eligibleCount++] = i;
            }
        }

        // Randomly select a segment from the eligible array
        if (eligibleCount > 0) {
            int randomIndex = eligibleSegments[random(0, eligibleCount)];
            groundEntity->setData(&groundDefinitions[randomIndex]);
        }

        // pick a new random section
        //groundEntity->setData(&groundDefinitions[random(0, GROUND_DEFINITION_COUNT)]);
    }
}

int EntityManager_Ground::calculateDifficultyLevel() {
    int difficultyLevel = 0;

    if (score > 10) {
      difficultyLevel = 1;
    } 
    if (score > 60) {
      difficultyLevel = 2;
    }
    if (score > 120) {
      difficultyLevel = 3;
    }

    if (difficultyLevel > MAX_DIFFICULTY) {
      difficultyLevel = MAX_DIFFICULTY;
    }

    return difficultyLevel;
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

Coin* EntityManager_Ground::coinCollision(int playerX, int playerY, int playerRadius)
{
  for (int i = 0; i < numEntities; i++) {
    if (entities[i] != nullptr) {
      Entity_Ground* groundEntity = static_cast<Entity_Ground*>(entities[i]);
      int entityX = groundEntity->getX();
      int entityWidth = groundEntity->getWidth();
      if (playerX >= entityX && playerX <= entityX + entityWidth) {
        return groundEntity->coinCollision(playerX, playerY, playerRadius);
      }
    }
  }
  return nullptr;
}


// Implement other methods specific to ground entities if needed
