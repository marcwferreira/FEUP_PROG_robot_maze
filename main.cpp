//T09_G12

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdio.h>
#include <chrono>

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
    const string rules = "1";
    const string play_game = "2";
    const string time_records = "3";
    const string exit = "0";
    
    string option;//variable to store the user input
    int option_selected;//convert string into int

    string title_line;//for title screen

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
        else if(option != rules & option != play_game & option != exit & option != time_records) {
            cout << "Input not valid, please try again." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    } while (option != rules & option != play_game & option != exit & option != time_records);

    //convert option into int
    option_selected = stoi(option);

    return option_selected;
}

//makes the maze file name
string maze_name(int maze_num, bool winner_file){

    const int maze_num_check = 10; //used to check if maze has a number lower than 10

    string maze;

    //select maze txt file
    if(winner_file == true){
        //select maze txt file for the winners
        if (maze_num < maze_num_check) {
            maze = "MAZE_0" + to_string(maze_num) + "_WINNERS.TXT";
        }
        else {
            maze = "MAZE_" + to_string(maze_num) + "_WINNERS.TXT";
        }
    }
    else{
        if (maze_num < maze_num_check) {
            maze = "MAZE_0" + to_string(maze_num) + ".TXT";
        }
        else {
            maze = "MAZE_" + to_string(maze_num) + ".TXT";
        }
    }

    return maze;
}

//Test if the maze exists in the files
bool teste(int maze_num, bool winner_teste) {

    const bool game_file = false;//indicates that this will name a maze file and not a winner file
    const bool winner_file = true;
    
    bool flag_no_map = false;

    string maze;

    if(winner_teste == false){
        maze = maze_name(maze_num, game_file);
    }
    else if(winner_teste == true){
        maze = maze_name(maze_num, winner_file);
    }

    ifstream mazefile;
    mazefile.open(maze);
    if (mazefile.fail()) {
        flag_no_map = true;
    }

    return flag_no_map;
}

//Load maze in the console
void maze(int maze_num,game_info &gameplay) {

    const bool game_file = false;//indicates that this is a maze file and not a winner file
    const int invalid_maze_num = 0;
    const char alive_player = 'H';
    const char alive_robot = 'R';

    string maze_select;

    //select maze txt file
    maze_select = maze_name(maze_num, game_file);

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

    //clearing vectors and preparing then to be resized (in the case player wants to replay)
    gameplay.maze_map.clear();
    gameplay.maze_map.shrink_to_fit();
    gameplay.player_pos.clear();
    gameplay.player_pos.shrink_to_fit();
    gameplay.robot_info.clear();
    gameplay.robot_info.shrink_to_fit();

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
                gameplay.robot_info[robot_index][0] = i; //robot line position
                gameplay.robot_info[robot_index][1] = j; //robot column position
                gameplay.robot_info[robot_index][2] = 1; //robot condition, 1 means the robot is alive

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
            printf("%c",gameplay.maze_map[i][j]);
        }
        printf("\n");
    }
}

//Player movement
void player_move(game_info &gameplay) {

    const bool valid_move_reset = true;
    const int detect_invalid_move = false;
    const int detect_s_move = 1;
    const int move_position_positive = 1;
    const int move_position_negative = -1;
    const int line = 0; //player line
    const int column = 1; //player column
    const char alive_player = 'H';
    const char dead_player = 'h';
    const char alive_robot = 'R';
    const char dead_robot = 'r';
    const char wall = '*';
    const char empty_map_space = ' ';

    string player_move; //variable to detect player movement
    bool movement_completed = false;

    int change_x = 0, change_y = 0; //to where we need to move relative where we are
    int s_move = 0; //verifies if it is an s input (choose not to move)
    bool valid_move = valid_move_reset; //if move is valid we do it and break from the loop

    cout << endl << "Where do you want to go?" << endl;
    while(!movement_completed){

        //reset move validation and move positions
        valid_move = valid_move_reset;//flag for invalid movement
        change_x = 0; //means no movement in x asix
        change_y = 0; //means no movment in y axis

        //get player input
        cin >> player_move;
        cin.ignore(255,'\n');

        //end the program if user press control + z
        if(cin.eof()){
            std::exit(0);
        }

        //determine which char the player chose and validates it
        if(player_move == "q" || player_move == "Q"){
            change_y = move_position_negative;
            change_x = move_position_negative;
        }
        else if(player_move == "w" || player_move == "W"){
           change_y = move_position_negative;
        }
        else if(player_move == "e" || player_move == "E"){
            change_y = move_position_negative;
            change_x = move_position_positive;
        }
        else if(player_move == "a" || player_move == "A"){
        change_x = move_position_negative;
        }
        else if(player_move == "s" || player_move == "S"){
            s_move = detect_s_move;
        }
        else if(player_move == "d" || player_move == "D"){
            change_x = move_position_positive;
        }
        else if(player_move == "z" || player_move == "Z"){
            change_y = move_position_positive;
            change_x = move_position_negative;
        }
        else if(player_move == "x" || player_move == "X"){
            change_y = move_position_positive;
        }
        else if(player_move == "c" || player_move == "C"){
            change_y = move_position_positive;
            change_x = move_position_positive;
        }
        else{
            valid_move = detect_invalid_move;//flag for invalid movement
        }

        //if valid checks where it is going and its consequences
        if(valid_move == valid_move_reset){
            //player tries to move into dead robot
            if(gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] == dead_robot){
                valid_move = detect_invalid_move;
            }
            //player hits wall or robt
            else if(gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] == wall || gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] == alive_robot){
                gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] = dead_player;
                if(s_move != detect_s_move){
                gameplay.maze_map[gameplay.player_pos[line]][gameplay.player_pos[column]] = empty_map_space;
                }
                gameplay.player_pos[line] = gameplay.player_pos[line]+change_y;
                gameplay.player_pos[column] = gameplay.player_pos[column]+change_x;
                movement_completed = true;
            }
            //player moves normally
            else{
                gameplay.maze_map[gameplay.player_pos[line]+change_y][gameplay.player_pos[column]+change_x] = alive_player;
                if(s_move != detect_s_move){
                    gameplay.maze_map[gameplay.player_pos[line]][gameplay.player_pos[column]] = empty_map_space;
                }
                gameplay.player_pos[line] = gameplay.player_pos[line]+change_y;
                gameplay.player_pos[column] = gameplay.player_pos[column]+change_x;
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
void robot_move(int robot_index,game_info &gameplay){

    //defining constants
    const int robot_move_place = 0; //used to determine the robts vertical and horizontal movement
    const int line = 0; //robot line
    const int column = 1; //robot column
    const int condition = 2; //robot condition (alive or dead)
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
    if(gameplay.robot_info[robot_index][line] - gameplay.player_pos[line] > robot_move_place){
        change_y = -1;
    }
    else if(gameplay.robot_info[robot_index][line] - gameplay.player_pos[line] < robot_move_place){
        change_y = 1;
    }

    //determines if the robot will move left or right (will chase the player)
    if(gameplay.robot_info[robot_index][column] - gameplay.player_pos[column] > robot_move_place){
        change_x = -1;
    }
    else if(gameplay.robot_info[robot_index][column] - gameplay.player_pos[column] < robot_move_place){
        change_x = 1;
    }

    //MAKE THE ROBOTS MOVE
    //robot catches player and player
    if(gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] == alive_player){
        gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] = dead_player;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
    }
    //robot dies in fence
    else if(gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] == wall){
        gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
        gameplay.robot_info[robot_index][line] = gameplay.robot_info[robot_index][line]+change_y;
        gameplay.robot_info[robot_index][column] = gameplay.robot_info[robot_index][column]+change_x;
    }
    //robot colides with another and both get stuck
    else if(gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] == alive_robot){
        gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
        gameplay.robot_info[robot_index][line] = gameplay.robot_info[robot_index][line]+change_y;
        gameplay.robot_info[robot_index][column] = gameplay.robot_info[robot_index][column]+change_x;
    }
    //got colides with stuck robot and get stuck
    else if(gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] == dead_robot){
        gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] = dead_robot;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
        gameplay.robot_info[robot_index][line] = gameplay.robot_info[robot_index][line]+change_y;
        gameplay.robot_info[robot_index][column] = gameplay.robot_info[robot_index][column]+change_x;
    }
    //robots move normally
    else{
        gameplay.maze_map[gameplay.robot_info[robot_index][line]+change_y][gameplay.robot_info[robot_index][column]+change_x] = alive_robot;
        gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] = empty_map_space;
        gameplay.robot_info[robot_index][line] = gameplay.robot_info[robot_index][line]+change_y;
        gameplay.robot_info[robot_index][column] = gameplay.robot_info[robot_index][column]+change_x;
    }

}

//Run the functions while playing the game
int play(int maze_num,game_info &gameplay) {

    //defining constants
    const char dead_player = 'h';
    const char dead_robot = 'r';
    const int robot_cond_alive = 1;
    const int robot_cond_dead = 0;
    const int line = 0; //player or robot line
    const int column = 1; // player or robot column
    const int condition = 2; // robot condition (alive or dead)

    gameplay.robots_dead = 0;//variable to see if all robots are dead during game

    bool game_run = true;
    bool player_won = false;
    int player_time = 0;//traks the time of the gameplay
    int r_dead;//used to count the number of dead robots

    maze(maze_num, gameplay); //load the map

    //timer for the game
    auto start = chrono::steady_clock::now();

    //game loop
    while(game_run){

        player_move(gameplay); //calls the player movement function
        //print_maze(gameplay); //prints the maze map after the movement

        //checks if the player lost after the movement
        if(gameplay.maze_map[gameplay.player_pos[line]][gameplay.player_pos[column]] == dead_player){
            print_maze(gameplay);
            cout << "You lost!" << endl;
            break; //break the "game loop" without waiting for robot movement
        }

        //movement of the robots
        for(int robot_index=0;robot_index < gameplay.robot_info.size();robot_index++){
            if(gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] == dead_robot && gameplay.robot_info[robot_index][condition] == robot_cond_alive){
                gameplay.robot_info[robot_index][condition] = robot_cond_dead;
                gameplay.robots_dead++;
            }
            else if(gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] == dead_robot){
                gameplay.robot_info[robot_index][condition] = robot_cond_dead;
            }
            else{
                robot_move(robot_index, gameplay);   //robots movement
            }
            
            //checks if the player died after the robot movement and exit their movements
            if(gameplay.maze_map[gameplay.player_pos[line]][gameplay.player_pos[column]] == dead_player){
                break; //break the for loop (player movement and robots movement)
            }

            
            //tests if all robots are dead (player victory)
            if(gameplay.robots_dead == gameplay.robot_info.size()){
                break; //break the for loop
            }
            
        }

        print_maze(gameplay); //prints the maze map after the robot movement

        //after all the robots move checks if the player died
        if(gameplay.maze_map[gameplay.player_pos[line]][gameplay.player_pos[column]] == dead_player){
            cout << "You lost!" << endl;
            game_run = false; //break the game loop
        }

        //checks if the player won
        r_dead =0; //resets the counting for how many robots are dead
        for(int robot_index=0;robot_index < gameplay.robot_info.size();robot_index++){
            if(gameplay.maze_map[gameplay.robot_info[robot_index][line]][gameplay.robot_info[robot_index][column]] == dead_robot){
                r_dead++;
            }
        }
        if (r_dead == gameplay.robot_info.size()){
            cout << "You won!" << endl;
            player_won = true;
            game_run = false;
        }
    }

    //stopping the timer
    auto end = chrono::steady_clock::now();

    //if player wins, the time is recorded
    if(player_won == true){
        player_time = chrono::duration_cast<chrono::seconds>(end - start).count();
    }

    return player_time;
}

//Player won - keep the time of his game
void player_win(int game_time, int maze_num){

    string save_time_choice;
    string save_yes = "1";
    string save_no = "0";

    //prints the player time
    cout << "Total time to complete maze: " << game_time << "s" << endl;
    //ask the player if he wishes to record his time
    cout << "Do you wish to save this time? " << endl;
    cout << "1- YES " << endl << "0- NO" << endl;
    do {
        std::cin >> save_time_choice;
        if(cin.eof()){
            std::exit(0);
        }
        else if(save_time_choice != save_yes & save_time_choice != save_no) {
            cout << "Input not valid, please choose 1- YES or 0- NO" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    } while (save_time_choice != save_yes & save_time_choice != save_no);

    //if player wishes to save his time
    if(save_time_choice == save_yes){

        string player_name;

        //ask player name also only allow for names up to 15 chars
        cout << "Please choose name to be recorded (name must have a mex of 15 character): ";
        do{
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, player_name);
            if(cin.eof()){
                std::exit(0);
            }
            else if(player_name.size() > 15){ //check if player tried to input more than 15 chars
                cout << "Name must have a max of 15 chars." << endl << "Please choose name to be recorded: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        }while(player_name.size() > 15);

        const bool winner_file = true;//indicates that the file should be named with _WINNERS at the end
        string maze_select = maze_name(maze_num, winner_file);//load the name of the file

        //opening the file
        ifstream mazefile;
        mazefile.open(maze_select);

        //create a winner file for the maze if it doesn't exist
        if(!mazefile.is_open()){
            ofstream mazefile(maze_select);
            mazefile << "Player        -   Time" << endl;
            mazefile << "----------------------" << endl;
            mazefile << player_name << " - " << game_time << "s";
        }
        //store and organize winners
        else{
            
            //store and organize winners
        
        }  mazefile.close();
    }

    //display a message showing time was saved
    cout << "Time saved, if you wish to see it go to time records!" << endl;

}

//function to show time records
void show_time_records(int maze_num){
    
    const bool winner_file = true;

    string winner_file_name; //where the file name will be loaded

    //function to prepare maze name
    winner_file_name = maze_name( maze_num, winner_file);

    //open the file
    ifstream winnerfile;
    winnerfile.open(winner_file_name);

    string line;


    //if opening the file fails it gives an error
    if(!winnerfile.is_open()){
        cout << "Could not open the winner file for the maze #" << maze_num << endl;
    }
    //if opening the files works it prints its content
    else{
        while(getline(winnerfile, line)){
            cout << line << endl;
        }
    } winnerfile.close();

}


//Main
int main() {

    //opttions choice
    const int rules = 1;
    const int play_game = 2;
    const int show_times = 3;
    const int exit = 0;
    const int time_fail = 0;
    const string no_playing = "0";
    const string yes_playing = "1";
    const bool winner_test_no = false;
    const bool winner_test_yes = true;

    //keep the loop for the player to play again
    string keep_playing;
    string rules_read;

    //variables to map the maze,player and robots
    int maze_num;
    bool maze_not_exist; 
    char maze_map;
    int gameplay_time;

    //variable for game mapping
    game_info gameplay;

    do{
         int option = game_start();//ask what the player wants to do

        //ACTIONS REGARDING THE OPTION CHOSE BY THE USER

        //rules
        if (option == rules) {
            //show the rules
            ifstream rules_file;
            rules_file.open("RULES.TXT");
            //alternative rules if file does not exist
            if(!rules_file.is_open()){
                cout << "Rules:" << endl; //write the rules
                cout << "Your objective is to survive inside the maze while robots chase you" << endl;
                cout << "You win the game if all robots are destroyed and you are still alive" << endl;
                cout << "'H' is your character" << endl;
                cout << "'h' is your character if you die (game over)" << endl;
                cout << "'*' is electric walls, if you hit then you die" << endl;
                cout << "'R' is an alive robot, they will chase you, you die if you touch them" << endl;
                cout << "'r' is a destroyed robot, you cannot walk over them" << endl;
                cout << "Robots are destroyed when they hit a fence or another robot (alive or destroyed)" << endl;
                cout << "The game works in rounds, you make a movement then the robots" << endl;
                cout << "Here is a list of possible movements in a round: " << endl;
                cout << "'q' or 'Q' : walk up-left (diagonal)" << endl;
                cout << "'w' or 'W' : walk up" << endl;
                cout << "'e' or 'E' : walk up-right (diagonal)" << endl;
                cout << "'a' or 'A' : walk left" << endl;
                cout << "'s' or 'S' : stay in place (no movement)" << endl;
                cout << "'d' or 'D' : walk right" << endl;
                cout << "'z' or 'Z' : walk down-left (diagonal)" << endl;
                cout << "'x' or 'X' - walk down" << endl;
                cout << "'c' or 'C' - walk down-right (diagonal)" << endl << endl;
                cout << "There is also time scores for people that win the game" << endl;
                cout << "Good Luck!" << endl << endl;
                cout << "Do you wish to got back to main menu or close the game?" << endl;
                cout << "1- MAIN MENU" << endl << "0- EXIT" << endl;
                cout << "please select you option:" ;
            }
            //rules if file exist
            else{
                while (getline(rules_file, rules_read)) {
                    cout << rules_read << endl;
                } 
                rules_file.close();
            }
            //ask player to go to main menu
            do{
                cin >> keep_playing;
                if(cin.eof()){
                    std::exit(0);
                }
                else if(keep_playing != no_playing && keep_playing != yes_playing){
                    cout << "Please select a valid option (1- MAIN MENU or 0- EXIT): ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
            }while(keep_playing != no_playing & keep_playing != yes_playing);
        }
        //Play the game
        else if (option == play_game) {

            cout << "Here we go!" << endl << "Choose the maze number: ";
            //Choose an available maze
            do{
                std::cin >> maze_num;
                maze_not_exist = teste(maze_num, winner_test_no); //test if maze exist
                if(cin.eof()){
                    std::exit(0);
                }
                else if(cin.fail() || maze_not_exist){
                    cout << "Not a valid inut or maze doens't exist" << endl;
                    cout << "please choose the maze number: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
            }while( cin.fail() || maze_not_exist);
                

            if (maze_num != 0) {
                gameplay_time = play(maze_num, gameplay);
                //call function to save player time if he won the maze
                if(gameplay_time != time_fail){
                    player_win(gameplay_time, maze_num);//calls the function to store players time
                }
                //ask the player if he wants to play again
                cout << "Do you want to play again?" << endl;
                cout << "1- YES" << endl << "0- NO" << endl;
                cout << "Please select an option: ";
                do{
                    cin >> keep_playing;
                    if(cin.eof()){
                        std::exit(0);
                    }
                    else if(keep_playing != no_playing && keep_playing != yes_playing){
                        cout << "Please select a valid option (1- YES or 0- NO): ";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                }while(keep_playing != no_playing && keep_playing != yes_playing);
            }
            //Exit
            else {
                cout << "Bye!";
            }
        }
        //see time records
        else if(option == show_times){

            //ask the player for the maze numbem to show time
            cout << "Choose the maze number you wish to see the records: ";
             do{
                std::cin >> maze_num;
                maze_not_exist = teste(maze_num, winner_test_yes); //test if maze exist
                if(cin.eof()){
                    std::exit(0);
                }
                else if(cin.fail() || maze_not_exist){
                    cout << "Not a valid inut or maze winners doens't exist" << endl;
                    cout << "please choose the maze number: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
            }while( cin.fail() || maze_not_exist);

            //calls the function to show the times
            show_time_records(maze_num);
            

            //ask the player if he wants to play the game (go to main menu)
                cout << "Do you want to play (go to main menu)?" << endl;
                cout << "1- YES" << endl << "0- NO" << endl;
                cout << "Please select an option: ";
                do{
                    cin >> keep_playing;
                    if(cin.eof()){
                        std::exit(0);
                    }
                    else if(keep_playing != no_playing && keep_playing != yes_playing){
                        cout << "Please select a valid option (1- YES or 0- NO): ";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                }while(keep_playing != no_playing && keep_playing != yes_playing);
        }
        //Exit
        else if (option == exit){
            return 0;
        }
    }while(keep_playing == yes_playing);
    
}