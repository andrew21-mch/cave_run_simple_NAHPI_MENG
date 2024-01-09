// Map.cpp
#include "headers/Map.h"
#include "headers/Room.h"
#include "headers/Player.h"
#include "headers/Monster.h"
#include <iostream> // Include the necessary header for std::cout


Map::Map(Vector dims, Vector exitPos, Player *p, Monster *m) : dimensions(dims), exitPosition(exitPos), player(p), monster(m) {}

void Map::addRoom(Room *room)
{
    rooms.push_back(room);
}

Room *Map::getRoomAtPosition(Vector pos)
{
    for (Room *room : rooms)
    {
        if (room->getPosition().x == pos.x && room->getPosition().y == pos.y)
        {
            return room;
        }
    }
    return nullptr;
}

Vector Map::getDimensions() const
{
    return dimensions;
}

Vector Map::getExitPosition() const
{
    return exitPosition;
}

void Map::draw()
{
    // Draw the map

    std::cout << " ****Updating Map*** " << std::endl;
    std::cout << "========================" << std::endl;

    for (int y = 0; y < dimensions.y; ++y)
    {
        for (int x = 0; x < dimensions.x; ++x)
        {
            Vector currentPos(x, y);
            Room *currentRoom = getRoomAtPosition(currentPos);

            if (currentRoom)
            {
                std::cout << "\033[33m R \033[0m"; // YELLOW
            }
            else if (player && player->getPosition().x == x && player->getPosition().y == y)
            {
                player->draw();
            }
            else if (monster && monster->getPosition().x == x && monster->getPosition().y == y)
            {
                monster->draw();
            }
            else
            {
                // If no room, player, or monster, draw '*'
                std::cout << " * ";
            }
        }
        std::cout << '\n';
    }
    std::cout << "========================" << std::endl;
}
