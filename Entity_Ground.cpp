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
        groundArray[i] = groundDefinitions[arrayIndex][i];
    }
}

/*
Entity_Ground::Entity_Ground(int initialX, int initialY, const int inputArray[GROUND_DEFINITION_SIZE])
    : Entity(initialX, initialY, GROUND_DEFINITION_SIZE * GROUND_SIZE, 1), groundArray() {
    // Constructor implementation
    type = EntityType::GROUND;
    for (int i = 0; i < GROUND_DEFINITION_SIZE; ++i) {
        groundArray[i] = inputArray[i];
    }
}
*/
void Entity_Ground::update() {
    // Update the position of the ground based on speed
}

void Entity_Ground::draw(Arduboy2 &arduboy) {
    // Draw the ground segment
    int max = floor(width / 6);
    arduboy.println(width);
    for (int i = 0; i < width; i += 6) {
      if (i == 0) {
        Sprites::drawOverwrite(x + i, y, environmentgroundstart, 0);
      } else if (i == max * 6) {
        Sprites::drawOverwrite(x + i, y, environmentgroundend, 0);
      } else {
        Sprites::drawOverwrite(x + i, y, environmentgroundmiddle, 0);
      }
    }
    
   // arduboy.drawRect(x, y, width, 64, WHITE); // Adjust color and size as needed

}
