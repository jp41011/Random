#include "TGame.h"
#include <iostream>
using std::cout;
using std::endl;

TGame::TGame()
{
	for(short row=0; row<3; row++)
		for(short col=0; col<3; col++)
			gameBoard[row][col] = EMPTY;
}

TGame::~TGame(){/*TODO*/}

void TGame::print()
{
	for(short row=0; row<3; row++)
	{
		cout << "\t";
		for(short col=0; col<3; col++)
		{
			if(gameBoard[row][col] == EX)
				cout << "X";
			else if(gameBoard[row][col] == OH)
				cout << "O";
			else
				cout << "-";
			if(col != 2)
				cout << "|";
		}
		cout << "\n";
	}
}