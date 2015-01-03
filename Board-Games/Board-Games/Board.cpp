#pragma once 

#include "stdafx.h"

using namespace std;

Board::Board()
{
	Board::_square = Empty;
	Board::nRow = { 0 };
	Board::nCol = { 0 };
}

void Board::setSize(int Row, int Col)
{	
	Board::bRow = Row;
	Board::bCol = Col;

	// initializes the array to user defined size up to 100 x 100
	int p_i{ 0 };
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			++p_i; /* put p_i in place of ' ' to initialize in a sequential manner.
				   has a problem at 127, it moves to -127 and if printed you get
				   random characters. char can only take single char if initialized to literal 1 / 9
				   and not anything higher than that.*/
			Board::pos[i][j] = " ";
			Board::ipos[i][j] = Empty;
		}
	}
}

int Board::getRow()
{
	return Board::nRow;
}

int Board::getCol()
{
	return Board::nCol;
}

void Board::setRow(int row)
{
	Board::nRow = row;
}

void Board::setCol(int col)
{
	Board::nCol = col;
}


void Board::ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}


void Board::drawBoard()
{
	ClearScreen();

	// Below was very complicated and does not work for any other size so I put it in an if statement.
	// For text based games the draw board function will have to be made around the board size.

	if (bRow && bCol == 8){
		for (int i = 0; i < bRow; i++)
		{
			for (int k = 0; k < bRow; k++)
			{
				if (k == bRow - 2){ cout << "\t\t\t\t\t     "; break; }
				if (k == 0){ cout << "\n\t\t        |"; }
				cout << "     |";
			}
			for (int j = 0; j < bCol; j++)
			{
				if (j == bCol - 1){ cout << Board::pos[i][j] << "\n"; break; }
				cout << Board::pos[i][j] << "  |  ";

			}
			cout << "\t\t   ";
			if (i < bRow){
				for (int k = 0; k < bRow; k++)
				{
					if (k == bRow - 1){ cout << "_____"; break; }
					cout << "_____|";
				}
				for (int k = 0; k < bRow; k++)
				{
					if (k == bRow - 2){ cout << ""; break; }
					if (k == 0){ cout << "\t\t\t\t        |"; }
					cout << "     |";
				}
			}// My head hurts
		}
	}
	
	if (bRow && bCol == 3)
	{
		char index[3][3]
		{ {'1', '2', '3'},
		{ '4', '5', '6' },
		{ '7', '8', '9' } };

		// Chose to use a visual index. Made the board look cleaner.
		cout << "      board index\n";
		cout << "\n     " << index[0][0] << "  |  " << index[0][1] << "  |  " << index[0][2] << "  \n";
		cout << "\n     " << index[1][0] << "  |  " << index[1][1] << "  |  " << index[1][2] << "  \n";
		cout << "\n     " << index[2][0] << "  |  " << index[2][1] << "  |  " << index[2][2] << "  \n\n";

		
		cout << "\n";


		cout << "\t\t        |     |     \n";
		cout << "\t\t     " << Board::pos[0][0] << "  |  " << Board::pos[0][1] << "  |  " << Board::pos[0][2] << "  \n";
		cout << "\t\t   _____|_____|_____\n";
		cout << "\t\t        |     |     \n";
		cout << "\t\t     " << Board::pos[1][0] << "  |  " << Board::pos[1][1] << "  |  " << Board::pos[1][2] << "  \n";
		cout << "\t\t   _____|_____|_____\n";
		cout << "\t\t        |     |     \n";
		cout << "\t\t     " << Board::pos[2][0] << "  |  " << Board::pos[2][1] << "  |  " << Board::pos[2][2] << "  \n";
		cout << "\t\t        |     |     \n\n";
	}
	
	if (bRow == 8 && bCol == 9){
		cout << "\n   1   2   3   4   5   6   7   8   9\n";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j == 0){ cout << " |"; }
				cout << " " << Board::pos[i][j] << " |";
			}
			cout << "\n";
		}
	}
}

void Board::printArray(int bRow, int bCol)
{
	// tests initialized values for array. Far from polished...

	for (int i = 0; i < bRow; i++)
	{

		for (int j = 0; j < bCol; j++)
		{
			std::cout << i << " x " << j << pos[i][j] << " " << '\t';
		}
	}
}


bool Board::DropPiece(int move, string token)
{
	if (ipos[0][move] == Taken){ return false; }

	for (int i = 0; i < 8; i++)
	{
		switch (ipos[i][move])
		{
		case Empty: 
			Board::Fall(i, move, token);
			if (i == 7){ setMove(7, move, token); return true; }
			break;

		case Taken: 
			//bounce
			--i; setMove(i, move, token); return true;
		}

	}
	return false;
}

void Board::Fall(int x, int y, string token)
{
	Board::pos[x][y] = token;
	Board::drawBoard();
	if (x != 0){ Board::pos[--x][y] = " "; };
	
}

void Board::setMove(int Row, int Col, string token)
{
	pos[Row][Col] = token;
	ipos[Row][Col] = Taken;
}

bool Board::chkWin(string token)
{
	// checks all possible combos to token which is passed in by getToken "X" or "O"
	if ((pos[0][0] == token && pos[0][0] == pos[0][1] && pos[0][1] == pos[0][2] ||
		pos[1][0] == token && pos[1][0] == pos[1][1] && pos[1][1] == pos[1][2] ||
		pos[2][0] == token && pos[2][0] == pos[2][1] && pos[2][1] == pos[2][2] ||
		pos[0][0] == token && pos[0][0] == pos[1][0] && pos[1][0] == pos[2][0] ||
		pos[0][1] == token && pos[0][1] == pos[1][1] && pos[1][1] == pos[2][1] ||
		pos[0][2] == token && pos[0][2] == pos[1][2] && pos[1][2] == pos[2][2] ||
		pos[0][0] == token && pos[0][0] == pos[1][1] && pos[1][1] == pos[2][2] ||
		pos[2][0] == token && pos[2][0] == pos[1][1] && pos[1][1] == pos[0][2]))
	{
		cout << "\t\t\t" << token << " wins!!";
		cin.get();
		return true;
	}

	return false;
}

bool Board::isEmpty(int Row, int Col)
{
	
	switch (Board::ipos[Row][Col]){

	case Empty: return true;
	case Taken: cout << "Enter valid choice...\n"; return false;
	}
	return false;
}

Board::~Board()
{

}
