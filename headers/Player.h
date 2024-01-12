// Player.h
#pragma once
#include "Character.h"
class Player : public Character
{
private:
    int healthPoints;
    int maxMoves;
    int movesRemaining;

public:
    Player(Vector pos, int health, int maxMoves);

    int getHealthPoints() const;
    int getMovesRemaining() const;
    void decreaseMovesRemaining();


    void draw() override;
    void move() override;
    Vector simulateNextMove();
    void update() override;
    void sense(Map *map) override;
    void reduceHealthPoints(int amount);
    void setHealthPoints(int value);
};
