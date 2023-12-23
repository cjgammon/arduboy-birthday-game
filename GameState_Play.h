// GameState_Play.h
#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include <avr/pgmspace.h>
#include "Vars.h"
#include "GameState.h"
#include "Character.h"
#include "Entity_Ground.h"
#include "EntityManager_Ground.h"


class GameState_Play : public GameState {
public:
    void init() override;
    void update() override;
    void draw() override;
    void cleanup() override;
private:
    Character* playerCharacter;
    EntityManager_Ground groundManager;

    void createGroundEntities();
    void playerDie();
};



#endif
