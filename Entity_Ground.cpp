// Entity_Ground.cpp
#include "Entity_Ground.h"
#include "GlobalMethods.h"

Entity_Ground::Entity_Ground(): Entity() {
    entityType = EntityType::GROUND;
    for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i)
    {
      enemies[i] = new Entity_Enemy();
    }

#ifdef COINS_ENALBED
    for (int coinIndex = 0; coinIndex < MAX_COINS_PER_SEGMENT; coinIndex++)
    {
      coins[coinIndex] = new Entity_Enemy();
    }
#endif
}

void Entity_Ground::init(int initialX, int initialY)
{
  x = initialX;
  xRaw = x;
  y = initialY;
  yRaw = y;
  width = GROUND_DEFINITION_SIZE * GROUND_SIZE;
  height = 1;
}

void Entity_Ground::setData(SegmentDefinition * segmentDefinition)
{
  for (int byteIndex = 0; byteIndex < GROUND_DEFINITION_SIZE / 8; byteIndex++)
  {
    uint8_t tileByte = pgm_read_byte(&(segmentDefinition->groundArray[byteIndex]));
    for (int bitIndex = 0; bitIndex < 8; bitIndex++)
    {
      groundTiles[byteIndex * 8 + bitIndex] = (tileByte >> bitIndex) & 1;
    }
  }

  for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i)
  {
    EnemyDefinition enemyDefinition;

    memcpy_P(&enemyDefinition, &segmentDefinition->enemies[i], sizeof(EnemyDefinition));
    if (enemyDefinition.enemyType != 0)// Assuming type 0 means no enemy
    {
      enemies[i]->setData(enemyDefinition, x);
      enemies[i]->enabled = true;
    }
    else
    {
      enemies[i]->enabled = false;
    }
  }

#ifdef COINS_ENABLED
  // reset all coins
  for (int coinIndex = 0; coinIndex < MAX_COINS_PER_SEGMENT; ++coinIndex)
  {
    coins[coinIndex]->enabled = false;
  }

  for (int coinFormationIndex = 0; coinFormationIndex < 1; coinFormationIndex++)
  {
    CoinFormationDefinition coinDefinition;
    memcpy_P(&coinDefinition, &segmentDefinition->coinFormations[coinFormationIndex], sizeof(CoinFormationDefinition));
    if (coinDefinition.formationType == 1)
    {
      coins[0]->setData(enemyDefinitionForCoin, x);
      coins[0]->setY(10);
    }
    else if (coinDefinition.formationType == 2)
    {
      coins[0]->setData(enemyDefinitionForCoin, x);
      coins[0]->setY(10);
      coins[1]->setData(enemyDefinitionForCoin, x + 10);
      coins[1]->setY(10);
    }
    else if (coinDefinition.formationType == 3)
    {
      int index = 0;
      for (int row = 0; row < 2; ++row)
      {
        for (int col = 0; col < 2; ++col)
        {
          coins[index]->setData(enemyDefinitionForCoin, x + 10 * col);
          coins[index]->setY(10 + 10 * row);
          index++;
        }
      }
    }
    else if (coinDefinition.formationType == 4)
    {
      for (int col = 0; col < 4; ++col)
      {
        coins[col]->setData(enemyDefinitionForCoin, x + 10 * col);
        coins[col]->setY(10);
      }
    }
  }
#endif
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

Entity_Enemy* Entity_Ground::enemyCollision(int playerX, int playerY, int playerRadius)
{
    for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i) {
      Entity_Enemy* enemy = enemies[i];

      if (!enemy->enabled)
      {
        continue;
      }

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
        return enemy; // Collision detected
      }
    }
    return nullptr;
}

void Entity_Ground::update() {
  for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i) {
    Entity_Enemy* enemy = enemies[i];
    enemy->update(x);
  }

#ifdef COINS_ENABLED
  for (int i = 0; i < MAX_COINS_PER_SEGMENT; ++i) {
    Entity_Enemy* coin = coins[i];
    coin->update(x);
  }
#endif
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
    for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i) {
      Entity_Enemy* enemy = enemies[i];
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
  for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i) {
    delete enemies[i];
  }

#ifdef COINS_ENABLED
  for (int i = 0; i < MAX_COINS_PER_SEGMENT; ++i) {
    delete coins[i];
  }
#endif
}