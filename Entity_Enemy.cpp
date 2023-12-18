// Entity_Ground.cpp
#include "Entity_Enemy.h"

Entity_Enemy::Entity_Enemy() : Entity()
{

}

void Entity_Enemy::setData(const EnemyDefinition& enemyDefinition, float segmentX)
{
    enemyType = enemyDefinition.enemyType;
    entityType = EntityType::ENEMY;

    const EnemyTypeDefinition& enemyTypeDefinition = getEnemyTypeDefinition();

    positionInSegmentX = enemyDefinition.x;
    x = segmentX + positionInSegmentX;
    xRaw = x;
    y = enemyTypeDefinition.y;
    yRaw = y;

    width = enemyTypeDefinition.spriteWidth;
    height = enemyTypeDefinition.spriteHeight;
}

int Entity_Enemy::getCollisionX() {
  return x + getColliderX();
}

int Entity_Enemy::getCollisionY() {
  return y + getColliderY();
}

void Entity_Enemy::update(float newX) {
  if (!enabled)
  {
    return;
  }

  x = newX + positionInSegmentX;
}

void Entity_Enemy::draw() {
  if (!enabled)
  {
    return;
  }

  if (enemyType == EnemyType::TROLL) {
    Sprites::drawSelfMasked(x, y, enemy_troll, 0);
  } else if (enemyType == EnemyType::SPIDER) {
    Sprites::drawSelfMasked(x, y, enemy_spider, 0);
  }
  else if (enemyType == EnemyType::COIN_ENEMY) {
    Sprites::drawSelfMasked(x, y, item_coin, 0);
  }

#ifdef DEBUG_DRAW_HITBOXES
  arduboy.drawCircle(getCollisionX(), getCollisionY(), getColliderRadius());
#endif
}
