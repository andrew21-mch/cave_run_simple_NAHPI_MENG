// Monster.h
#pragma once
#include "Character.h"
#include "Player.h"

class Monster : public Character
{
public:
    Monster(Vector pos);

    void moveTowardPlayer(Player *player);
    void move() override;
    void draw() override;
    void sense(Map *map) override;
};
