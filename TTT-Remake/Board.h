#pragma once

#include "stdafx.h"

class Board
{
public:
	Board();
	int getRow();
	int getCol();
	int getMove();
	void setSize(int, int);
	void drawBoard();
	void printArray(int, int);
	void setMove(std::string);
	bool chkMove();
	bool chkWin(std::string);

	std::string pos[100][100];

	~Board();

private:
	// use these to print board at bRow x bCol dimension.
	int bRow, bCol;
	int nRow, nCol;
	
	int ipos[100][100];
	static enum Square {Empty, Taken};
	Square _square;
};
