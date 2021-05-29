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
#include "player_win.h"

int main(){

    //constants
    const int rules = 1;
    const int play_game = 2;
    const int show_times = 3;
    const int exit = 0;
    const std::string no_playing = "0";
    const std::string yes_playing = "1";
    const bool game_file = false;
    const bool check_type_game = false;
    const int main_menu = 0;

    //variables
    std::string play_again;
    int maze_number;
    std::string maze_selection;
    bool player_has_won;
    int player_time;

    //repeat loop while player wants to keep playing
    do{

        //ask player for for the menu option
        int option = select_option_game();

        //main menu options
        if (option == rules){
            //read the rules
            read_rules();

            //ask if want to continue playing
            play_again = keep_playing();
        }
        else if (option == play_game){         
            //ask player for the maze he wants to play
            maze_number = maze_choose(check_type_game);

            //only start game if player choose a maze (0 is to back)
            if (maze_number != main_menu) {
                //get maze_name
                maze_selection = maze_name(maze_number, game_file);

                //create game object
                Game gameplay(maze_selection);
                //start time count
                auto start = std::chrono::steady_clock::now();
                //calls game funcion 
                player_has_won = gameplay.play();
                //stop time counter
                auto end = std::chrono::steady_clock::now();

                //ask to save time
                if (player_has_won) {
                    player_time = std::chrono::duration_cast<std::chrono::seconds>(end - start).count(); //calculate player time
                    std::cout << "you won!" << std::endl;
                    player_win(player_time, maze_number); //function to save the player time in the records
                }
                else if (!player_has_won) {
                    std::cout << "you lost!" << std::endl;
                }
            }

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
            play_again = no_playing;//breaks out of the while loop of "playing again"
        }

    }while(play_again == yes_playing); //loop while player wants to keep playing

    return 0;
}