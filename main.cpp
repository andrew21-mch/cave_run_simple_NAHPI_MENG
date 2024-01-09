// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "headers/Player.h"
#include "headers/Monster.h"
#include "headers/Map.h"
#include "headers/Room.h"
#include "headers/PoisonRoom.h"
#include "headers/TrapRoom.h"
#include "headers/Game.h"

int main()
{
    // Initialize random seed
    std::srand(std::time(0));

    // Create player, monster, and map objects
    Player *player = new Player(Vector(0, 7), 10, 100);
    Monster *monster = new Monster(Vector(7, 4));
    Map *map = new Map(Vector(8, 8), Vector(7, 0), player, monster);

    // Create rooms and add them to the map
    // Room *room1 = new Room(Vector(1, 1));
    Room *room2 = new PoisonRoom(Vector(2, 2));
    Room *room3 = new TrapRoom(Vector(3, 3));
    // map->addRoom(room1);
    map->addRoom(room2);
    map->addRoom(room3);

    // Assign the map to the player and monster
    player->sense(map);
    monster->sense(map);

    // Create the game object and run the game
    Game *game = new Game(player, monster, map);

    game->run();

    // Clean up allocated memory
    delete player;
    delete monster;
    delete map;
    // delete room1;
    delete room2;
    delete room3;
    delete game;

    return 0;
}
