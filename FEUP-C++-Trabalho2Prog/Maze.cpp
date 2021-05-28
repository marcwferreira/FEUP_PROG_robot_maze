#include <iostream>
#include "Maze.h"
#include "Post.h"
#include "Player.h"
#include "Robot.h"

using namespace std;

Maze::Maze() {}
Maze::Maze(string maze_name) {

    string line;

    ifstream mazeFile(maze_name);

    while (getline(mazeFile, line)) {
        int count = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '*') {
                Post postes;
                postes.setPosition(count, i);
                listPost.push_back(postes);
            }
            else if (line[i] == '+') {
                Post postes;
                postes.setPosition(count, i);
                postes.setState(false);
                listPost.push_back(postes);
            }
        }
        count++;
    }
}

bool Maze::checkPost(int x, int y) {

    Position p;
    p.setPosition(x, y);

    for (Post pst : listPost)
    {
        bool flag = false;

        Position position_post = pst.getPosition();
        if (position_post.getX() == p.getX()) {
            if (position_post.getY() == p.getY()) {
                if (pst.getState() == true) {
                    flag = true;
                    break;
                }
            }
        }

        return flag;
    }
}

