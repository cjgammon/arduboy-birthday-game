// Character0.cpp
#include "sprites.h"
#include "Character0.h"

Character0::Character0(int initialX, int initialY) : Character(initialX, initialY) {
    this->predefinedSprite = character0idle;
    // You can add any additional initialization specific to Character0 here
}

Character0::~Character0() {
    // Add any necessary cleanup code here
}
