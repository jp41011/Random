#ifndef TGAME_H
#define TGAME_H
#include <string>
using std::string;

enum Cell {EMPTY, EX, OH}; // emty cell, X, O

class TGame
{
private:
	Cell gameBoard [3][3];
	string player1; // will be X
	string player2; // will be O
	bool XsTurn; // is it X's turn
	bool gameOver;
public:
	//TGame();
	TGame(string p1="Player 1", string p2="Player 2");
	~TGame();
	void gameIntro();
	void startGame();
	void takeTurn(); // player takes turn
	bool validMove(short, short);
	bool checkBoard(); // true if winner, false not winner yet
	bool checkBoard(short, short); // true = winner, false = no winner
	bool fullBoard(); // is the board completely filled
	void print();

};

#endif