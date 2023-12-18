// Entity_Ground.cpp
#include "Entity_Ground.h"
#include "GlobalMethods.h"

Entity_Ground::Entity_Ground(): Entity() {
    entityType = EntityType::GROUND;
    for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i)
    {
      enemies[i] = new Entity_Enemy();
    }

#ifdef COINS_ENABLED
    for (int coinIndex = 0; coinIndex < MAX_COINS_PER_SEGMENT; ++coinIndex)
    {
      coinsArray[coinIndex] = new Coin();
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

  // start by turning all the coins off
  for (int coinIndex = 0; coinIndex < MAX_COINS_PER_SEGMENT; ++coinIndex)
  {
    coinsArray[coinIndex]->enabled = false;
  }

  // now loop over all our coin formations in data and build them
  for (int coinFormationIndex = 0; coinFormationIndex < MAX_COIN_FORMATIONS_PER_SEGMENT; coinFormationIndex++)
  {
    CoinFormationDefinition coinFormationDefinition;
    memcpy_P(&coinFormationDefinition, &segmentDefinition->coinFormations[coinFormationIndex], sizeof(CoinFormationDefinition));
    if (coinFormationDefinition.formationType == 1)
    {
      coinsArray[0]->init(x, coinFormationDefinition.x, 10);
    }
    else if (coinFormationDefinition.formationType == 2)
    {
      coinsArray[0]->init(x, coinFormationDefinition.x, 10);
      coinsArray[1]->init(x, coinFormationDefinition.x + 10, 10);
    }
    else if (coinFormationDefinition.formationType == 3)
    {
      int index = 0;
      for (int row = 0; row < 2; ++row)
      {
        for (int col = 0; col < 2; ++col)
        {
          coinsArray[index]->init(x, coinFormationDefinition.x + 10 * col, 10 + 10 * row);
          index++;
        }
      }
    }
    else if (coinFormationDefinition.formationType == 4)
    {
      for (int col = 0; col < 4; ++col)
      {
        coinsArray[col]->init(x, coinFormationDefinition.x + 10 * col, 10);
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

      int enemyRadius = enemy->getColliderRadius();

      int dx = playerX - enemy->getCollisionX();
      int dy = playerY - enemy->getCollisionY();
      int distanceSquared = dx * dx + dy * dy;

      int radiiSumSquared = (playerRadius + enemyRadius) * (playerRadius + enemyRadius);
      if (distanceSquared < radiiSumSquared) {
        return enemy; // Collision detected
      }
    }
    return nullptr;
}

Coin* Entity_Ground::coinCollision(int playerX, int playerY, int playerRadius)
{
  for (int i = 0; i < MAX_COINS_PER_SEGMENT; ++i) {
    Coin* coin = coinsArray[i];

    if (!coin->enabled)
    {
      continue;
    }

    int enemyRadius = 4;

    int dx = playerX - (coin->x + 4);
    int dy = playerY - (coin->y + 4);
    int distanceSquared = dx * dx + dy * dy;

    int radiiSumSquared = (playerRadius + enemyRadius) * (playerRadius + enemyRadius);
    if (distanceSquared < radiiSumSquared) {
      return coin; // Collision detected
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
    Coin* coin = coinsArray[i];
    coin->update(x);
  }
#endif
}

void Entity_Ground::draw() {

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

    // draw enemies
    for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i)
    {
      enemies[i]->draw();
    }

#ifdef COINS_ENABLED
    for (int i = 0; i < MAX_COINS_PER_SEGMENT; ++i)
    {
      coinsArray[i]->draw();
    }
#endif

}

Entity_Ground::~Entity_Ground() {
  for (int i = 0; i < MAX_ENEMIES_PER_SEGMENT; ++i) {
    delete enemies[i];
  }

#ifdef COINS_ENABLED
  for (int i = 0; i < MAX_COINS_PER_SEGMENT; ++i) {
    delete coinsArray[i];
  }
#endif
}
