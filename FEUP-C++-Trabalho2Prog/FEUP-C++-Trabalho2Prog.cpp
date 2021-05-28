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

char chooseMove() {

    char option;
    bool flag = true;
    do {

        cin >> option;
        if (cin.fail()) {
            cout << "Not a valid input. Please try again!" << endl;
            cin.clear();
            cin.ignore(CHAR_MAX, '\n');
        }

    } while (option != 'q' && option != 'w' && option != 'e' && option != 'a' && option != 's' && option != 'd' && option != 'z' && option != 'x' && option != 'c' && option != 'Q' && option != 'W' && option != 'E' && option != 'A' && option != 'S' && option != 'D' && option != 'Z' && option != 'X' && option != 'C');

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

void moveRobot(Game g, char option) {

    Player player_1 = g.getPlayer();
    if (g.robotMovement(player_1)) { exit(0); }

    
    
}

void movePlayer(Game g) {
    
    char option; 

    cout << "Where do you want to go?" << endl;
    option = isupper(chooseMove());
    moveRobot(g, option);
    Player p = g.getPlayer();
    Position pos = p.getPosition();
    int x = pos.getX();
    int y = pos.getY();
    Maze maze = g.getMaze();
    do {
        switch (option)
        {
        case 'Q':
            if (!g.checkRobot((x - 1), (y - 1)) || !maze.checkPost((x - 1), (y - 1))) { p.setPosition((x - 1), (y - 1)); }
            else { p.setState(false); }
            break;
        case 'W':
            if (!g.checkRobot((x - 1), y) || !maze.checkPost((x - 1), y)) { p.setPosition((x - 1), y); }
            else { p.setState(false); }
            break;
        case 'E':
            if (!g.checkRobot((x - 1), (y + 1)) || !maze.checkPost((x - 1), (y + 1))) { p.setPosition((x - 1), (y + 1)); }
            else { p.setState(false); }
            break;
        case 'A':
            if (!g.checkRobot(x, (y - 1)) || !maze.checkPost(x, (y - 1))) { p.setPosition(x, (y - 1)); }
            else { p.setState(false); }
            break;
        case 'S':
            if (!g.checkRobot(x, y) || !maze.checkPost(x, y)) { p.setPosition(x, y); }
            else { p.setState(false); }
            break;
        case 'D':
            if (!g.checkRobot(x, (y + 1)) || !maze.checkPost(x, (y + 1))) { p.setPosition(x, (y + 1)); }
            else { p.setState(false); }
            break;
        case 'Z':
            if (!g.checkRobot((x + 1), (y - 1)) || !maze.checkPost((x + 1), (y - 1))) { p.setPosition((x + 1), (y - 1)); }
            else { p.setState(false); }
            break;
        case 'X':
            if (!g.checkRobot((x + 1), y) || !maze.checkPost((x + 1), y)) { p.setPosition((x + 1), y); }
            else { p.setState(false); }
            break;
        case 'C':
            if (!g.checkRobot((x + 1), (y + 1)) || !maze.checkPost((x + 1), (y + 1))) { p.setPosition((x + 1), (y + 1)); }
            else { p.setState(false); }
            break;
        default:
            abort(); //rever
            break;
        }
    } while (p.getState());

    if (!p.getState()) { cout << "LOSER!" << endl; }
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
            }

            mazeFile.close();

            Game g(maze_name);
            movePlayer(g);
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


