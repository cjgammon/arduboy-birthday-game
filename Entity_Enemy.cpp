// Entity_Ground.cpp
#include "Entity_Enemy.h"

Entity_Enemy::Entity_Enemy(uint8_t initialEnemyType, uint8_t initialX, uint8_t initialY): Entity(initialX, initialY) {
    // Constructor code, initialize variables
    enemyType = initialEnemyType;
    entityType = EntityType::ENEMY;
    offsetX = 1000;  //prevents from flashing on screen
    width = getEnemyTypeDefinition().spriteWidth;
    height = getEnemyTypeDefinition().spriteHeight;
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

void Entity_Enemy::update(int newOffsetX) {
  offsetX = newOffsetX;
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
