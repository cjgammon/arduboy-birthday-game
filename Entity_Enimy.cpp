// Entity_Ground.cpp
#include "Entity_Enemy.h"

Entity_Enemy::Entity_Enemy(): Entity() {
    // Constructor code, initialize variables
    type = EntityType::ENEMY;
}

void Entity_Enemy::update() {
    // Update the position of the ground based on speed
}

void Entity_Enemy::draw(Arduboy2 &arduboy) {
   
}
