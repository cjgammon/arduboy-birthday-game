#include "EntityManager_Ground.h"

#define MAX_VISIBLE_GROUND_PIECES 3

Entity_Ground groundPieces[MAX_VISIBLE_GROUND_PIECES];

const int fixedSeedValue = 122; // Example fixed seed value

EntityManager_Ground::EntityManager_Ground() {
}

void EntityManager_Ground::init() {
  randomSeed(fixedSeedValue); // Seed the random number generator with a fixed value
                              //
  for (int i = 0; i < MAX_ENTITIES; i++) {
    entities[i] = nullptr;
  }
  numEntities = 0;
  createGroundEntities();
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

const SegmentDefinition* EntityManager_Ground::selectSegmentBasedOnDifficulty() {
    int eligibleSegments[GROUND_DEFINITION_COUNT];
    int eligibleCount = 0;
    int currentDifficultyLevel = calculateDifficultyLevel();

    for (int i = 0; i < GROUND_DEFINITION_COUNT; i++) {
        int segmentDifficulty = pgm_read_byte(&groundDefinitions[i].difficulty);
        if (segmentDifficulty <= currentDifficultyLevel) {
          eligibleSegments[eligibleCount++] = i;
        }
    }

    if (eligibleCount > 0) {
        int randomIndex = eligibleSegments[random(0, eligibleCount)];
        return &groundDefinitions[randomIndex];
    } else {
        return &flatGround;
    }
}

void EntityManager_Ground::createGroundEntities() {
    int lastX = 0;
    for (int i = 0; i < MAX_VISIBLE_GROUND_PIECES; i++) {
        Entity_Ground* groundEntity = &groundPieces[i];
        groundEntity->init(lastX, 60);
        addEntity(groundEntity);
        lastX += GROUND_DEFINITION_SIZE * GROUND_SIZE;

        if (i == 0) {
          groundEntity->setData(&flatGround);
        } else {
          const SegmentDefinition* selectedSegment = selectSegmentBasedOnDifficulty();
          groundEntity->setData(selectedSegment);
        }

    }
}

void EntityManager_Ground::recycleGroundEntity(int index) {
    // Find the rightmost position of the current ground segments
    int maxRightX = findMaxRightX();

    if (entities[index] != nullptr && entities[index]->getEntityType() == EntityType::GROUND) {
        Entity_Ground* groundEntity = static_cast<Entity_Ground*>(entities[index]);
        groundEntity->setX(maxRightX);

        const SegmentDefinition* selectedSegment = selectSegmentBasedOnDifficulty();
        groundEntity->setData(selectedSegment);
    }
}

int EntityManager_Ground::calculateDifficultyLevel() {
    int difficultyLevel = 0;
    float maximumSpeed = 2.2;
    float initialSpeed = 0.95; //make sure this matches the initial value in GameState_Play.cpp

    //todo instead base it relative to max speed as fractions
    double normalizedSpeed = (globalSpeedMultiplier - initialSpeed) / (maximumSpeed - initialSpeed);

    if (normalizedSpeed > 0.9) {
      difficultyLevel = 3;
    } else if (normalizedSpeed > 0.7) {
      difficultyLevel = 2;
    } else if (normalizedSpeed > 0.5) {
      difficultyLevel = 3;
    } else if (normalizedSpeed > 0.4) {
      difficultyLevel = 2;
    } else if (normalizedSpeed > 0.2) {
      difficultyLevel = 1;
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
