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
	void setMove(int, int, std::string);
	bool DropPiece(int, std::string);
	void Fall(int, int, std::string);
	void Color(int);
	std::string drawTile(int, int);
	bool chkWin(std::string);
		
	~Board();

	std::string pos[100][100];
	int ipos[100][100]; 
	bool isEmpty(int, int);

private:
	// use these to print board at bRow x bCol dimension.
	int bRow, bCol;
	int nRow, nCol;

	struct pieces
	{
		enum Color {
			BLUE = 1, GREEN, CYAN, RED, PURPLE, DRK_YELLOW, DEFAULT, GRAY,
			BRT_BLUE, BRT_GREEN, BRT_CYAN, BRT_RED, MAGENTA, YELLOW, BRT_WHITE
		};
		Color color;

	} piece;

	enum Square {Empty, Taken_X, Taken_O};
	Square _square;
};
