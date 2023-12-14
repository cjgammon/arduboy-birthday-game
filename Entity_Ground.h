// Entity_Ground.h
#ifndef ENTITY_GROUND_H
#define ENTITY_GROUND_H

//#define COINS_ENABLED

#include "Vars.h"
#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"
#include "Entity_Enemy.h"

class Entity_Ground : public Entity {
public:
    Entity_Ground();
    void init(int initialX, int initialY);
    ~Entity_Ground();

    void setData(SegmentDefinition * segmentDefinition);

    void update() override;
    void draw(Arduboy2 &arduboy) override;

    void drawEnemies(Arduboy2 &arduboy);
    bool isGroundAt(int posX);
    Entity_Enemy* enemyCollision(int playerX, int playerY, int playerRadius);

private:
    uint8_t groundTiles[GROUND_DEFINITION_SIZE];
    Entity_Enemy* enemies[MAX_ENEMIES_PER_SEGMENT];
    Entity_Enemy* coins[MAX_COINS_PER_SEGMENT];
};

#endif // ENTITY_GROUND_H
