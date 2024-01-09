// PoisonRoom.cpp
#include "headers/PoisonRoom.h"
#include "iostream"

PoisonRoom::PoisonRoom(Vector pos) : Room(pos) {}

void PoisonRoom::visit(Player *player)
{
    // Logic for player visiting the poison room
    std::cout << "Player visiting poison room at position (" << getPosition().x << ", " << getPosition().y << ")" << std::endl;
}
