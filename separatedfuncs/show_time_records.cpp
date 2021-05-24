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
#include "gameStart.h" 
#include "show_time_records.h"//this file

using namespace std;

//function to show time records
void show_time_records(int maze_num) {

    const bool winner_file = true;

    string winner_file_name; //where the file name will be loaded

    //function to prepare maze name
    winner_file_name = maze_name(maze_num, winner_file);

    //open the file
    ifstream winnerfile;
    winnerfile.open(winner_file_name);

    string line;

    //if opening the file fails it gives an error
    if (!winnerfile.is_open()) {
        cout << "Could not open the winner file for the maze #" << maze_num << endl;
    }
    //if opening the files works it prints its content
    else {
        while (getline(winnerfile, line)) {
            cout << line << endl;
        }
    } winnerfile.close();

}