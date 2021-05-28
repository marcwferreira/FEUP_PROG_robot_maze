#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include "Position.h"

using namespace std;

class Robot
{
public:
	enum State { ALIVE, STUCK, DEAD };
	Robot(int row, int col);
	int getID() const;
	char getSymbol() const; // get char representation of robot (R if alive, r if dead)
	int getRow() const;
	int getCol() const;
	Position getPosition() const;
	bool isAlive() const;
	void setRow(int x);
	void setCol(int y);
	void setPosition(const Position& pos);
	void setAsDead();
	//other methods
private:
	static int robotCounter; //used to attribute automatically the id to the robots
	int id;
	int row, col;
	bool alive;
	// other attributes (?)

};

#endif

