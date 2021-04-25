//T09_G12

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdio.h>

using namespace std;

//Struct to pass important game info
struct game_info{
    vector<vector<char>> maze_map;
    vector<int> player_pos;//vector with player position
    vector<vector<int>> robot_info; //vector with the different robots and their info
    int robots_dead;
};

//Function for the main menu - returns the option chosen by the user
int game_start() {

    //options choice
    const char rules = '0';
    const char play_game = '1';
    const char exit = '2';
    
    char option;//variable to store the user input

    string title_line;//for title screen

    //print title screen and menu
    ifstream title_game;
    title_game.open("TITLE.TXT");
    if(!title_game.is_open()){
        cout << "Welcome to Robot Maze" << endl;
        cout << "please choose an option: " << endl;
        cout << "1- Rules" << endl << "2- Play" << endl << "0- Exit" << endl;
    }
    else{
        while (getline(title_game, title_line)) {
            cout << title_line << endl;
        } 
        title_game.close();
    }

    //asks repeatedly for an option only accepting 1, 2 or 0 (rules, play, quit)
    do {
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if (option != rules & option != play_game & option != exit) {
            cout << "Input not valid, please try again." << endl;
        }
    } while (option != rules & option != play_game & option != exit);
    return option;
}

//Test if the maze exists in the files
bool teste(int maze_num) {

    const int maze_num_check = 10; //used to check if maze has a number lower than 10
    
    bool flag = false;

    string maze;

    //select maze txt file
    if (maze_num < maze_num_check) {
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

//Load maze in the console
void maze(int maze_num,game_info &gameplay) {

    const int maze_num_check = 10; //used to check if maze has a number lower than 10
    const int invalid_maze_num = 0;
    const char alive_player = 'H';
    const char alive_robot = 'R';

    string maze_select;

    //select maze txt file
    if (maze_num < maze_num_check) {
        maze_select = "MAZE_0" + to_string(maze_num) + ".TXT";
    }
    else {
        maze_select = "MAZE_" + to_string(maze_num) + ".TXT";
    }

    ifstream mazefile;
    mazefile.open(maze_select);

    string line; //lines of the file
    int pos_x, pos_y; //vars to get map size
    int count_robot = 0;//count the robots in the game

    if(!mazefile.is_open()){
        cout << "ERROR!" << endl;
    }
    else{

        //get the size of the maze
        mazefile >> pos_y;
        mazefile.ignore ( std::numeric_limits<std::streamsize>::max(), 'x' );
        mazefile >> pos_x;

        //count the number of robots
        while (getline(mazefile, line)) {
            int line_len = line.length();
            for(int i=1; i < line_len; i++){
                if(line[i] == alive_robot){
                    count_robot++;
                }
            }
        } mazefile.close();

    }

    //resizing the vector in gameplay to appropriate size
    gameplay.maze_map.resize(pos_y,vector<char>(pos_x));
    gameplay.player_pos.resize(2);
    gameplay.robot_info.resize(count_robot,vector<int>(3));

    int map_line = 0; //counting the lines
    int robot_index = 0; //help indexing the robot_info

    //getting the map into a vector
    mazefile.open(maze_select);
     if(!mazefile.is_open()){
        cout << "ERROR!" << endl;
    }
    else{
        mazefile.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
        while(getline(mazefile,line)){
            for(int i=0; i < pos_x; i++){
                gameplay.maze_map[map_line][i] = line[i];
            }

            map_line++;
        }
        mazefile.close();
    }

    //finding player and robot positions
    for(int i=0;i<pos_y;i++){
        for(int j=0;j<pos_x;j++){
            cout << gameplay.maze_map[i][j];

            //find player position in the map
            if(gameplay.maze_map[i][j] == alive_player){
                gameplay.player_pos[0] = i;
                gameplay.player_pos[1] = j;
            }
            //find robots positions in the map
            else if(gameplay.maze_map[i][j] == alive_robot){
                gameplay.robot_info[robot_index][0] = 1; //robot condition, 1 means the robot is alive
                gameplay.robot_info[robot_index][1] = i; //robot line position
                gameplay.robot_info[robot_index][2] = j; //robot column position

                robot_index++;
            }
        }
        cout << endl;
    }

    //Return to main menu
    if (maze_num == invalid_maze_num) {
        game_start();
    }
}

//Prints maze map when called
void print_maze(game_info &gameplay){

    for(int i=0;i<gameplay.maze_map.size();i++){
        for(int j=0;j<gameplay.maze_map[i].size();j++){
            cout << gameplay.maze_map[i][j];           
        }
        cout << endl;
    }
}

//Player movement
void player_move(game_info &gameplay) {

    const int detect_s_move = 1;
    const int detect_invalid_move = 0;
    const int move_position_positive = 1;
    const int move_position_negative = -1;
    const char alive_player = 'H';
    const char dead_player = 'h';
    const char alive_robot = 'R';
    const char dead_robot = 'r';
    const char wall = '*';
    const char empty_map_space = ' ';

    char player_move; //variable to detect player movement
    bool movement_completed = false;

    int change_x = 0, change_y = 0; //to where we need to move relative where we are
    int s_move = 0; //verifies if it is an s input (choose not to move)
    int valid_move = 1; //if move is valid we do it and break from the loop

    cout << endl << "Where do you want to go?" << endl;
    while(!movement_completed){

        //get player input
        cin >> player_move;
        cin.ignore(255,'\n');

        //determine which char the player chose and validates it
        if(player_move == 'q' || player_move == 'Q'){
            change_y = move_position_negative;
            change_x = move_position_negative;
        }
        else if(player_move == 'w' || player_move == 'W'){
           change_y = move_position_negative;
        }
        else if(player_move == 'e' || player_move == 'E'){
            change_y = move_position_negative;
            change_x = move_position_positive;
        }
        else if(player_move == 'a' || player_move == 'A'){
        change_x = move_position_negative;
        }
        else if(player_move == 's' || player_move == 'S'){
            s_move = detect_s_move;
        }
        else if(player_move == 'd' || player_move == 'D'){
            change_x = move_position_positive;
        }
        else if(player_move == 'z' || player_move == 'Z'){
            change_y = move_position_positive;
            change_x = move_position_negative;
        }
        else if(player_move == 'x' || player_move == 'X'){
            change_y = move_position_positive;
        }
        else if(player_move == 'c' || player_move == 'C'){
            change_y = move_position_positive;
            change_x = move_position_positive;
        }
        else{
            valid_move = detect_invalid_move;//flag for invalid movement
        }

        //if valid checks where it is going and its consequences
        if(valid_move == 1){
            //player tries to move into dead robot
            if(gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] == dead_robot){
                valid_move = 0;
            }
            //player hits wall or robt
            else if(gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] == wall || gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] == alive_robot){
                gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] = dead_player;
                if(s_move != detect_s_move){
                gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] = empty_map_space;
                }
                gameplay.player_pos[0] = gameplay.player_pos[0]+change_y;
                gameplay.player_pos[1] = gameplay.player_pos[1]+change_x;
                movement_completed = true;
            }
            //player moves normally
            else{
                gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] = alive_player;
                if(s_move != detect_s_move){
                    gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] = empty_map_space;
                }
                gameplay.player_pos[0] = gameplay.player_pos[0]+change_y;
                gameplay.player_pos[1] = gameplay.player_pos[1]+change_x;
                movement_completed = true;
            }
        }

        //if not valid tells the user and restart the loop
        if(valid_move == detect_invalid_move){
            cout << "Movement invalid, please choose another one" << endl;
        }
    }
}

//Robots movement
void robot_move(int i,game_info &gameplay){

    //defining constants
    const int robot_move_place = 0; //used to determine the robts vertical and horizontal movement
    const char alive_player = 'H';
    const char dead_player = 'h';
    const char alive_robot = 'R';
    const char dead_robot = 'r';
    const char wall = '*';
    const char empty_map_space = ' ';

    //variables to determine where the robot will move
    int change_x = 0;
    int change_y = 0;

    //determines if the robot will move up or down (will chase the player)
    if(gameplay.robot_info[i][1] - gameplay.player_pos[0] > robot_move_place){
        change_y = -1;
    }
    else if(gameplay.robot_info[i][1] - gameplay.player_pos[0] < robot_move_place){
        change_y = 1;
    }

    //determines if the robot will move left or right (will chase the player)
    if(gameplay.robot_info[i][2] - gameplay.player_pos[1] > robot_move_place){
        change_x = -1;
    }
    else if(gameplay.robot_info[i][2] - gameplay.player_pos[1] < robot_move_place){
        change_x = 1;
    }

    //MAKE THE ROBOTS MOVE
    //robot catches player and player
    if(gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] == alive_player){
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = dead_player;
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = empty_map_space;
    }
    //robot dies in fence
    else if(gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] == wall){
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = empty_map_space;
        gameplay.robot_info[i][1] = gameplay.robot_info[i][1]+change_y;
        gameplay.robot_info[i][2] = gameplay.robot_info[i][2]+change_x;
    }
    //robot colides with another and both get stuck
    else if(gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] == alive_robot){
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = empty_map_space;
        gameplay.robot_info[i][1] = gameplay.robot_info[i][1]+change_y;
        gameplay.robot_info[i][2] = gameplay.robot_info[i][2]+change_x;
    }
    //got colides with stuck robot and get stuck
    else if(gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] == dead_robot){
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = empty_map_space;
        gameplay.robot_info[i][1] = gameplay.robot_info[i][1]+change_y;
        gameplay.robot_info[i][2] = gameplay.robot_info[i][2]+change_x;
    }
    //robots move normally
    else{
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = alive_robot;
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = empty_map_space;
        gameplay.robot_info[i][1] = gameplay.robot_info[i][1]+change_y;
        gameplay.robot_info[i][2] = gameplay.robot_info[i][2]+change_x;
    }

}

//Run the functions while playing the game
void play(int &maze_num,game_info &gameplay) {

    //defining constants
    const char dead_player = 'h';
    const char dead_robot = 'r';
    const int robot_cond_alive = 1;

    gameplay.robots_dead = 0;//variable to see if all robots are dead during game

    bool game_run = true;
    int r_dead;//used to count the number of dead robots

    maze(maze_num, gameplay); //load the map

    //game loop
    while(game_run){

        player_move(gameplay); //calls the player movement function
        //print_maze(gameplay); //prints the maze map after the movement

        //checks if the player lost after the movement
        if(gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] == dead_player){
            cout << "You lost!" << endl;
            break; //break the "game loop" without waiting for robot movement
        }

        //movement of the robots
        for(int i=0;i < gameplay.robot_info.size();i++){
            if(gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] == dead_robot && gameplay.robot_info[i][0] == robot_cond_alive){
                gameplay.robot_info[i][0] = 0;
                gameplay.robots_dead++;
            }
            else if(gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] == dead_robot){
                gameplay.robot_info[i][0] = 0;
            }
            else{
                robot_move(i, gameplay);   //robots movement
            }

            //checks if the player died after the robot movement and exit their movements
            if(gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] == dead_player){
                break; //break the for loop (player movement and robots movement)
            }

            //tests if all robots are dead (player victory)
            if(gameplay.robots_dead == gameplay.robot_info.size()){
                break; //break the for loop
            }
            
        }

        print_maze(gameplay); //prints the maze map after the robot movement

        //after all the robots move checks if the player died
        if(gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] == dead_player){
            cout << "You lost!" << endl;
            game_run = false; //break the game loop
        }

        //checks if the player won
        r_dead =0; //resets the counting for how many robots are dead
        for(int i=0;i < gameplay.robot_info.size();i++){
            if(gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] == dead_robot){
                r_dead++;
            }
        }
        if (r_dead == gameplay.robot_info.size()){
            cout << "You won!" << endl;
            game_run = false;
        }
    }
}

//Player won - keep the time of his game
//create a function for when the player win!

//Main
int main() {

    //opttions choice
    const char rules = '1';
    const char play_game = '2';
    const char exit = '0';

    // variables user input and chosen maze
    int option = game_start();
    int maze_num;

    //variables to map the maze,player and robots
    char maze_map;

    //variable for game mapping
    game_info gameplay;

    //ACTIONS REGARDING THE OPTION CHOSE BY THE USER

    //rules
    if (option == rules) {
        cout << "The rules are: "; //to be written
    }
    //Play the game
    else if (option == play_game) {

        cout << "Here we go!" << endl << "Choose the maze: ";
        //Choose an available maze
        do {
            std::cin >> maze_num;
        } while (maze_num != 01 & teste(maze_num)); //test if the maze exists

        if (maze_num != 0) {
            play(maze_num, gameplay);
        }
        // Exit
        else {
            cout << "Bye!";
        }
    }
    //Quit
    else if (option == exit){
        return 0;
    }
    
}
