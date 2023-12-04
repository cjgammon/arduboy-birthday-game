// Ground.cpp
#include "Ground.h"

Ground::Ground(): Entity() {
    // Constructor code, initialize variables
}

Ground::Ground(int initialX, int initialY, int initialWidth)
    : Entity(initialX, initialY, initialWidth, 1) {
    // Constructor code, initialize variables
    type = "ground";
}

void Ground::update() {
    // Update the position of the ground based on speed
}

void Ground::draw(Arduboy2 &arduboy) {
    // Draw the ground segment
    int max = floor(width / 6);

    for (int i = 0; i < width; i += 6) {
      if (i == 0) {
        Sprites::drawOverwrite(x + i, y, environmentgroundstart, 0);
      } else if (i == max * 6) {
        Sprites::drawOverwrite(x + i, y, environmentgroundend, 0);
      } else {
        Sprites::drawOverwrite(x + i, y, environmentgroundmiddle, 0);
      }
    }
    
    //arduboy.drawRect(x, y, width, 64, WHITE); // Adjust color and size as needed

}
