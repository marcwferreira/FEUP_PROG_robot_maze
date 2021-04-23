//T09_G12

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

//struct to pass important info to functions
struct game_info{
    vector<vector<char>> maze_map;
    vector<int> player_pos;
    vector<vector<int>> robot_info;
};

//Function for the main menu returns the option chosen by the user
int game_start() {
    // variable to store the user input
    char option;

    //shows the menu
    cout << "1) Rules;" << endl << "2) Play;" << endl << "0) Exit" << endl;

    //asks repeatedly for an option only accepting 1, 2 or 0
    do {
        cin >> option;
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
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
void maze(int maze_num,game_info &gameplay) {

    int count = -1;
    int count_robot = 0;
    string maze_select;

    //select maze txt file
    if (maze_num < 10) {
        maze_select = "MAZE_0" + to_string(maze_num) + ".TXT";
    }
    else {
        maze_select = "MAZE_" + to_string(maze_num) + ".TXT";
    }

    ifstream mazefile;
    mazefile.open(maze_select);

    string line; //lines of the file
    int pos_x, pos_y; //initialize vars to get map size

    while (getline(mazefile, line)) {

        //count the size of columns in the map
        if (count == 0) {
            pos_x = line.length(); //pos_x is the number of columns
        }

        //count the number of robots in the map
        int line_len = line.length();
        for(int i=0; i < line_len; i++){
            if(line[i] == 'R'){
                count_robot++;
            }
        }
    
        count++;

    } mazefile.close();


    pos_y = count + 1; //pos_y is the number of lines

    //resizing the vector in gameplay to appropriate size
    gameplay.maze_map.resize(pos_y,vector<char>(pos_x));
    gameplay.player_pos.resize(2);
    gameplay.robot_info.resize(count_robot,vector<int>(3));

    int count2 = 0; //counting the lines
    int robot_index = 0; //help indexing the robot_info

     mazefile.open(maze_select);

    while(getline(mazefile,line)){
        for(int i=0; i < pos_x; i++){
            gameplay.maze_map[count2][i] = line[i];
        }
        count2++;
    }

    mazefile.close(); //close map file

    //finding player and robot positions
    for(int i=0;i<pos_y;i++){
        for(int j=0;j<pos_x;j++){
            cout << gameplay.maze_map[i][j];
            //find player position in the map or robots
            if(gameplay.maze_map[i][j] == 'H'){
                gameplay.player_pos[0] = i;
                gameplay.player_pos[1] = j;
            }
            else if(gameplay.maze_map[i][j] == 'R'){
                gameplay.robot_info[robot_index][0] = 1; //robot condition
                gameplay.robot_info[robot_index][1] = i; //robot line position
                gameplay.robot_info[robot_index][2] = j; //robot column position

                robot_index++;
            }
        }
        cout << endl;
    }

    //begin: TEST TO SEE IF POSITION WORKER
    cout << gameplay.player_pos[0] << ' ' << gameplay.player_pos[1] << endl;

    for(int i=0;i<count_robot;i++){
    cout << "robot " << i << endl;
    cout << gameplay.robot_info[i][0] << endl;
    cout<< gameplay.robot_info[i][1] << ' ' << gameplay.robot_info[i][2] << endl;
    }
    //end: END OF POSITION TEST

    //Return to main menu
    if (maze_num == 0) {
        game_start();
    }
}

//print maze map when called
void print_maze(game_info &gameplay){
    for(int i=0;i<gameplay.maze_map.size();i++){
        for(int j=0;j<gameplay.maze_map[i].size();j++){
            cout << gameplay.maze_map[i][j];           
        }
        cout << endl;
    }
}

//player movement
void player_move(game_info &gameplay) {

    char player_move; //variable to detect player movement

    int change_x = 0, change_y = 0; //to where we need to move relative where we are
    int s_move = 0; //verifies if it is an s input (choose not to move)
    int valid_move = 0; //if move is valid we do it and break from the loop

    cout << endl << "Where do you want to go?" << endl;
    while(true){

        //get player input
        cin >> player_move;
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        //determine which cahr the player chose and validates it
        if(player_move == 'q' || player_move == 'Q'){
            change_y = -1;
            change_x = -1;
            valid_move = 1;
        }
        else if(player_move == 'w' || player_move == 'W'){
           change_y = -1;
           valid_move = 1;
        }
        else if(player_move == 'e' || player_move == 'E'){
            change_y = -1;
            change_x = 1;
            valid_move = 1;
        }
        else if(player_move == 'a' || player_move == 'A'){
        change_x = -1;
        valid_move = 1;
        }
        else if(player_move == 's' || player_move == 'S'){
            s_move =1;
            valid_move = 1;
        }
        else if(player_move == 'd' || player_move == 'D'){
            change_x = 1;
            valid_move = 1;
        }
        else if(player_move == 'z' || player_move == 'Z'){
            change_y = 1;
            change_x = -1;
            valid_move =1;
        }
        else if(player_move == 'x' || player_move == 'X'){
            change_y = 1;
            valid_move =1;
        }
        else if(player_move == 'c' || player_move == 'C'){
            change_y = 1;
            change_x = 1;
            valid_move =1;
        }

        //if valid checks where it is going and its consequences
        if(valid_move == 1){
            if(gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] == 'r'){
                valid_move = 0;
            }
            else if(gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] == '*' || gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] == 'R'){
                gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] = 'h';
                if(s_move != 1){
                gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] = ' ';
                }
                gameplay.player_pos[0] = gameplay.player_pos[0]+change_y;
                gameplay.player_pos[1] = gameplay.player_pos[1]+change_x;
                break;
            }
            else{
                gameplay.maze_map[gameplay.player_pos[0]+change_y][gameplay.player_pos[1]+change_x] = 'H';
                if(s_move != 1){
                    gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] = ' ';
                }
                gameplay.player_pos[0] = gameplay.player_pos[0]+change_y;
                gameplay.player_pos[1] = gameplay.player_pos[1]+change_x;
                break;
            }
        }

        //if not valid tells the user and restart the loop
        if(valid_move == 0){
            cout << "Movement invalid, please choose another one" << endl;
        }
    }
}

//robots movement
void robot_move(int i,game_info &gameplay){

    //variables to determine where the robot will move
    int change_x = 0;
    int change_y = 0;

    //determines if the robot will move up or down (will chase the player)
    if(gameplay.robot_info[i][1] - gameplay.player_pos[0] > 0){
        change_y = -1;
    }
    else if(gameplay.robot_info[i][1] - gameplay.player_pos[0] < 0){
        change_y = 1;
    }

    //determines if the robot will move left or right (will chase the player)
    if(gameplay.robot_info[i][2] - gameplay.player_pos[1] > 0){
        change_x = -1;
    }
    else if(gameplay.robot_info[i][2] - gameplay.player_pos[1] < 0){
        change_x = 1;
    }

    //make the robot move
    if(gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] == 'H'){
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = 'h';
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = ' ';
    }
    else if(gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] == '*'){
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = 'r';
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = ' ';
        gameplay.robot_info[i][1] = gameplay.robot_info[i][1]+change_y;
        gameplay.robot_info[i][2] = gameplay.robot_info[i][2]+change_x;
        //gameplay.robot_info[i][0] = 0;
    }
    else if(gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] == 'R'){
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = 'r';
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = ' ';
        gameplay.robot_info[i][1] = gameplay.robot_info[i][1]+change_y;
        gameplay.robot_info[i][2] = gameplay.robot_info[i][2]+change_x;
        //gameplay.robot_info[i][0] = 0;
    }
    else if(gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] == 'r'){
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = 'r';
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = ' ';
        gameplay.robot_info[i][1] = gameplay.robot_info[i][1]+change_y;
        gameplay.robot_info[i][2] = gameplay.robot_info[i][2]+change_x;
        //gameplay.robot_info[i][0] = 0;
    }
    else{
        gameplay.maze_map[gameplay.robot_info[i][1]+change_y][gameplay.robot_info[i][2]+change_x] = 'R';
        gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] = ' ';
        gameplay.robot_info[i][1] = gameplay.robot_info[i][1]+change_y;
        gameplay.robot_info[i][2] = gameplay.robot_info[i][2]+change_x;
    }

}

//run the functions while playing the game
void play(int &maze_num,game_info &gameplay) {

    int a;// REMOVE

    maze(maze_num, gameplay); //load the map

    //this will be in a loop
    while(true){
        player_move(gameplay); //calls the player movement function
        print_maze(gameplay); //prints the maze map after the movement

        //checks if the player lost after the movement
        if(gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] == 'h'){
            cout << "You lost!" << endl;
            break; //break the "game loop" (player movement and robots movement)
        }

        //movement of the robots
        for(int i=0;i < gameplay.robot_info.size();i++){
            cout << "this is robot:" << i << endl;
            cout << "Robot position: " << gameplay.robot_info[i][1] << ' ' << gameplay.robot_info[i][2] << endl; //REMOVE
            if(gameplay.maze_map[gameplay.robot_info[i][1]][gameplay.robot_info[i][2]] == 'r'){
                gameplay.robot_info[i][0] = 0;
            }
            else if(gameplay.robot_info[1][0] == 1){ //verifies f the robot is still alive
                robot_move(i, gameplay);   //not implemented - robots movement
                print_maze(gameplay); //prints the maze map after the robot movement
                cout << "Robot position: " << gameplay.robot_info[i][1] << ' ' << gameplay.robot_info[i][2] << endl; //REMOVE
            }

            //checks if the player died after the robot movement and exit their movements
            if(gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] == 'h'){
                break; //break the for loop (player movement and robots movement)
            }
            
        }

        //after all the robots move checks if the player died
        if(gameplay.maze_map[gameplay.player_pos[0]][gameplay.player_pos[1]] == 'h'){
            cout << "You lost!" << endl;
            break; //break the "game loop" (player movement and robots movement)
        }    
    }

    cin >> a;// REMOVE

}

//main
int main() {

    // variables user input and chosen maze
    int option = game_start();
    int maze_num;

    //variables to map the maze,player and robots
    char maze_map;

    //variable for game mapping
    game_info gameplay;

    //ACTIONS REGARDING THE OPTION CHOSE BY THE USER

    //rules
    if (option == '1') {
        cout << "The rules are: "; //to be written
    }
    //Play the game
    else if (option == '2') {

        cout << "Here we go!" << endl << "Choose the maze: ";
        //Choose an available maze
        do {
            cin >> maze_num;
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
    else if (option == '0'){
        return 0;
    }
    
}
