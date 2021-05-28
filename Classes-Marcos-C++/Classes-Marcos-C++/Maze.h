#ifndef MAZE_H
#define MAZE_H

#include "Post.h"
#include "Position.h"

using namespace std;

class Maze
{
public:
	Maze(int numRows, int numCols);
	bool addPost(const Post& post, const Position& position);
	int getnumRows() const;
	int getnumCols() const;
	// other methods
private:
	int numRows, numCols;
	list <Post> listPosts;
	// data structure that represents the posts
};

#endif

