#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>

#include "GameObject.h"
#include "Robot.h"
#include "Maze.h"
#include "Player.h"

using namespace std;

class Game
{

private:

    Player player_1;
    Maze maze;
    list <Robot> listRobot;

public:
    Game();
    //Create the gameObjects including maze, robots and player
    Game(string maze_name);

    Player getPlayer();

    Maze getMaze();

    bool robotMovement(Player player);

    bool checkRobot(int x, int y);
};

#endif

