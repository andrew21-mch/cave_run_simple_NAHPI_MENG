#pragma once
#include "Player.h"
#include "Monster.h"
#include "Map.h"

class Game
{
private:
    Player *player;
    Monster *monster;
    Map *map;

public:
    Game(Player *p, Monster *m, Map *map);

    void run();
    void handlePlayerMove();
};
