// Ground.cpp
#include "Ground.h"


Ground::Ground(): Entity() {
    // Constructor code, initialize variables
}

Ground::Ground(int initialX, int initialY, int initialWidth, int initialSpeed)
    : Entity(initialX, initialY, initialWidth, 1, initialSpeed) {
    // Constructor code, initialize variables
    type = "ground";
}

void Ground::update() {
    // Update the position of the ground based on speed
    //x -= speed;
}

void Ground::draw(Arduboy2 &arduboy) {
    // Draw the ground segment
    arduboy.fillRect(x, y, width, 64, WHITE); // Adjust color and size as needed
}
