// FEUP-C++-Trabalho2Prog.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Post.h"
#include "Maze.h"
#include "Robot.h"
#include "Position.h"
#include "Player.h"
#include "Game.h"
#include "GameObject.h"

using namespace std;

int chooseOption() {

    int option;
    bool flag = true;
    do {

        cin >> option;
        if (cin.fail()) {
            cout << "Not a valid input. Please try again!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

    }while (option != 0 && option != 1 && option != 2 && option != 3);

    return option;
}

int gameIntro(){
    string line;

    ifstream titleFile("TITLE.TXT");

    while(getline (titleFile, line)) {
        cout << line << endl;
    }

    titleFile.close();

    return chooseOption();
}

int showRules() {

    string line;

    ifstream rulesFile("RULES.TXT");

    while (getline(rulesFile, line)) {
        cout << line << endl;
    }

    rulesFile.close();

    cout << "Do you want to play now? (y/n)" << endl;
    char option;
    bool flag = true;
    do {

        cin >> option;
        if (option != 'y' && option != 'Y' && option != 'n' && option != 'N') {
            cout << "Not a valid input. Please try again!" << endl;
        }

    } while (option != 'y' && option != 'Y' && option != 'n' && option != 'N');
    
    if (option == 'y' || option == 'Y') {
        return 0;
    }
    else {
        abort(); //rever 
    }
}

string chooseMaze() {
    
    int maze_number;
    cout << "Please choose a maze: " << endl;
    do {

        cin >> maze_number;
        if (cin.fail()) {
            cout << "Not a valid input. Please try again!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

    } while (maze_number < 0);

    if (maze_number < 10) {

        return "MAZE_0" + to_string(maze_number) + ".TXT";
    }
    else {
        return "MAZE_" + to_string(maze_number) + ".TXT";
    }

}

bool fileCheck(string file_name) {

    ifstream fileName(file_name);
    return fileName.good();

}

void playGame() {

    string maze_name;

    do {
        maze_name = chooseMaze();

        if (fileCheck(maze_name)) {

            string line;

            ifstream mazeFile(maze_name);

            while (getline(mazeFile, line)) {
                cout << line << endl;
                Game g(maze_name);
            }

            mazeFile.close();
        }
        else {
            cout << "Not a valid maze. Please try again!" << endl;
        }
    } while (!fileCheck(maze_name));
}

void showTimeRecords(){}

int main()
{
    int option;

    do {
        option = gameIntro();
        switch (option)
        {
        case 1:
            showRules();
            break;
        case 2:
            playGame();
            break;
        case 3:
            showTimeRecords();
            break;
        default:
            abort(); //rever
            break;
        }
    } while (option != 2);
}


