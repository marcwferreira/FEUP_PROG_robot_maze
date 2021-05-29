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
#include "maze_name.h"

//makes the file name to open the map
std::string maze_name(int maze_num, bool winner_file){

    std::string maze;

    //select maze txt file
    if(winner_file){
        //select maze txt file for the winners (create winner file name)
        if (maze_num < maze_num_check) {
            maze = "MAZE_0" + std::to_string(maze_num) + "_WINNERS.TXT";
        }
        else {
            maze = "MAZE_" + std::to_string(maze_num) + "_WINNERS.TXT";
        }
    }
    //select max txt file for gameplay (create game file name)
    else if(!winner_file){
        if (maze_num < maze_num_check) {
            maze = "MAZE_0" + std::to_string(maze_num) + ".TXT";
        }
        else {
            maze = "MAZE_" + std::to_string(maze_num) + ".TXT";
        }
    }

    return maze;
}