#include <iostream>
#include "Robot.h"

using namespace std;

enum State { ALIVE, STUCK, DEAD };
Robot::Robot(int row, int col){
	row = row;
	col = col;
}
int Robot::getID() const {
	return id;
}
char Robot::getSymbol() const {
	if(ALIVE){
		return 'R';
	}
	else {
		return 'r';
	}
}// get char representation of robot (R if alive, r if dead)

int Robot::getRow() const {
	return row;
}
int Robot::getCol() const {
	return col;
}
Position Robot::getPosition() const {
	struct Position pos;
	return pos;
}
bool Robot::isAlive() const {
	if (ALIVE) { return true; }
}
void Robot::setRow(int x) {
	row = x;
}
void Robot::setCol(int y) {
	col = y;
}
void Robot::setPosition(const Position& pos) {
	int pos_x = pos.row;
	int pos_y = pos.col;
	setRow(pos_x);
	setCol(pos_y);
}
void Robot::setAsDead() {
	State estado = DEAD;
}
