#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <list>

using namespace std;

class Position
{
public:
	Position();

	int getX();
	int getY();

	void setX(int value);
	void setY(int value);
	void setPosition(int X, int Y);

public:

	int x = 0;
	int y = 0;
};

#endif

