#ifndef TGAME_H
#define TGAME_H

enum Cell {EMPTY, EX, OH}; // emty cell, X, O

class TGame
{
private:
	Cell gameBoard [3][3];
public:
	TGame();
	~TGame();

	void print();

};

#endif