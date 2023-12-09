// Entity_Ground.h
#ifndef ENTITY_GROUND_H
#define ENTITY_GROUND_H

#include "Vars.h"
#include "Entity.h"
#include <Arduboy2.h>
#include "sprites.h"
#include "Entity_Enemy.h"

class Entity_Ground : public Entity {
public:
    Entity_Ground();
    Entity_Ground(int initialX, int initialY, int arrayIndex);
    ~Entity_Ground();

    void update() override;
    void draw(Arduboy2 &arduboy) override;

    void drawEnemies(Arduboy2 &arduboy);
    bool isGroundAt(int posX);
    void addEnemy(const Enemy& enemyData);
    bool enemyCollision(int playerX, int playerY);

private:
    uint8_t groundArray[GROUND_DEFINITION_SIZE];

    Entity_Enemy* enemyArray[MAX_ENEMIES_PER_SEGMENT]; // Array of pointers to Entity_Enemy
    int numEnemies;

    Coin coinArray[MAX_COINS_PER_SEGMENT];
    int numCoins;

    int _playerX;
    int _playerY;

};

#endif // ENTITY_GROUND_H
