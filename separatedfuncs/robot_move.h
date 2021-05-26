//T09_G12

#ifndef robot_move_H
#define robot_move_H

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

#include "main.cpp"

//Robots movement
robot_move(int robot_index, game_info& gameplay);

//defining constants
const int robot_move_place = 0; //used to determine the robts vertical and horizontal movement
const int line = 0; //robot line
const int column = 1; //robot column
const int condition = 2; //robot condition (alive or dead)
const char alive_player = 'H';
const char dead_player = 'h';
const char alive_robot = 'R';
const char dead_robot = 'r';
const char wall = '*';
const char empty_map_space = ' ';

#endif
