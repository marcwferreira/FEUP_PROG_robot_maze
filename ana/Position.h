#include <iostream>
#include <string>
#include <list>

using namespace std;

class Position
{

public:

    Position() {};

    int getX() { return x; }
    int getY() { return y; }

    void setX(int value) { x = value; }
    void setY(int value) { y = value; }
    void setPosition(int X, int Y) { x = X; y = Y; }


private:

    int x = 0;
    int y = 0;

};


