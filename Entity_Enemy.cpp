// Entity_Ground.cpp
#include "Entity_Enemy.h"

Entity_Enemy::Entity_Enemy(uint8_t initialEnemyType, uint8_t initialX, uint8_t initialY, uint8_t initialWidth, uint8_t initialHeight, uint8_t cx, uint8_t cy, uint8_t cr): Entity(initialX, initialY, initialWidth, initialHeight) {
    // Constructor code, initialize variables
    enemyType = initialEnemyType;
    type = EntityType::ENEMY;
    offsetX = 1000;  //prevents from flashing on screen
    collisionX = cx;
    collisionY = cy;
    collisionR = cr;
}

int Entity_Enemy::getAbsoluteX() {
  return offsetX + x;
}

int Entity_Enemy::getCollisionX() {
  return offsetX + x + collisionX;
}

int Entity_Enemy::getCollisionY() {
  return y + collisionY;
}

int Entity_Enemy::getCollisionR() {
  return collisionR;
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

  if (debugDraw) {
    arduboy.drawCircle(getCollisionX(), getCollisionY(), getCollisionR());
  }
}
