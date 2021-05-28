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
                listRobot.push_back(r);
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

Player Game::getPlayer() { return player_1; }

Maze Game::getMaze() { return maze; }

bool Game::checkRobot(int x, int y) {

    Position p;
    p.setPosition(x, y);
    Robot rt;

    for (Robot r : listRobot)
    {
        bool flag = false;

        Position position_robot = r.getPosition();
        if (position_robot.getX() == p.getX()) {
            if (position_robot.getY() == p.getY()) {
                flag = true;
                break;
            } 
        }

        return flag;
    }
}

bool Game::robotMovement(Player player) {

    Maze maze = this->getMaze();
    bool flag = true;

    for (Robot rb : listRobot)
    {
        Position position_robot = rb.getPosition();
        Position position_player = player.getPosition();

        if (position_robot.getX() < position_player.getX()) { position_robot.setX(position_robot.getX() + 1); }

        else if (position_robot.getY() < position_player.getY()) { position_robot.setY(position_robot.getY() + 1); }

        else if (position_robot.getX() > position_player.getX()) { position_robot.setX(position_robot.getX() - 1); }

        else if (position_robot.getY() > position_player.getY()) { position_robot.setY(position_robot.getY() - 1); }

        if (position_robot.getX() == position_player.getX() && position_robot.getY() == position_player.getY()) {
            break;
            flag = false;
        }
        else if (maze.checkPost(position_robot.getX(), position_robot.getY())) { rb.setState(false); }
    }

    return flag;
}

