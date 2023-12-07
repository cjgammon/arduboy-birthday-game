// Entity_Ground.cpp
#include "Entity_Ground.h"

Entity_Ground::Entity_Ground(): Entity() {
    // Constructor code, initialize variables
    type = EntityType::GROUND;
}

Entity_Ground::Entity_Ground(int initialX, int initialY, int arrayIndex)
    : Entity(initialX, initialY, GROUND_DEFINITION_SIZE * GROUND_SIZE, 1) {
    // Constructor code, initialize variables
    type = EntityType::GROUND;
    for (int i = 0; i < GROUND_DEFINITION_SIZE; ++i) {
        //groundArray[i] = groundDefinitions[arrayIndex][i];
        groundArray[i] = pgm_read_byte(&(groundDefinitions[arrayIndex][i]));
    }
}

void Entity_Ground::update() {
    // Update the position of the ground based on speed
}

void Entity_Ground::draw(Arduboy2 &arduboy) {
    // Draw the ground segment
    for (int i = 0; i < GROUND_DEFINITION_SIZE; i ++) {
      int newX = x + (i * GROUND_SIZE);
      if (groundArray[i] == 1) {
        Sprites::drawOverwrite(newX, y, environmentgroundmiddle, 0);
      }
      /*
      if (i == 0) {
        Sprites::drawOverwrite(x + i, y, environmentgroundstart, 0);
      } else if (i == max * 6) {
        Sprites::drawOverwrite(x + i, y, environmentgroundend, 0);
      } else {
        Sprites::drawOverwrite(x + i, y, environmentgroundmiddle, 0);
      }
      */
    }
    //arduboy.drawRect(x, y, width, 64, WHITE); // Adjust color and size as needed
}
