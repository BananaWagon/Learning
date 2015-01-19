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

void Board::Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string Board::drawTile(int x, int y)
{
	
	switch (ipos[x][y])
	{
	
	case Empty:
		return Board::pos[x][y];
		

	case Taken_X:
		Color(RED);
		return Board::pos[x][y];
		
		
	case Taken_O:
		Color(DRK_YELLOW);
		return Board::pos[x][y];
		
	}
	return "?";
}

void Board::setMove(int Row, int Col, string token)
{
	pos[Row][Col] = token;
	if (token == "X") { ipos[Row][Col] = Taken_X; }
	else if (token == "O") { ipos[Row][Col] = Taken_O; }
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
	case Taken_X: cout << "\n\t  !! Slot Full !!\n"; return false;
	case Taken_O: cout << "\n\t  !! Slot Full !!\n"; return false;
	}
	return false;
}

Board::~Board()
{

}
