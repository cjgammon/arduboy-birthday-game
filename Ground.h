// Ground.h
#ifndef GROUND_H
#define GROUND_H

#include "Entity.h"
#include <Arduboy2.h>

class Ground : public Entity {
public:
    Ground();
    Ground(int initialX, int initialY, int initialWidth);
    void update() override;
    void draw(Arduboy2 &arduboy) override;
};

#endif // GROUND_H
