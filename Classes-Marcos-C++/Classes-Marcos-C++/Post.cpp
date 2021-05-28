#include <iostream>
#include "Post.h"

using namespace std;

Post::Post(int row, int col, char type) {
	row = row;
	col = col;
	type = type;
}
int Post::getRow() const{
	return row;
}
int Post::getCol() const {
	return col;
}
char Post::getSymbol() const {
	return type;
} // get char representation of Post
bool Post::isElectrified() const {
	if (type == '*') {
		return true;
	}
	else {
		return false;
	}
	
}
//other methods