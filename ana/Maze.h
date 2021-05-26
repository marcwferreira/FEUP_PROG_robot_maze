#include <iostream>
#include <string>
#include <list>
#include "Post.h"

using namespace std;
class Maze
{
    Maze(string maze_name) {
        
        string line;

        ifstream mazeFile(maze_name);

        while (getline(mazeFile, line)) {
            int count = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == '*') {
                    Post p;
                    p.setPosition(count, i);
                    listPost.push_back(p);
                }
                else if (line[i] == '+') {
                    Post p;
                    p.setPosition(count, i);
                    p.setState(false);
                    listPost.push_back(p);
                }
            }
            count++;
        }
    }

private:
    list <Post*> listPost;
};

