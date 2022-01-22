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
#include "maze_check.h"
#include "maze_name.h"

//check if the game file (or winner file if selected) exists
bool maze_check(int maze_num, bool winner_check){

    bool file_exist = false;

    std::string maze;

    //decide if will check a winner file or game file and get the file name
    if(winner_check == false){
        maze = maze_name(maze_num, game_file);
    }
    else if(winner_check == true){
        maze = maze_name(maze_num, winner_file);
    }

    //tries opening the file (returns true if it can do it)
    std::ifstream mazefile;
    mazefile.open(maze);
    if (mazefile.fail()) {
        file_exist = true;
    }

    return file_exist;
}