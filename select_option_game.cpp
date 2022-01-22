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
#include "read_title.h"

//Function for the main menu (opitions selection) - returns the option chosen by the user
int select_option_game() {
    
    std::string option;//variable to store the user input
    int option_selected;//convert string into int

    //read the rules to the player
    read_title();

    //asks repeatedly for an option only accepting 1, 2 or 0 (rules, play, quit)
    do {
        std::cin >> option;
        if(std::cin.eof()){
            std::exit(0);
        }
        else if(option != rules & option != play_game & option != exit_game & option != time_records) {
            std::cout << "Input not valid, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    } while (option != rules & option != play_game & option != exit_game & option != time_records);

    //convert option into int
    option_selected = stoi(option);

    return option_selected;
}