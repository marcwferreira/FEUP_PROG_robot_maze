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

std::string maze_name(int maze_num, bool winner_file){

    std::string maze;

    //select maze txt file
    if(winner_file == true){
        //select maze txt file for the winners
        if (maze_num < maze_num_check) {
            maze = "MAZE_0" + std::to_string(maze_num) + "_WINNERS.TXT";
        }
        else {
            maze = "MAZE_" + std::to_string(maze_num) + "_WINNERS.TXT";
        }
    }
    else{
        if (maze_num < maze_num_check) {
            maze = "MAZE_0" + std::to_string(maze_num) + ".TXT";
        }
        else {
            maze = "MAZE_" + std::to_string(maze_num) + ".TXT";
        }
    }

    return maze;
}