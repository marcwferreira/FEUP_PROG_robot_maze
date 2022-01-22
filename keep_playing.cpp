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
#include "keep_playing.h"

//loop until valid option is chosen (ask the user if he wants to keep playing (goes to main menu) )
std::string keep_playing(){

    std::string keep_play; //var to store option

    //print message
    std::cout << "Do you want to play (1- MAIN MENU or 0- EXIT)?" << std::endl;
    std::cout << "1- YES" << std::endl << "0- NO" << std::endl;
    std::cout << "Please select an option: ";

    //loop until valid answer
    do{
        std::cin >> keep_play;
        if(std::cin.eof()){
            std::exit(0);
        }
        else if(keep_play != no_playing && keep_play != yes_playing){
            std::cout << "Please select a valid option (1- MAIN MENU or 0- EXIT): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }while(keep_play != no_playing & keep_play != yes_playing);

    return keep_play; //return answer
}