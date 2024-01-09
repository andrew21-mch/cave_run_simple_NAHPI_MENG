// Monster.cpp
#include "headers/Monster.h"
#include "headers/Character.h"
#include "headers/Room.h"
#include "headers/Map.h"
#include "iostream"
#include "headers/Colors.h"

Monster::Monster(Vector pos) : Character(pos) {}

void Monster::moveTowardPlayer(Player *player)
{
    // Simulate the player's next move
    Vector anticipatedPosition = player->simulateNextMove();

    // Move the monster toward the anticipated position
    int deltaX = anticipatedPosition.x - getPosition().x;
    int deltaY = anticipatedPosition.y - getPosition().y;

    if (std::abs(deltaX) > std::abs(deltaY))
    {
        // Move horizontally toward the player
        setPosition(Vector(getPosition().x + (deltaX > 0 ? 1 : -1), getPosition().y));
    }
    else
    {
        // Move vertically toward the player
        setPosition(Vector(getPosition().x, getPosition().y + (deltaY > 0 ? 1 : -1)));
    }
}

void Monster::move()
{
    // Custom logic for monster movement
    std::cout << "Monster moving..." << std::endl;
}

void Monster::draw()
{
    std::cout << RED << " M " << RESET;
}

void Monster::sense(Map *map)
{
    // Custom logic for monster sensing the map state
    std::cout << "Monster sensing map..." << std::endl;
}
