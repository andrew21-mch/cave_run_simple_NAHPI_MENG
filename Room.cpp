#include "headers/Room.h"
#include "headers/Player.h"
#include "iostream"

Room::Room(Vector pos) : position(pos) {}

Vector Room::getPosition() const
{
    return position;
}

void Room::visit(Player *player)
{
    // Logic for player visiting the room
    std::cout << "Player visiting room at position (" << position.x << ", " << position.y << ")" << std::endl;
}
