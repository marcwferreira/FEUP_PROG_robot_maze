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
#include "select_option_game.h"
#include "keep_playing.h"
#include "read_rules.h"
#include "read_times.h"
#include "maze_choose.h"
#include "maze_name.h"
#include "Game.h"

int main(){

    //constants
    const int rules = 1;
    const int play_game = 2;
    const int show_times = 3;
    const int exit = 0;

    const std::string no_playing = "0";
    const std::string yes_playing = "1";
    const bool game_file = false;

    //variables
    std::string play_again;
    int maze_number;
    std::string maze_selection;

    do{

        //ask player for for the menu option
        int option = select_option_game();

        if (option == rules){
            //read the rules
            read_rules();

            //ask if want to continue playing
            play_again = keep_playing();
        }
        else if (option == play_game){
            //game 
            
            //ask player for maze
            maze_number = maze_choose();

            //get maze_name
            maze_selection = maze_name(maze_number, game_file);

            //open file map
            Game gameplay(maze_selection);
            gameplay.play();
            //load player

            //load map

            //start time

            /*
            do{
            //play - player movement and robot movement (detect player leave door)
            }while("this si true");
            */

            //end time

            //ask to save time

            //ask if want to continue playing
            play_again = keep_playing();
        }
        else if ( option == show_times){
            //show time reords
            read_times();

            //ask if want to continue playing
            play_again = keep_playing();
        }
        else if (option == exit){
            return 0;
        }

    }while(play_again == yes_playing);

    return 0;
}