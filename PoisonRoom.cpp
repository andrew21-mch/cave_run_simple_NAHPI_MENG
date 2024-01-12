// PoisonRoom.cpp
#include "headers/PoisonRoom.h"
#include "headers/Player.h"
#include "iostream"

PoisonRoom::PoisonRoom(Vector pos) : Room(pos) {}

void PoisonRoom::visit(Player *player)
{
    // Logic for player visiting the trap room
    std::cout << "Player visiting Poisoned room at position (" << getPosition().x << ", " << getPosition().y << ")" << std::endl;

    // Reduce player's health points (you can adjust the value as needed)
    int damage = 2; // or any other value
    player->reduceHealthPoints(damage);

    std::cout << "Player's health points reduced by " << damage << ". Current health points: " << player->getHealthPoints() << std::endl;
}
