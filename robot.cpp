//T09_G12

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
#include "robot.h"
#include "move_pos.h"

robot::robot(int idset, int rowset, int colset){
    id = idset;
    row = rowset;
    col = colset;
    alive = robot_alive;
}

int robot::getid(){
    return id;
}

char robot::getsymbol(){
    if (alive == robot_alive){
        return robot_alive_char;
    }
    else{
        return robot_dead_char;
    }
}

int robot::getrow(){
    return row;
}

int robot::getcol(){
    return col;
}

position robot::getposition(){
    position robotpos;
    robotpos.row = row;
    robotpos.col = col;
    return robotpos;
}

bool robot::isalive(){
    return alive;
}

void robot::setrow(int x){
    if(alive == robot_alive){
        row = x;
    }
}

void robot::setcol(int y){
    if(alive == robot_alive){
        col = y;
    }
}

void robot::setposition(const position &pos){
    if(alive == robot_alive){
        row = pos.row;
        col = pos.col;
    }
}

void robot::setasdead(){
    alive = false;
}