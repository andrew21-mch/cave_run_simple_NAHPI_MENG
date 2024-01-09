#pragma once
#include "Room.h"

class PoisonRoom : public Room
{
public:
    PoisonRoom(Vector pos);

    void visit(Player *player) override;
};
