// Entity_Ground.h
#ifndef ENTITY_GROUND_H
#define ENTITY_GROUND_H

#define COINS_ENABLED

#include "Vars.h"
#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"
#include "Entity_Enemy.h"
#include "Coin.h"

class Entity_Ground : public Entity {
public:
    Entity_Ground();
    void init(int initialX, int initialY);
    ~Entity_Ground();

    void setData(SegmentDefinition * segmentDefinition);

    void update() override;
    void draw(Arduboy2 &arduboy) override;

    bool isGroundAt(int posX);
    Entity_Enemy* enemyCollision(int playerX, int playerY, int playerRadius);
    Coin* coinCollision(int playerX, int playerY, int playerRadius);

private:
    uint8_t groundTiles[GROUND_DEFINITION_SIZE];
    Entity_Enemy* enemies[MAX_ENEMIES_PER_SEGMENT];
    Coin* coinsArray[MAX_COINS_PER_SEGMENT];
};

#endif // ENTITY_GROUND_H
