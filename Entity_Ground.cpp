// Entity_Ground.cpp
#include "Entity_Ground.h"
#include "GlobalMethods.h"

Entity_Ground::Entity_Ground(): Entity() {
    // Constructor code, initialize variables
    entityType = EntityType::GROUND;
}

Entity_Ground::Entity_Ground(int initialX, int initialY, int arrayIndex)
    : Entity(initialX, initialY) {

    width = GROUND_DEFINITION_SIZE * GROUND_SIZE;
    height = 1;

    entityType = EntityType::GROUND;

    for (int byteIndex = 0; byteIndex < GROUND_DEFINITION_SIZE / 8; byteIndex++)
    {
        uint8_t tileByte = pgm_read_byte(&(groundDefinitions[arrayIndex].groundArray[byteIndex]));
        for (int bitIndex = 0; bitIndex < 8; bitIndex++)
        {
          //groundTiles[byteIndex * 8 + bitIndex] = tileByte & (1 << bitIndex) != 0 ? 1 : 0;
          groundTiles[byteIndex * 8 + bitIndex] = (tileByte >> bitIndex) & 1;
        }
    }

    numEnemies = 0;
    for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i) {
        EnemyDefinition enemyDefinition;
        
        memcpy_P(&enemyDefinition, &groundDefinitions[arrayIndex].enemies[i], sizeof(EnemyDefinition));
        if (enemyDefinition.enemyType != 0) { // Assuming type 0 means no enemy
            addEnemy(enemyDefinition);
        }
    }
}

void Entity_Ground::addEnemy(const EnemyDefinition& enemyDefinition) {
    if (numEnemies < MAX_ENEMIES_PER_SEGMENT) {
        enemyArray[numEnemies] = new Entity_Enemy(enemyDefinition, x);
        numEnemies++;
    }
}

bool Entity_Ground::isGroundAt(int posX) {
    // Calculate the relative x position
    int relativeX = posX - x;

    // Convert to index in the ground array
    int index = relativeX / GROUND_SIZE;

    // Check if the index is within the bounds of the array
    if (index < 0 || index >= GROUND_DEFINITION_SIZE) {
        return false; // posX is outside of this ground entity
    }

    // Return true if there's ground at the index, false otherwise
    return groundTiles[index] == 1;
}

bool Entity_Ground::enemyCollision(int playerX, int playerY, int playerRadius) {
    for (int i = 0; i < numEnemies; ++i) {
      Entity_Enemy* enemy = enemyArray[i];
      //int enemyX = enemy->getAbsoluteX() + enemy->getWidth() / 2;
      //int enemyY = enemy->getY() + enemy->getHeight() / 2;
      //int enemyRadius = enemy->getWidth() / 2;
      int enemyX = enemy->getCollisionX();
      int enemyY = enemy->getCollisionY();
      int enemyRadius = enemy->getColliderRadius();

      int px = playerX - x;
      int py = playerY;

      int dx = playerX - enemyX;
      int dy = playerY - enemyY;
      int distanceSquared = dx * dx + dy * dy;

      int radiiSumSquared = (playerRadius + enemyRadius) * (playerRadius + enemyRadius);
      if (distanceSquared < radiiSumSquared) {
        return true; // Collision detected
      }
    }
    return false;
}

void Entity_Ground::update() {
    for (int i = 0; i < numEnemies; ++i) {
      Entity_Enemy* enemy = enemyArray[i];
      enemy->update(x);
    }
}

void Entity_Ground::draw(Arduboy2 &arduboy) {
    // Draw the ground segment
    for (int i = 0; i < GROUND_DEFINITION_SIZE; i ++) {
      int newX = x + (i * GROUND_SIZE);

      if (i == 0 || i == GROUND_DEFINITION_SIZE - 1) {
        Sprites::drawOverwrite(newX, y, environmentgroundmiddle, 0);
      }

      if (groundTiles[i] == 1) {
        if (i > 0 && groundTiles[i - 1] == 0) {
          Sprites::drawOverwrite(newX, y, environmentgroundstart, 0);
        } else if (i < GROUND_DEFINITION_SIZE - 1 && groundTiles[i + 1] == 0) {
          Sprites::drawOverwrite(newX, y, environmentgroundend, 0);
        } else {
          drawRandomGround(i, newX, y);
        }
      }
    }
    //arduboy.drawRect(x, y, width, 64, WHITE); // Adjust color and size as needed
    drawEnemies(arduboy);
}

void Entity_Ground::drawEnemies(Arduboy2 &arduboy) {
    for (int i = 0; i < numEnemies; ++i) {
      Entity_Enemy* enemy = enemyArray[i];
      /*

      int enemyX = enemy->getAbsoluteX() + enemy->getWidth() / 2;
      int enemyY = enemy->getY() + enemy->getHeight() / 2;
      int enemyRadius = enemy->getWidth() / 2;

      int px = _playerX - x;
      int py = _playerY;
      int playerRadius = PLAYER_HALF_W; // Radius of player

      int dx = px - enemyX;
      int dy = py - enemyY;
      int distanceSquared = dx * dx + dy * dy;

      int radiiSumSquared = (playerRadius + enemyRadius) * (playerRadius + enemyRadius);

      arduboy.drawCircle(enemyX, enemyY, enemyRadius);

      arduboy.setCursor(enemy->getAbsoluteX(), enemy->getY());
      arduboy.print(distanceSquared);
      arduboy.print(",");
      arduboy.print(radiiSumSquared);
      */
      enemy->draw(arduboy);
    }
}

Entity_Ground::~Entity_Ground() {
    for (int i = 0; i < numEnemies; ++i) {
        delete enemyArray[i];
    }
}