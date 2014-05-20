#include "TGame.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/*
TGame::TGame()
{
	player1 = "Player 1";
	player2 = "Player 2";
	XsTurn = true;
	gameOver = false;
	for(short row=0; row<3; row++)
		for(short col=0; col<3; col++)
			gameBoard[row][col] = EMPTY;
}
*/
TGame::TGame(string p1, string p2)
{
	player1 = p1;
	player2 = p2;
	XsTurn = true;
	gameOver = false;
	for(short row=0; row<3; row++)
		for(short col=0; col<3; col++)
			gameBoard[row][col] = EMPTY;	
}

TGame::~TGame(){/*TODO*/}

void TGame::gameIntro()
{
	cout << "Enter move: [row #] [col #]" << endl;
	cout << "Move example: 1 3" << endl;
	cout << "1st row, 3rd column" << endl;
}

void TGame::startGame()
{
	gameIntro();
	gameOver = false;
	while(gameOver == false)
	{
		print();
		takeTurn();
	}
	print(); // print out final board
	cout << "Game Over" << endl;
}

void TGame::takeTurn()
{
	if(XsTurn)
		cout << player1 << "'s move: ";
	else
		cout << player2 << "'s move: ";
	short r, c; // row and colum of move
	cin >> r;
	cin >> c;
	r--; // convert to 0 base index
	c--;
	if(validMove(r,c) == false)
	{
		cout << "Invalid move" << endl;
		return; //takeTurn();
	}
	// else - it was a valid move. Check for winner
	// set move on board
	if(XsTurn)
		gameBoard[r][c] = EX;
	else
		gameBoard[r][c] = OH;

	if(checkBoard() == true) // we have a winner
	{
		if(XsTurn == true)
			cout << player1 << " Wins!" << endl;
		else
			cout << player2 << " Wins!" << endl;
		gameOver = true;
		return;
	}
	if(fullBoard() == true) // the board is all filled
	{
		cout << "Players Tied!" << endl;
		gameOver = true;
	}
	//switch XsTurn
	if(XsTurn == true) // it was X's turn
		XsTurn = false; // now it is O's turn
	else // if O's turn
		XsTurn = true; // change to X's turn
	return;
}

bool TGame::validMove(short r, short c)
{
	if(r < 0 || r > 2 || c < 0 || c > 2)
		return false;
	if(gameBoard[r][c] == EMPTY)
		return true;
	else
		return false;
}

bool TGame::checkBoard()
{
	// check rows
	for(short row=0; row <= 2; row++)
	{
		if(gameBoard[row][0] == gameBoard[row][1] && 
			gameBoard[row][1] == gameBoard[row][2] &&
			gameBoard[row][2] != EMPTY )
			return true;
	}
	// check columns
	for(short col=0; col <= 2; col++)
	{
		if(gameBoard[0][col] == gameBoard[1][col] && 
			gameBoard[1][col] == gameBoard[2][col] && 
			gameBoard[2][col] != EMPTY )
			return true;
	}
	// check diagonals
	if(gameBoard[0][0] == gameBoard[1][1] && 
		gameBoard[1][1] == gameBoard[2][2] && 
		gameBoard[2][2] != EMPTY )
		return true;

	if(gameBoard[0][2] == gameBoard[1][1] && 
		gameBoard[1][1] == gameBoard[2][0] && 
		gameBoard[2][0] != EMPTY)
		return true;

	return false;
}

bool TGame::checkBoard(short r, short c)
{
	//TODO optimized checking
	// only check rows/colums/diagonals that could result in a winner
	// based on the location of the last move
}

bool TGame::fullBoard()
{
	for(short row=0; row <= 2; row++)
		for(short col=0; col <= 2; col++)
			if(gameBoard[row][col] == EMPTY)
				return false; // found an empty slot
	return true;
}

void TGame::print()
{
	cout << "-------------------------" << endl;
	for(short row=0; row<3; row++)
	{
		cout << "\t";
		for(short col=0; col<3; col++)
		{
			if(gameBoard[row][col] == EX)
				cout << "X ";
			else if(gameBoard[row][col] == OH)
				cout << "O ";
			else
				cout << "- ";
			if(col != 2)
				cout << "| ";
		}
		cout << "\n";
	}

	if(gameOver == true)
	{
		cout << "Congratulations ";
		if(XsTurn == true)
			cout << player1;
		else
			cout << player2;
		cout << "!" << endl;
	}

}