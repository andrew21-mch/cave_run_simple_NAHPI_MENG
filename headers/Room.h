#pragma once
#include "Vector.h"

class Player; // Forward declaration

class Room
{
private:
    Vector position;

public:
    Room(Vector pos);

    Vector getPosition() const;
    virtual void visit(Player *player);
};
