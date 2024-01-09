// Map.h
#pragma once
#include "Vector.h"
#include <vector>

class Room;   // Forward declaration
class Player; // Forward declaration
class Monster; // Forward declaration

class Map
{
private:
    std::vector<Room *> rooms;
    Vector dimensions;
    Vector exitPosition;
    Player *player;
    Monster *monster;

public:
    Map(Vector dims, Vector exitPos, Player *p, Monster *m);

    void addRoom(Room *room);
    Room *getRoomAtPosition(Vector pos);
    Vector getDimensions() const;
    Vector getExitPosition() const;
    void draw();
};
