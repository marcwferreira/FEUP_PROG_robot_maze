//T09_G12

#ifndef MAZENAME_H
#define MAZENAME_H

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

//makes the maze file name
std::string maze_name(int maze_num, bool winner_file);

//used to check if maze has a number lower than 10
const int maze_num_check = 10;

#endif