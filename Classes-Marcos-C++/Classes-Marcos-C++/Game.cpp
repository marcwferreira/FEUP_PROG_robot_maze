#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Game.h"

using namespace std;

Game::Game(const string& filename) {
	string line;

	ifstream MyReadFile(filename);

	while (getline(MyReadFile, line)) {
		//fazer a leitura dos objetos 

	}
}

// This constructor should initialize the Maze, the vector of Robots, and the Player,
// using the chars read from the file

bool Game::play() {// implements the game loop; returns true if player wins, false otherwise} 
bool Game::isValid() { //não percebo o erro
	char option;

	cin >> option;
	if (cin.fail()) {
		cout << "Not a valid input. Please try again!" << endl;
		cin.clear();
		cin.ignore(CHAR_MAX, '\n');
		return false;
	}
	return true;
}
void Game::showGameDisplay() const {}
bool Game::collide(Robot& robot, Post& post) {
	// check if robot collided with post (and possibly set it as dead)
} 
bool Game::collide(Robot& robot, Player& player) {// check if human and robot collided (and possibly set human as dead)
} 
	// other methods, for example:
	// to check if player is trying to move to a valid place
	// to apply a valid play and check collisions
	// to check if two robots collide (and possibly set them as dead)
	// etc.