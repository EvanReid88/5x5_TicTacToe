#pragma once
#include <iostream>
#include <string>

using namespace std;

class TicTacToeGame
{
public:
	TicTacToeGame();

	void TicTacToeGame::printBoard();
	void TicTacToeGame::playGame();
	void TicTacToeGame::clearBoard();
	int TicTacToeGame::CheckWinner();

	~TicTacToeGame();
private:

	string board[9];
	int boardval[5][5];

};

