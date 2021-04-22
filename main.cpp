//T09_G12

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Function for the main menu returns the option chosen by the user
int game_start() {
    // variable to store the user input
    char option;

    //shows the menu
    cout << "1) Rules;" << endl << "2) Play;" << endl << "0) Exit" << endl;

    //asks repeatedly for an option only accepting 1, 2 or 0
    do {
        cin >> option;
        if (option != '0' & option != '1' & option != '2') {
            cout << "Input not valid, please try again." << endl;
        }
    } while (option != '0' & option != '1' & option != '2');
    return option;
}

//Test if the maze exists in the files
bool teste(int maze_num) {
    
    bool flag = false;

    string maze;

    //select maze txt file
    if (maze_num < 10) {
        maze = "Maze_0" + to_string(maze_num) + ".TXT";
    }
    else {
        maze = "Maze_" + to_string(maze_num) + ".TXT";
    }

    ifstream mazefile;
    mazefile.open(maze);
    if (mazefile.fail()) {
        flag = true;
    }

    return flag;
}

//load maze in the console
void maze(int maze_num, int &player_line, int &player_col) {

    string player;
    int count = -1;

    string maze;

    //select maze txt file
    if (maze_num < 10) {
        maze = "Maze_0" + to_string(maze_num) + ".TXT";
    }
    else {
        maze = "Maze_" + to_string(maze_num) + ".TXT";
    }

    ifstream mazefile;
    mazefile.open(maze);

    //linhas ficheiro
    string line;
    int l, c;

    while (getline(mazefile, line)) {
        cout << line << endl;
        if (count == 0) {
            l = line.length();
        }

        count++;

    }
    mazefile.close();

    mazefile.open(maze);

    c = count;
    char ** pos = new char*[l];

    for (int i = 1; i < l; i++) {
        pos[i] = new char[c];
    }

    //estava a tentar criar uma matriz para guardar as posições dos objetos mas ainda não consegui 
    while (getline(mazefile,line)) { 
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                pos[i][j] = line[i];
                if (line[i] == 'H') {
                    player_line = i;
                    player_col = j;
                }
            }
        }
    }

    //close maze file
    mazefile.close();

    //Return to main menu
    if (maze_num == 0) {
        game_start();
    }
}

//player movement
void moves() {
    char player_move;

    cout << endl << "Where do you want to go?" << endl;
    cin >> player_move;

}

void play(int maze_num) {

    string player_position;
    int player_line, player_col;

    maze(maze_num, player_line, player_col);

    cout << "Player: " << endl << "line: " << player_line << endl << "column: " << player_col;

    moves();
}

//main

int main() {

    // variables user input and chosen maze
    int option = game_start();
    int maze_num;

    //actions regarding the option chose by the user

    //rules
    if (option == '1') {
        cout << "The rules are: ";
    }
    //Play the game
    else if (option == '2') {

        cout << "Here we go!" << endl << "Choose the maze: ";
        //Choose an available maze
        do {
            cin >> maze_num;
        } while (maze_num != 01 & teste(maze_num)); //test if the maze exists

        if (maze_num != 0) {
            play(maze_num);
        }
        // Exit
        else {
            cout << "Bye!";
        }
    }
    //Quit
    else if (option == '0'){
        return 0;
    }

}
