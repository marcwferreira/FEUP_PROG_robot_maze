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
#include "read_times.h"
#include "maze_check.h"
#include "maze_name.h"

void read_times(){

    int maze_num;
    bool maze_not_exist;

    std::string winner_file_name; //open file to read times

    //ask the player for the maze numbem to show time
            std::cout << "Choose the maze number you wish to see the records (0 for main menu): ";
             do{
                std::cin >> maze_num;
                maze_not_exist = maze_check(maze_num, winner_file_yes_read_times); //test if maze exist
                if(std::cin.eof()){
                    std::exit(0);
                }
                else if(maze_num == main_menu_read_times){
                    break;
                }
                else if(std::cin.fail() || maze_not_exist){
                    std::cout << "Not a valid inut or maze winners doens't exist" << std::endl;
                    std::cout << "please choose the maze number (0 for main menu): ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
            }while( std::cin.fail() || maze_not_exist);

            if(maze_num != main_menu_read_times){
                winner_file_name = maze_name(maze_num, winner_file);

                //open the file
                std::ifstream winnerfile;
                winnerfile.open(winner_file_name);

                std::string line;

                //if opening the file fails it gives an error
                if (!winnerfile.is_open()) {
                    std::cout << "Could not open the winner file for the maze #" << maze_num << std::endl;
                }
                //if opening the files works it prints its content
                else {
                    while (getline(winnerfile, line)) {
                        std::cout << line << std::endl;
                    }
                } winnerfile.close();
            }

}