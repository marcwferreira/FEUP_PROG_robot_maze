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

void read_title(){

    std::string title_line;//for title screen

    //print title screen and menu
    std::ifstream title_game;
    title_game.open("TITLE.TXT");
    //alternative title if file does not exist
    if(!title_game.is_open()){
        std::cout << "Welcome to Robot Maze" << std::endl;
        std::cout << "please choose an option: " << std::endl;
        std::cout << "1- Rules" << std::endl << "2- Play" << std::endl;
        std::cout << "3- Time Records" << std::endl << "0- Exit" << std::endl;
    }
    //title if file exist
    else{
        while (getline(title_game, title_line)) {
            std::cout << title_line << std::endl;
        } 
        title_game.close();
    }

}