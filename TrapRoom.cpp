#include "headers/TrapRoom.h"
#include "iostream"

TrapRoom::TrapRoom(Vector pos) : Room(pos) {}

void TrapRoom::visit(Player *player)
{
    // Logic for player visiting the trap room
    std::cout << "Player visiting trap room at position (" << getPosition().x << ", " << getPosition().y << ")" << std::endl;
}
