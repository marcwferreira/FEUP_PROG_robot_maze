#include <iostream>
#include <string>
#include <list>
#include "Player.h"
#include "Maze.h"
#include "Robot.h"

using namespace std;

class Game
{
public:
    Game(string maze_name) {

        string line;

        ifstream mazeFile(maze_name);

        while (getline(mazeFile, line)) {
            int count = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == 'R') {
                    Robot *r;
                    listRobot.push_back(r);
                    Robot r = find(listRobot.begin(), listRobot.end(), );
                }
                else if (line[i] = 'H') {
                    Player p;
                    p.setPosition(count, i);
                }
            }
            count++;
        }

        mazeFile.close();

        maze = Maze(maze_name);
    }

private:

    Player player_1;
    Maze maze;
    list <Robot*> listRobot;
};

