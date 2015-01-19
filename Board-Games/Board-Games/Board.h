#pragma once

#include "stdafx.h"

class Board
{

private:
	// use these to print board at bRow x bCol dimension.
	int bRow, bCol;
	int nRow, nCol;

public:
	Board();

	int getRow();
	int getCol();
	void setRow(int);
	void setCol(int);
	void setSize(int, int);
	void ClearScreen();
	void printArray(int, int);
	void setMove(int, int, std::string);
	void Color(int);
	std::string drawTile(int, int);
	bool chkWin(std::string);
		
	~Board();

	std::string pos[100][100];
	int ipos[100][100]; 
	bool isEmpty(int, int);

	enum Color {
		BLUE = 1, GREEN, CYAN, RED, PURPLE, DRK_YELLOW, DEFAULT, GRAY,
		BRT_BLUE, BRT_GREEN, BRT_CYAN, BRT_RED, MAGENTA, YELLOW, BRT_WHITE
	}color;

	enum Square { Empty, Taken_X, Taken_O }_square;
};
