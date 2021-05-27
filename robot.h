//T09_G12

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdio.h>
#include <chrono>
#include <iomanip>
#include <algorithm>

//our files
#include "move_pos.h"

class robot {
public:
    robot(int idset, int row, int col);
    int getid();
    char getsymbol(); // get char representation of robot (R if alive, r if dead)
    int getrow();
    int getcol();
    position getposition();
    bool isalive();
    void setrow(int x);
    void setcol(int y);
    void setposition(const position &pos);
    void setasdead();

private:
    static int robotCounter; //used to attribute automatically the id to the robots
    int id;
    int row, col;
    bool alive;
};

const bool robot_alive = true;
const char robot_alive_char = 'R';
const char robot_dead_char = 'r';

#endif