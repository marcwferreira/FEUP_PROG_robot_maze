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

//get the input from user for a maze number and check if it exists
int maze_choose(bool type_of_check){

    int maze_num;
    bool maze_not_exist;

    //ask the player and verifies if it is a valid answer (loop until yes)
    std::cout << "Choose the maze number you wish to select (0 to go back): ";
        do{
            std::cin >> maze_num;
            maze_not_exist = maze_check(maze_num, type_of_check); //test if maze exist
            if(std::cin.eof()){
                std::exit(0);
            }
            else if(maze_num == main_menu_maze_choose){ //see if player choose to go to back
                break;
            }
            else if(std::cin.fail() || maze_not_exist){ //see if it is a valid option
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Not a valid input or file doens't exist" << std::endl;
                std::cout << "please choose the maze number (0 to go back): ";
            }
        }while( std::cin.fail() || maze_not_exist);

    return maze_num;
}