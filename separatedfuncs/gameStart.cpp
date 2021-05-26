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

//our functions
#include "gameStart.h" //this file
#include "mazeName.h"

using namespace std;

//Function for the main menu - returns the option chosen by the user
int game_start() {

    std::string option;//variable to store the user input
    int option_selected;//convert string into int

    std::string title_line;//for title screen

    //print title screen and menu
    ifstream title_game;
    title_game.open("TITLE.TXT");
    //alternative title if file does not exist
    if(!title_game.is_open()){
        cout << "Welcome to Robot Maze" << endl;
        cout << "please choose an option: " << endl;
        cout << "1- Rules" << endl << "2- Play" << endl;
        cout << "3- Time Records" << endl << "0- Exit" << endl;
    }
    //title if file exist
    else{
        while (getline(title_game, title_line)) {
            cout << title_line << endl;
        } 
        title_game.close();
    }

    //asks repeatedly for an option only accepting 1, 2 or 0 (rules, play, quit)
    do {
        std::cin >> option;
        if(cin.eof()){
            std::exit(0);
        }
        else if(option != rules & option != play_game & option != exit_game & option != time_records) {
            cout << "Input not valid, please try again." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    } while (option != rules & option != play_game & option != exit_game & option != time_records);

    //convert option into int
    option_selected = stoi(option);

    return option_selected;
}
