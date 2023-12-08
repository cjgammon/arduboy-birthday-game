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
        groundArray[i] = pgm_read_byte(&(groundDefinitions[arrayIndex].groundArray[i]));
    }
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
    return groundArray[index] == 1;
}

void Entity_Ground::update() {
    // Update the position of the ground based on speed
}

void Entity_Ground::draw(Arduboy2 &arduboy) {
    // Draw the ground segment
    for (int i = 0; i < GROUND_DEFINITION_SIZE; i ++) {
      int newX = x + (i * GROUND_SIZE);

      if (i == 0 || i == GROUND_DEFINITION_SIZE - 1) {
        Sprites::drawOverwrite(newX, y, environmentgroundmiddle, 0);
      }

      if (groundArray[i] == 1) {
        if (i > 0 && groundArray[i - 1] == 0) {
          Sprites::drawOverwrite(newX, y, environmentgroundstart, 0);
        } else if (i < GROUND_DEFINITION_SIZE - 1 && groundArray[i + 1] == 0) {
          Sprites::drawOverwrite(newX, y, environmentgroundend, 0);
        } else {
          if (i % 23 == 0) {
            Sprites::drawOverwrite(newX, y, environmentgroundmiddle_alt4, 0);
          } else if (i % 17 == 0) {
            Sprites::drawOverwrite(newX, y, environmentgroundmiddle_alt5, 0);
          } else if (i % 12 == 0) {
            Sprites::drawOverwrite(newX, y, environmentgroundmiddle_alt3, 0);
          } else if (i % 8 == 0) {
            Sprites::drawOverwrite(newX, y, environmentgroundmiddle_alt2, 0);
          } else if (i % 7 == 0) {
            Sprites::drawOverwrite(newX, y, environmentgroundmiddle_alt1, 0);
          } else {
            Sprites::drawOverwrite(newX, y, environmentgroundmiddle, 0);
          }
        }
      }
    }
    //arduboy.drawRect(x, y, width, 64, WHITE); // Adjust color and size as needed
}
