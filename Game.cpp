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

//our files
#include "Game.h"
#include "Maze.h"
#include "Player.h"
#include "Robot.h"
#include "Post.h"
#include "Gate.h"
#include "Move_pos.h"

//constructor
Game::Game(const std::string & filename){

    gameWin = false; //only altered if player wins the game
    
    std::ifstream mazefile;
    mazefile.open(filename);//open maze file

    std::string line;

    if(!mazefile.is_open()){
        std::cout << "ERROR!" << std::endl;
    }
    else{

        int robot_counter = 0; //count the number of robots added (also pass the id)

        //get maze variables
        int pos_x, pos_y;
        mazefile >> pos_x;
        mazefile.ignore ( std::numeric_limits<std::streamsize>::max(), 'x' );
        mazefile >> pos_y;

        //set maze variables
        maze.setnumRows(pos_x);
        maze.setnumCols(pos_y);

        int line_counter = -1;//point to the line of the maze we are reading (-1 becaue of the first line in the file that is the size of map)

        //read the lines of the fize to extract information
        while (getline(mazefile, line)) {
            for (int i = 0; i!=line.length(); i++) {

                //read the robots in the map
                if (line[i] == alive_robot) {
                    robot_counter++;
                    Robot robot_store(robot_counter, line_counter, i);
                    robots.push_back(robot_store);
                }

                //read the player in the map
                else if (line[i] == alive_player) {
                    player.setRow(line_counter);
                    player.setCol(i);
                }

                //read the electric posts in the map
                else if (line[i] == electric_post){
                    Post post_store(line_counter, i, electric_post);
                    posts.push_back(post_store);
                }

                //read the non electric posts in map
                else if (line[i] == normal_post){
                    Post post_store(line_counter, i, normal_post);
                    posts.push_back(post_store);
                }

                //read doors in map
                else if (line[i] == door){
                    Gate gate_store(line_counter, i);
                    gates.push_back(gate_store);
                }
            }
            line_counter++;//jump to next line
        }
    }
    mazefile.close();
}

//getters
Maze Game::getMaze() const { return maze; }
Player Game::getPlayer() const { return player; }
std::vector<Robot> Game::getRobots() const { return robots; }
std::vector<Post> Game::getPosts() const { return posts; }
std::vector<Gate> Game::getGates() const { return gates; }
bool Game::getGameWin() const { return gameWin; }

//setter
void Game::setGameWin(bool gameCond) {
    gameWin = gameCond;
}

//function to detect player win or lose
bool Game::ask_game_ended() {
    //see if player won game
    if (gameWin) {
        return game_ended;
    }
    //see if player lost game
    else if (!player.isAlive()) {
        return game_ended;
    }
    //if neither continue game
    else {
        return game_running;
    }
}


//public function to play the game;
bool Game::play() {

    setGameWin(game_start_cond);//ensures the gameWin condiiton is set to false

    bool game_running = true;//initiates varviable to loop the game

    while (game_running) {

        //print the game
        showGameDisplay();

        //player_movement
        player_movement();
        //detect if game ended (if player has won or lost)
        game_running = ask_game_ended();
        
        //robots_movements
        for (size_t i = 0; i < robots.size(); i++) {
            robot_movement(i);
            //detect if game ended (if player has won or lost)
            game_running = ask_game_ended();
            if (!game_running) {
                break;
            }
        }
        //detect player_lost
    }

    showGameDisplay(); //show display after the game ended

    return gameWin;
}

//function to print the map (private)
void Game::showGameDisplay() {

    Maze maze_s = getMaze();
    Player player_s = getPlayer();
    std::vector<Robot> robots_s = getRobots();
    std::vector<Post> posts_s = getPosts();
    std::vector<Gate> gates_s = getGates();

    bool printed = false; //see if the char has already been printed
    int size_line = maze_s.getnumRows(); //number of rows in map
    int size_col = maze_s.getnumCols(); //number of columns in map
    int player_row, player_col; //detect player place in map
    int robot_row, robot_col; //detect place of a robot in map
    int post_row, post_col; //detect place of post in map
    int gate_row, gate_col; //detect place of door in map

    //run the map coordinates, see what is in the position and prints it
    for (int row_number=0;row_number<size_line;row_number++){
        for (int column_number=0;column_number<size_col;column_number++){

            printed = false; //set printed char to false

            //print player on the map
            player_row = player_s.getRow();
            player_col = player_s.getCol();
            if (player_row == row_number && player_col == column_number){
                if (!printed) {
                    std::cout << player_s.getSymbol();
                }
                printed = true;
            }

            //print robots on the map
            for (Robot robot_store : robots_s) {
                robot_row = robot_store.getRow();
                robot_col = robot_store.getCol();
                if (robot_row == row_number && robot_col == column_number) {
                    if (!printed) {
                        std::cout << robot_store.getSymbol();
                    }
                    printed = true;
                }
            }

            //print posts in the map
            for (Post post_store : posts_s) {
                post_row = post_store.getRow();
                post_col = post_store.getCol();
                if (post_row == row_number && post_col == column_number) {
                    if (!printed) {
                        std::cout << post_store.getSymbol();
                    }
                    printed = true;
                }
            }

            //print gates in the map
            for (Gate gate_store : gates_s) {
                gate_row = gate_store.getRow();
                gate_col = gate_store.getCol();
                if (gate_row == row_number && gate_col == column_number ) {
                    if (!printed) {
                        std::cout << gate_store.getSymbol();
                    }
                    printed = true;
                }
            }

            //if is none prints a space
            if(!printed){
                std::cout << ' ';
            }

        }

        std::cout << std::endl; //goes to the next line

    }
}

//function to do player movement (private)
void Game::player_movement() {

    std::string player_move; //variable to detect player movement
    bool movement_completed = false;

    Movement player_movement;

    int s_move = 0; //verifies if it is an s input (choose not to move)
    bool valid_move = valid_move_reset; //if move is valid we do it and break from the loop

    std::cout << std::endl << "Where do you want to go?" << std::endl;
    while (!movement_completed) {

        //reset move validation and move positions
        valid_move = valid_move_reset;//flag for invalid movement

        //get player input
        std::cin >> player_move;
        std::cin.ignore(255, '\n');

        //end the program if user press control + z
        if (std::cin.eof()) {
            std::exit(0);
        }

        //load defaut movemetn (no movement)
        player_movement.dRow = no_movement;
        player_movement.dCol = no_movement;

        //determine which char the player chose and validates it
        if (player_move == "q" || player_move == "Q") {
            player_movement.dRow = move_position_negative;
            player_movement.dCol = move_position_negative;
        }
        else if (player_move == "w" || player_move == "W") {
            player_movement.dRow = move_position_negative;
        }
        else if (player_move == "e" || player_move == "E") {
            player_movement.dRow = move_position_negative;
            player_movement.dCol = move_position_positive;
        }
        else if (player_move == "a" || player_move == "A") {
            player_movement.dCol = move_position_negative;
        }
        else if (player_move == "s" || player_move == "S") {
            s_move = detect_s_move;
        }
        else if (player_move == "d" || player_move == "D") {
            player_movement.dCol = move_position_positive;
        }
        else if (player_move == "z" || player_move == "Z") {
            player_movement.dRow = move_position_positive;
            player_movement.dCol = move_position_negative;
        }
        else if (player_move == "x" || player_move == "X") {
            player_movement.dRow = move_position_positive;
        }
        else if (player_move == "c" || player_move == "C") {
            player_movement.dRow = move_position_positive;
            player_movement.dCol = move_position_positive;
        }
        else {
            valid_move = detect_invalid_move;//flag for invalid movement
        }

        //if valid checks where it is going and its consequences
        if (valid_move == valid_move_reset) {

            //player tries to move into a robot
            for (unsigned int i = 0; i < robots.size(); i++) {
                if ((robots[i].getRow() == player.getRow() + player_movement.dRow) && (robots[i].getCol() == player.getCol() + player_movement.dCol)) {
                    if (robots[i].isAlive()) {
                        player.move(player_movement);//puts player where he died
                        player.setAsDead();
                        setGameWin(game_lost); //assures the player has lost
                        movement_completed = true;
                    }
                    else {
                        valid_move = detect_invalid_move;
                    }
                }
            }

            //player tries to move into a post
            for (unsigned int i = 0; i < posts.size(); i++) {
                if ((posts[i].getRow() == player.getRow() + player_movement.dRow) && (posts[i].getCol() == player.getCol() + player_movement.dCol)) {
                    if (posts[i].isElectrified()) {
                        //player doesnt move to electrified post
                        player.setAsDead();
                        setGameWin(game_lost); //assures the player has lost
                        movement_completed = true;
                    }
                    else if (!posts[i].isElectrified()) {
                        valid_move = detect_invalid_move;
                    }
                }
            }

            //player tries to move into gate
            for (unsigned int i = 0; i < gates.size(); i++) {
                if ((gates[i].getRow() == player.getRow() + player_movement.dRow) && (gates[i].getCol() == player.getCol() + player_movement.dCol)) {
                    player.move(player_movement);//puts player in door frame
                    setGameWin(game_won);//signifies play won
                    movement_completed = true;
                }
            }

            //player moves normally
            if (!movement_completed && valid_move) { //if movement has still not be completed move normally
                player.move(player_movement);
                movement_completed = true;
            }
        }

        //if not valid tells the user and restart the loop
        if (!valid_move) {
            std::cout << "Movement invalid, please choose another one" << std::endl;
        }
    }
}

//function to do robot movement (private)
void Game::robot_movement(int robot_index) {

    if (robots[robot_index].isAlive()) {

        //variables to determine where the robot will move
        bool robot_has_moved = false;
        Movement robot_movement;

        //defaut robot movement (no movement)
        robot_movement.dRow = no_movement;
        robot_movement.dCol = no_movement;

        //determines if the robot will move up or down (will chase the player)
        if (robots[robot_index].getRow() - player.getRow() > robot_move_place) {
            robot_movement.dRow = move_position_negative;
        }
        else if (robots[robot_index].getRow() - player.getRow() < robot_move_place) {
            robot_movement.dRow = move_position_positive;
        }

        //determines if the robot will move left or right (will chase the player)
        if (robots[robot_index].getCol() - player.getCol() > robot_move_place) {
            robot_movement.dCol = move_position_negative;
        }
        else if (robots[robot_index].getCol() - player.getCol() < robot_move_place) {
            robot_movement.dCol = move_position_positive;
        }

        //MAKE THE ROBOTS MOVE

        //robot catches player and player dies
        if ((robots[robot_index].getRow() + robot_movement.dRow == player.getRow()) && (robots[robot_index].getCol() + robot_movement.dCol == player.getCol())) {
            robots[robot_index].robotMove(robot_movement);
            player.setAsDead();
            setGameWin(game_lost); //assures the player has lost
            robot_has_moved = true; //sinaliaing the robot has already moved (so no defaut movement)
        }
        //robot goes into posts
        for (unsigned int j = 0; j < posts.size(); j++) {
            if ((posts[j].getRow() == robots[robot_index].getRow() + robot_movement.dRow) && (posts[j].getCol() == robots[robot_index].getCol() + robot_movement.dCol) && !robot_has_moved) {
                if (posts[j].isElectrified()) {
                    //robot doesnt move
                    robots[robot_index].setAsDead(); //robot dies
                    robot_has_moved = true; //sinaliaing the robot has already moved (so no defaut movement)
                }
                else if (!posts[j].isElectrified() && !robot_has_moved) {
                    robots[robot_index].robotMove(robot_movement);//puts robot where he died
                    robots[robot_index].setAsDead();
                    robot_has_moved = true; //sinaliaing the robot has already moved (so no defaut movement)
                }
            }
        }
        //robot goes into gate
        for (unsigned int j = 0; j < gates.size(); j++) {
            if ((gates[j].getRow() == robots[robot_index].getRow() + robot_movement.dRow) && (gates[j].getCol() == robots[robot_index].getCol() + robot_movement.dCol) && !robot_has_moved) {
                //do nothing (robot cant move to door so it doesnt move)
                robot_has_moved = true; //sinaliaing the robot has already moved (so no defaut movement)
            }
        }
        //robot colides with another robot
        for (unsigned int j = 0; j < robots.size(); j++) {
            if ((robots[j].getRow() == robots[robot_index].getRow() + robot_movement.dRow) && (robots[j].getCol() == robots[robot_index].getCol() + robot_movement.dCol) && !robot_has_moved) {
                //only do it if it doesnt collide with itself
                if (robots[j].getID() != robots[robot_index].getID() && !robot_has_moved) {
                    robots[robot_index].robotMove(robot_movement);//puts player where he died
                    robots[robot_index].setAsDead();
                    robots[j].setAsDead();
                    robot_has_moved = true; //sinaliaing the robot has already moved (so no defaut movement)
                }
            }
        }
        //robots move normally
        if (!robot_has_moved) {
            robots[robot_index].robotMove(robot_movement);
        }
    }
}