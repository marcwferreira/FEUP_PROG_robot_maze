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
#include "Robot.h"
#include "Move_pos.h"

//constructor
Robot::Robot() {
    row = -1;
    col = -1;
    id = -1;
    alive = true;
}
Robot::Robot(int ID, int row_input,int col_input){
    row = row_input;
    col = col_input;
    id = ID;
    alive = true;
}

//getters
int Robot::getID() const { return id; }
int Robot::getRow() const {return row;}
int Robot::getCol() const {return col;}
char Robot::getSymbol() const {
    if (alive==true){
        return alive_robot;
    }
    else{
        return dead_robot;
    }
}
Position Robot::getPosition() const {
    Position robot_return;
    robot_return.row = row;
    robot_return.col = col;
    return robot_return;
}
bool Robot::isAlive() const {return alive;}

//setter
void Robot::setRow(int x){
    row = x;
}
void Robot::setCol(int y){
    col = y;
}
void Robot::setID(char ID) {
    id = ID;
}
void Robot::setPosition(const Position &pos){
    row = pos.row;
    col = pos.col;
}

//robot movement
void Robot::robotMove(Movement delta) {
    row = row + delta.dRow;
    col = col + delta.dCol;
}

//set robot dead
void Robot::setAsDead(){
    alive = false;
}