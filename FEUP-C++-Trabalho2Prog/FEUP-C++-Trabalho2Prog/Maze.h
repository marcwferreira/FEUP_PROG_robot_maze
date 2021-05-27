#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <string>
#include <list>

#include "GameObject.h"
#include "Post.h"

using namespace std;

class Maze
{
public:
    Maze();
    Maze(string maze_name);

private:
    list <Post*> listPost;
};

#endif

