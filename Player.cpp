// Player.cpp
#include "headers/Player.h"
#include "headers/Map.h"
#include "iostream"
#include "headers/Colors.h"

Player::Player(Vector pos, int health, int maxMoves) : Character(pos), healthPoints(health), maxMoves(maxMoves), movesRemaining(maxMoves) {}

int Player::getHealthPoints() const
{
    return healthPoints;
}

int Player::getMovesRemaining() const
{
    return movesRemaining;
}

void Player::decreaseMovesRemaining()
{
    movesRemaining--;
}

void Player::draw()
{
    std::cout << BLUE << " P " << RESET;
}

void Player::move()
{
    std::cout << "Player moving..." << std::endl;

    // Ask the user for input to choose a direction
    std::cout << "Choose a direction (1: right, 2: down, 3: left, 4: up): ";
    int direction;
    std::cin >> direction;

    switch (direction)
    {
    case 1:
        // Move right
        setPosition(Vector(getPosition().x + 1, getPosition().y));
        break;
    case 2:
        // Move down
        setPosition(Vector(getPosition().x, getPosition().y + 1));
        break;
    case 3:
        // Move left
        setPosition(Vector(getPosition().x - 1, getPosition().y));
        break;
    case 4:
        // Move up
        setPosition(Vector(getPosition().x, getPosition().y - 1));
        break;
    default:
        // Stay in the current position
        std::cout << "Invalid direction. Staying in the current position." << std::endl;
        break;
    }

    // Decrement moves remaining
    decreaseMovesRemaining();
}

Vector Player::simulateNextMove()
{
    // Simulate the next move without actually changing the player's position
    Vector simulatedPosition = getPosition();

    // Randomly choose a direction (0: stay, 1: move right, 2: move up, 3: move left, 4: move down)
    int direction = rand() % 5;

    switch (direction)
    {
    case 1:
        simulatedPosition.x += 1;
        break;
    case 2:
        simulatedPosition.y += 1;
        break;
    case 3:
        simulatedPosition.x -= 1;
        break;
    case 4:
        simulatedPosition.y -= 1;
        break;
    default:
        // Stay in the current position
        break;
    }

    return simulatedPosition;
}

void Player::update()
{
    // Custom logic for player update
    std::cout << "Player updating..." << std::endl;
}

void Player::sense(Map *map)
{
    // Custom logic for player sensing the map state
    std::cout << "Player sensing map..." << std::endl;
}

void Player::reduceHealthPoints(int amount)
{
    healthPoints -= amount;
    if (healthPoints < 0)
    {
        healthPoints = 0;
    }
}
void Player::setHealthPoints(int value)
{
    healthPoints = value;
}