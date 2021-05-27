#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Maze.h"
#include "Robot.h"

using namespace std;

Game::Game() {};

Game::Game(string maze_name) 
{
    string line;

    ifstream mazeFile(maze_name);

    while (getline(mazeFile, line)) {
        int count = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == 'R') {
                Robot r;
                listRobot.push_back(&r);
                r.setPosition(count, i);
            }
            else if (line[i] == 'H') {
                Player p;
                p.setPosition(count, i);
            }
            else {

            }
        }
        count++;


    }

    mazeFile.close();

    Maze maze(maze_name);
}

