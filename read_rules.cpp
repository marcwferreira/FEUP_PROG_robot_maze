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
#include "read_rules.h"

void read_rules(){

    std::string rules_read; //var to load rules file

    //show the rules
            std::ifstream rules_file;
            rules_file.open("RULES.TXT");
            //alternative rules if file does not exist
            if(!rules_file.is_open()){
                std::cout << "Rules:" << std::endl;
                std::cout << "Your objective is to survive inside the maze while robots chase you" << std::endl;
                std::cout << "You win the game if all robots are destroyed and you are still alive" << std::endl;
                std::cout << "'H' is your character" << std::endl;
                std::cout << "'h' is your character if you die (game over)" << std::endl;
                std::cout << "'*' is electric walls, if you hit then you die" << std::endl;
                std::cout << "'R' is an alive robot, they will chase you, you die if you touch them" << std::endl;
                std::cout << "'r' is a destroyed robot, you cannot walk over them" << std::endl;
                std::cout << "Robots are destroyed when they hit a fence or another robot (alive or destroyed)" << std::endl;
                std::cout << "The game works in rounds, you make a movement then the robots" << std::endl;
                std::cout << "Here is a list of possible movements in a round: " << std::endl;
                std::cout << "'q' or 'Q' : walk up-left (diagonal)" << std::endl;
                std::cout << "'w' or 'W' : walk up" << std::endl;
                std::cout << "'e' or 'E' : walk up-right (diagonal)" << std::endl;
                std::cout << "'a' or 'A' : walk left" << std::endl;
                std::cout << "'s' or 'S' : stay in place (no movement)" << std::endl;
                std::cout << "'d' or 'D' : walk right" << std::endl;
                std::cout << "'z' or 'Z' : walk down-left (diagonal)" << std::endl;
                std::cout << "'x' or 'X' - walk down" << std::endl;
                std::cout << "'c' or 'C' - walk down-right (diagonal)" << std::endl << std::endl;
                std::cout << "There is also time scores for people that win the game" << std::endl;
                std::cout << "Good Luck!" << std::endl << std::endl;
            }
            //rules if file exist
            else{
                while (getline(rules_file, rules_read)) {
                    std::cout << rules_read << std::endl;
                } 
                rules_file.close();
            }
}