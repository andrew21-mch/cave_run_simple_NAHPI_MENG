#!/bin/bash

g++ -c Vector.cpp -o out/Vector.o
g++ -c Character.cpp -o out/Character.o
g++ -c Room.cpp -o out/Room.o
g++ -c PoisonRoom.cpp -o out/PoisonRoom.o
g++ -c TrapRoom.cpp -o out/TrapRoom.o
g++ -c Player.cpp -o out/Player.o
g++ -c Monster.cpp -o out/Monster.o
g++ -c Map.cpp -o out/Map.o
g++ -c Game.cpp -o out/Game.o
g++ -c main.cpp -o out/main.o


g++ out/Vector.o out/Character.o out/Room.o out/PoisonRoom.o out/TrapRoom.o out/Player.o out/Monster.o out/Map.o out/Game.o out/main.o -o out/run

# Run the executable
./out/run
