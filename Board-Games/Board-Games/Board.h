#pragma once

#include "stdafx.h"

class Board
{
public:
	Board();

	int getRow();
	int getCol();
	void setRow(int);
	void setCol(int);
	void setSize(int, int);
	void ClearScreen();
	void drawBoard();
	void printArray(int, int);
	void setMove(int Row, int Col, std::string);
	bool DropPiece(int, std::string);
	bool chkWin(std::string);
		
	~Board();

	std::string pos[100][100];
	int ipos[100][100]; 
	bool isEmpty(int, int);

private:
	// use these to print board at bRow x bCol dimension.
	int bRow, bCol;
	int nRow, nCol;

	enum Square {Empty, Taken};
	Square _square;
};
