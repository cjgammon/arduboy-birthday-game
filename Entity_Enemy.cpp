// Entity_Ground.cpp
#include "Entity_Enemy.h"

Entity_Enemy::Entity_Enemy(const EnemyDefinition& enemyDefinition, float groundX): Entity()
{
    EnemyTypeDefinition enemyTypeDefinition = getEnemyTypeDefinition();

    x = enemyDefinition.x;
    xRaw = x;
    y = enemyTypeDefinition.y;
    yRaw = y;

    enemyType = enemyDefinition.enemyType;
    entityType = EntityType::ENEMY;
    offsetX = groundX;
    width = enemyTypeDefinition.spriteWidth;
    height = enemyTypeDefinition.spriteHeight;
}

int Entity_Enemy::getAbsoluteX() {
  return offsetX + x;
}

int Entity_Enemy::getCollisionX() {
  return offsetX + x + getColliderX();
}

int Entity_Enemy::getCollisionY() {
  return y + getColliderY();
}

void Entity_Enemy::update(float newX) {
  offsetX = newX;
}

void Entity_Enemy::draw(Arduboy2 &arduboy) {

  if (enemyType == EnemyType::TROLL) {
    Sprites::drawSelfMasked(getAbsoluteX(), y, enemy_troll, 0);
  } else if (enemyType == EnemyType::SPIDER) {
    Sprites::drawSelfMasked(getAbsoluteX(), y, enemy_spider, 0);
  }

#ifdef DEBUG_DRAW_HITBOXES
  arduboy.drawCircle(getCollisionX(), getCollisionY(), getColliderRadius());
#endif
}
