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
#include "Move_pos.h"

class Robot {

public:
    Robot();
    Robot(int ID, int row, int col);
    int getID() const;
    int getRow() const;
    int getCol() const;
    char getSymbol() const; // get char representation of robot (R if alive, r if dead)
    Position getPosition() const;
    bool isAlive() const; //verify if a robot is dead or alive
    void setRow(int x);
    void setCol(int y);
    void setID(char ID);
    void setPosition(const Position &pos); //set the position of a robot in the map
    void robotMove(Movement delta);
    void setAsDead(); //set the robot as dead
    //other methods
private:
    int id;
    int row, col;
    bool alive;
};

//constants
const char alive_robot = 'R';
const char dead_robot = 'r';

#endif