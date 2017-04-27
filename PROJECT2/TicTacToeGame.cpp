#include "TicTacToeGame.h"

// also don't let user enter char

// TIE GAME CODE

TicTacToeGame::TicTacToeGame()
{
	clearBoard();
}



void TicTacToeGame::playGame() {

	bool gamenotdone = true;
	int turncount = 1;

	do {

		char shape;
		int shapeval; // 1 is X, 2 is O
		int row, column;
		printBoard();

		if (turncount == 1 || turncount % 2 == 1) {
			shape = 'X';
			shapeval = 1;
			cout << "Player One's Turn (X's). " << endl << endl;
		}
		else {
			shape = 'O';
			shapeval = 2;
			cout << "Player Two's Turn (O's). " << endl << endl;
		}


		bool emptyspace = true;

		do {
			// get row
			bool rowval = true;
			do {


				cout << "Enter the row (1-5): ";

				while (!(cin >> row)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Try again: ";
				}

				if (row < 1 || row > 5) {
					cout << endl << "Invalid input. " << endl;
				}
				else {
					rowval = false;
				}

			} while (rowval);

			// get column
			bool colval = true;
			do {
				cout << "Enter the column (1-5): ";

				while (!(cin >> column)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Try again: ";
				}

				if (column < 1 || column > 5) {
					cout << endl << "Invalid input. " << endl;
				}
				else {
					colval = false;
				}
			} while (colval);



			if (boardval[row - 1][column - 1] == 0) {
				boardval[row - 1][column - 1] = shapeval;

				cout << "An " << shape << " was placed in row " << row << ", column " << column << ". " << endl;
				// add to value board

				for (int i = 0; i < 5; i++) {
					if (row - 1 == i) {
						for (int k = 0; k < 5; k++) {
							if (column - 1 == k) {
								boardval[i][k] = shapeval;
							}
						}
					}
				}

				// add shape to printed board
				int countrow = 0;
				for (int i = 0; i < 9; i += 2) {
					if (row - 1 == countrow) {
						int countcol = 0;
						for (int k = 1; k < 19; k += 4) {
							if (column - 1 == countcol) {
								board[i][k] = shape;
							}
							countcol++;
						}
					}
					countrow++;
				}
				emptyspace = false;
			}
			else {
				cout << "Not an open space. Try another location." << endl;
			}
		} while (emptyspace);

		switch (CheckWinner()) {
		case 0:
			break;
		case 1:
			printBoard();
			cout << "Player One, X's Won!" << endl;
			gamenotdone = false;
			break;
		case 2:
			printBoard();
			cout << "Player Two, O's Won!" << endl;
			gamenotdone = false;
			break;
		case 3: 
			printBoard();
			cout << "It's a tie!" << endl;
			gamenotdone = false;
			break;
		}

		turncount++;

	} while (gamenotdone);

	clearBoard();

}

void TicTacToeGame::printBoard() {

	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << board[i] << endl;
	}
	cout << endl;

}

void TicTacToeGame::clearBoard() {
	for (int i = 0; i < 9; i++) {
		switch (i) {
		case 0:case 2:case 4:case 6:case 8:
			board[i] = "   |   |   |   |   ";
			break;
		case 1:case 3:case 5:case 7:
			board[i] = "-------------------";
			break;
			//default: 
		}
	}

	// fill value board with 0's
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			boardval[i][k] = 0; // 0 means none, 1 is X, 2 is 0
		}
	}
}

int TicTacToeGame::CheckWinner() {

	char shapes[2] = { 'X', 'O' }; // 1, 2
	int xwinrow = 0;
	int owinrow = 0;

	int xwincol = 0;
	int owincol = 0;

	int xleft = 0;
	int xright = 0;
	int oleft = 0;
	int oright = 0;

	bool xwins = false, owins = false;

	// check for X's in row
	for (int i = 0; i < 5; i++) {
		if (boardval[i][0] == 1) {
			// check for X's in column
			xwincol++;
			for (int k = 0; k < 5; k++) {

				if (boardval[i][k] == 1) {
					xwinrow++;
				}
			}
		}
	}

	// check fo O's in row
	for (int i = 0; i < 5; i++) {
		if (boardval[i][0] == 2) {
			// check for O's in column
			owincol++;
			for (int k = 0; k < 5; k++) {

				if (boardval[i][k] == 2) {
					owinrow++;
				}
			}
		}
	}

	// check diagonal X and O

	int diagcount = 0;
	for (int i = 0; i < 5; i++) {

		if (boardval[i][0 + diagcount] == 1) {
			xleft++;
		}
		else if (boardval[i][0 + diagcount] == 2) {
			oleft++;
		}

		if (boardval[i][4 - diagcount] == 1) {
			xright++;
		}
		else if (boardval[i][4 - diagcount] == 2) {
			oright++;
		}

		diagcount++;
	}

	// check tie
	int tie = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (boardval[i][j] != 0) {
				tie++;
			}
		}
	}


	if (xwinrow == 5 || xwincol == 5 || xleft == 5 || xright == 5) {
		return 1;
	}
	else if (owinrow == 5 || owincol == 5 || oleft == 5 || oright == 5) {
		return 2;
	}
	else if (tie == 25){
		return 3;
	}
	else {
		return 0;
	}



}

TicTacToeGame::~TicTacToeGame()
{
}
