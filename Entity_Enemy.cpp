// Entity_Ground.cpp
#include "Entity_Enemy.h"

Entity_Enemy::Entity_Enemy() : Entity()
{

}

void Entity_Enemy::setData(const EnemyDefinition& enemyDefinition, float segmentX)
{
    const EnemyTypeDefinition& enemyTypeDefinition = getEnemyTypeDefinition();

    positionInSegmentX = enemyDefinition.x;
    x = segmentX + positionInSegmentX;
    xRaw = x;
    y = enemyTypeDefinition.y;
    yRaw = y;

    enemyType = enemyDefinition.enemyType;
    entityType = EntityType::ENEMY;
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

void Entity_Enemy::draw(Arduboy2 &arduboy) {
  if (!enabled)
  {
    return;
  }

  if (enemyType == EnemyType::TROLL) {
    Sprites::drawSelfMasked(x, 28, enemy_troll, 0);
  } else if (enemyType == EnemyType::SPIDER) {
    Sprites::drawSelfMasked(x, 0, enemy_spider, 0);
  }

#ifdef DEBUG_DRAW_HITBOXES
  arduboy.drawCircle(getCollisionX(), getCollisionY(), getColliderRadius());
#endif
}
