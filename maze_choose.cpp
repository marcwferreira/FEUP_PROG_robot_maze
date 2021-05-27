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
#include "maze_choose.h"
#include "maze_check.h"

int maze_choose(){

    int maze_num;
    bool maze_not_exist;

    std::cout << "Choose the maze number you wish to play (0 for main menu): ";
             do{
                std::cin >> maze_num;
                maze_not_exist = maze_check(maze_num, winner_file_yes_maze_choose); //test if maze exist
                if(std::cin.eof()){
                    std::exit(0);
                }
                else if(maze_num == main_menu_maze_choose){
                    break;
                }
                else if(std::cin.fail() || maze_not_exist){
                    std::cout << "Not a valid inut or maze winners doens't exist" << std::endl;
                    std::cout << "please choose the maze number (0 for main menu): ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
            }while( std::cin.fail() || maze_not_exist);

    return maze_num;
}