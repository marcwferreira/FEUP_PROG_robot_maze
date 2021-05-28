#include <iostream>
#include <list>
#include "Post.h"
#include "Position.h"
#include "Maze.h"

using namespace std;

Maze::Maze(int numRows, int numCols){
	numRows = numRows;
	numCols = numCols;
}
bool Maze::addPost(const Post& post, const Position& position) {
	//n�o sei para que serve a posi��o
	listPosts.push_back(post);

}
int Maze::getnumRows() const {
	return numRows;
}
int Maze::getnumCols() const {
	return numCols;
}

