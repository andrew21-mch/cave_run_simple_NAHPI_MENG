#include "headers/Character.h"
#include "headers/Map.h"
#include "iostream"

Character::Character(Vector pos) : position(pos) {}

Vector Character::getPosition() const
{
    return position;
}

void Character::setPosition(Vector newPos)
{
    position = newPos;
}

void Character::draw()
{
    std::cout << "Drawing character at position (" << position.x << ", " << position.y << ")" << std::endl;
}

void Character::move()
{
    // Default move does nothing
}

void Character::update()
{
    // Default update does nothing
}

void Character::sense(Map *map)
{
    // Default sense does nothing
}
