#pragma once
#include "Vector.h"

class Map;

class Character
{
private:
    Vector position;

public:
    Character(Vector pos);

    Vector getPosition() const;
    void setPosition(Vector newPos);

    virtual void draw();
    virtual void move();
    virtual void update();
    virtual void sense(Map *map);
};
