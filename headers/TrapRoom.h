#pragma once
#include "Room.h"
#include "Player.h"

class TrapRoom : public Room
{
public:
    TrapRoom(Vector pos);

    void visit(Player *player) override;
};
