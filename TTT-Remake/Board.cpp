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
	bRow = Row;
	bCol = Col;

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
			pos[i][j] = " ";
			ipos[i][j] = Empty;
		}
	}
}

int Board::getRow()
{
	return nRow;
}

int Board::getCol()
{
	return nCol;
}

int Board::getMove()
{
	char s_move;

	std::cin >> s_move;

	// simple conversion from string to corresponding Row/Column to later modify array. 
	// this can be applied to many different array types.

	// ToDo: Apply this to "get Key Press" function...
	switch (s_move){

	case '1': nRow = 0; nCol = 0; return 1;
	case '2': nRow = 0; nCol = 1; return 2;
	case '3': nRow = 0; nCol = 2; return 3;
	case '4': nRow = 1; nCol = 0; return 4;
	case '5': nRow = 1; nCol = 1; return 5;
	case '6': nRow = 1; nCol = 2; return 6;
	case '7': nRow = 2; nCol = 0; return 7;
	case '8': nRow = 2; nCol = 1; return 8;
	case '9': nRow = 2; nCol = 2; return 9;
	}
	return 0;
}

void Board::drawBoard()
{
	ClearScreen();

	char index[3][3]
		{ {'1', '2', '3'},
		{ '4', '5', '6' },
		{ '7', '8', '9' } };

	// Chose to use a visual index. Made the board look cleaner.
	cout << "      board index\n";
	cout << "\n     " << index[0][0] << "  |  " << index[0][1] << "  |  " << index[0][2] << "  \n";
	cout << "\n     " << index[1][0] << "  |  " << index[1][1] << "  |  " << index[1][2] << "  \n";
	cout << "\n     " << index[2][0] << "  |  " << index[2][1] << "  |  " << index[2][2] << "  \n\n";

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

void Board::printArray(int nRow, int nCol)
{
	// tests initialized values for array. Far from polished...

	for (int i = 0; i < nRow; i++)
	{

		for (int j = 0; j < nCol; j++)
		{
			std::cout << i << " x " << j << pos[i][j] << " " << '\t';
		}
	}
}

bool Board::chkMove()
{
	// ipos can only be 0 or 1. This is now universal and wicked simple!
	switch (ipos[nRow][nCol]){

	case Empty: return true;
	case Taken: cout << "Enter valid choice...\n"; return false;
	}

	
	return false;
}

void Board::setMove(std::string token)
{
	// these values are set after chkMove is true
	pos[nRow][nCol] = token;
	ipos[nRow][nCol] = Taken;
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

Board::~Board()
{

}
