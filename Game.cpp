// Game.cpp
#include "headers/Game.h"
#include "headers/Player.h"
#include "headers/Monster.h"
#include "headers/TrapRoom.h"
#include "headers/PoisonRoom.h"
#include "headers/Map.h"
#include "iostream"

Game::Game(Player *p, Monster *m, Map *map) : player(p), monster(m), map(map) {}

void Game::run()
{
    std::cout << "Welcome to the Game!" << std::endl;

    while (player->getMovesRemaining() > 0 && player->getHealthPoints() > 0)
    {

        // Display game state
        player->draw();
        monster->draw();
        // Player's turn
        std::cout << "Player's Turn:" << std::endl;

        // Perform two moves in one turn
        handlePlayerMove();
        player->update();
        player->sense(map);

        // Display player's and monster's positions
        std::cout << "Player position: P(" << player->getPosition().x << ", " << player->getPosition().y << ")" << std::endl;
        std::cout << "Monster position: M(" << monster->getPosition().x << ", " << monster->getPosition().y << ")" << std::endl;

        // Check if player reached the exit
        if (player->getPosition().x == map->getExitPosition().x && player->getPosition().y == map->getExitPosition().y)
        {
            std::cout << "Congratulations! You reached the exit. You win!" << std::endl;
            break;
        }

        // Check if the current room is a TrapRoom
        Room *currentRoom = map->getRoomAtPosition(player->getPosition());
        PoisonRoom *poisonRoom = dynamic_cast<PoisonRoom *>(currentRoom);

          // Check if the current room is a TrapRoom
        TrapRoom *trapRoom = dynamic_cast<TrapRoom *>(currentRoom);

        // Monster's turn
        std::cout << "Monster's Turn:" << std::endl;

        // Move monster toward the player
        monster->moveTowardPlayer(player);

        monster->update();
        monster->sense(map);

        map->draw();

        // Check if monster caught the player
        if (player->getPosition().x == monster->getPosition().x && player->getPosition().y == monster->getPosition().y)
        {
            std::cout << "Game Over! The monster caught you. You lose!" << std::endl;
            break;
        }

        // Check if the current room is a PoisonedRoom and visit it
        if (poisonRoom)
        {
            poisonRoom->visit(player);
        }

         // Check if the current room is a TrapRoom and visit it
        if (trapRoom)
        {
            trapRoom->visit(player);
        }
    }

    // Check if the game ended due to running out of moves
    if (player->getMovesRemaining() <= 0)
    {
        std::cout << "Out of moves! Game over." << std::endl;
    }
}

void Game::handlePlayerMove()
{

    // Store the current position for potential rollback
    Vector currentPosition = player->getPosition();

    // Perform the move based on user input
    player->move();

    // Check if the new position is within the map boundaries
    if (player->getPosition().x < 0 || player->getPosition().y < 0 || player->getPosition().x >= map->getDimensions().x || player->getPosition().y >= map->getDimensions().y)
    {
        std::cout << "***********************************************************" << std::endl;
        std::cout << "Cannot move. Hit the wall. Staying in the current position." << std::endl;
        std::cout << "***********************************************************" << std::endl;
        // Rollback to the previous position
        player->setPosition(currentPosition);
    }

    // Decrement moves remaining
    player->decreaseMovesRemaining();
}
