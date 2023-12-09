// Entity_Ground.cpp
#include "Entity_Enemy.h"

Entity_Enemy::Entity_Enemy(uint8_t initialEnemyType, uint8_t initialX, uint8_t initialY, uint8_t initialWidth, uint8_t initialHeight): Entity(initialX, initialY, initialWidth, initialHeight) {
    // Constructor code, initialize variables
    enemyType = initialEnemyType;
    type = EntityType::ENEMY;
}

void Entity_Enemy::update() {
    // Update the position of the ground based on speed
}

void Entity_Enemy::draw(Arduboy2 &arduboy, int offsetX) {

  if (enemyType == EnemyType::TROLL) {
    Sprites::drawOverwrite(offsetX + x, y, enemy_troll, 0);
  } else if (enemyType == EnemyType::SPIDER) {
    Sprites::drawOverwrite(offsetX + x, y, enemy_spider, 0);
  }
}
