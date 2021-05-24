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
#include "gameStart.h" 
#include "show_time_records.h"
#include "player_win.h"//this file

using namespace std;

//Player won - keep the time of his game
void player_win(int game_time, int maze_num) {

    vector<string> reading_file; //help with reading file strings
    vector<string> writing_to_file; //help to put the name in the file if it doesnt exist
    vector<vector<string>> winner_reading;//used to sort winners if file exists

    stringstream player_name_to_store;
    stringstream player_time_to_store;
    string save_time_choice;

    bool file_already_existed = false;
    bool player_already_exist = false;

    //prints the player time
    cout << "Total time to complete maze: " << game_time << "s" << endl;
    //ask the player if he wishes to record his time
    cout << "Do you wish to save this time? " << endl;
    cout << "1- YES " << endl << "0- NO" << endl;
    do {
        std::cin >> save_time_choice;
        if (cin.eof()) {
            std::exit(0);
        }
        else if (save_time_choice != save_yes & save_time_choice != save_no) {
            cout << "Input not valid, please choose 1- YES or 0- NO" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (save_time_choice != save_yes & save_time_choice != save_no);

    //if player wishes to save his time
    if (save_time_choice == save_yes) {

        string player_name;

        //ask player name also only allow for names up to 15 chars
        cout << "Please choose name to be recorded (name must have a max of 15 character): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        do {
            getline(cin, player_name);
            if (cin.eof()) {
                std::exit(0);
            }
            else if (player_name.length() > max_name_size) { //check if player tried to input more than 15 chars
                cout << "Name must have a max of 15 chars." << endl << "Please choose name to be recorded: ";
            }
        } while (player_name.length() > max_name_size);

        const bool winner_file = true;//indicates that the file should be named with _WINNERS at the end
        string maze_select = maze_name(maze_num, winner_file);//load the name of the file

        //opening the file
        ifstream mazefile;
        mazefile.open(maze_select);

        string line;//used to read strings of the file

        //create a winner file for the maze if it doesn't exist
        if (!mazefile.is_open()) {
            ofstream mazefile(maze_select);
            mazefile << "Player         -  Time" << endl;
            mazefile << "----------------------" << endl;
            mazefile << left << setw(15) << player_name << "-" << right << setw(5) << game_time << "s";
            mazefile.close(); //closing the file created
        }
        //store and organize winners
        else {

            //STORE AND ORGANIZE WINNERS

            //ignore the first two lines of the file
            mazefile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mazefile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            //separating the names and times into a vector
            while (getline(mazefile, line)) {
                reading_file.clear(); //clear the previous string info
                reading_file.resize(2); //resize reading_file to store name and time
                reading_file[player_name_read] = line.substr(0, 14); //store name in reading_file
                reading_file[player_time_read] = line.substr(16, 8); //store time in reading_file (with some leniance)
                winner_reading.push_back(reading_file);//storing the pair name and time in winner_reading
            }

            //preparing data to go into vector
            player_name_to_store << left << setw(14) << player_name;
            player_time_to_store << right << setw(5) << game_time << "s";

            //if name alreay exist replace the time only if the time is lower
            for (int index = 0; index < winner_reading.size(); index++) {
                if (winner_reading[index][player_name_read] == player_name_to_store.str()) {
                    //only replaces the time if the time is lower
                    if (player_time_to_store.str() <= winner_reading[index][player_time_read]) {
                        winner_reading[index][player_time_read] = player_time_to_store.str();
                    }
                    else {
                        cout << "Previous time was better, time was not updated." << endl;
                    }
                    player_already_exist = true;
                }
            }
            //if name is not already in the file it adds it
            if (!player_already_exist) {
                //preaparing the vector to add to winnner_reading
                writing_to_file.push_back(player_name_to_store.str());
                writing_to_file.push_back(player_time_to_store.str());
                //adding the vector to wiiner_reading
                winner_reading.push_back(writing_to_file);
            }

            //sorting the order by the time - using function sort_winner_time
            sort(winner_reading.begin(), winner_reading.end(), sort_winner_time);

            //set true to file_already_existed
            file_already_existed = true;

            for (int i = 0; i < winner_reading.size(); i++) {
                cout << "test: " << winner_reading[i][player_name_read] << " e " << winner_reading[i][player_time_read] << endl;
            }

        }  mazefile.close();

        //writting the altered data to the winner file if file existed already
        if (file_already_existed) {
            ofstream mazefile;
            mazefile.open(maze_select);
            if (!mazefile.is_open()) {
                cout << "ERROR!" << endl;
            }
            else {
                mazefile << "Player         -  Time" << endl;
                mazefile << "----------------------" << endl;
                for (int index = 0; index < winner_reading.size(); index++) {
                    mazefile << left << setw(15) << winner_reading[index][player_name_read] << "-" << right << setw(6) << winner_reading[index][player_time_read] << endl;
                }

            } mazefile.close();
        }

        //display a message showing time was saved
        cout << "Time saved, if you wish to see it go to time records!" << endl;
    }
    else {
        cout << "Time not saved." << endl;
    }
}