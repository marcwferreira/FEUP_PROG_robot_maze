#include <iostream>
#include "Position.h"

using namespace std;

Position::Position() {};
int Position::getX() { return x; }
int Position::getY() { return y; }

void Position::setX(int value) { x = value; }
void Position::setY(int value) { y = value; }
void Position::setPosition(int X, int Y) { x = X; y = Y; }


