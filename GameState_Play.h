// GameState_Play.h
#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include <avr/pgmspace.h>
#include "Vars.h"
#include "GameState.h"
#include "GameUI.h"
#include "Character.h"
#include "Entity_Ground.h"
#include "EntityManager_Ground.h"


class GameState_Play : public GameState {
public:
    void init() override;
    void update(Arduboy2 &arduboy) override;
    void draw(Arduboy2 &arduboy) override;
    void cleanup() override;
private:
    GameUI gameUI; // Create an instance of the GameUI class 
    Character* playerCharacter;
    EntityManager_Ground groundManager;
    //EntityManager_Enemy enemyManager;

    void createGroundEntities();
    //void createEnemyEntities();
};



#endif
