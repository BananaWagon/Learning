#pragma once
#include "GameBase.h"
#include "Board.h"

class TicTacToe :
	public GameBase
{
	Board TTT;
public:
	TicTacToe();
	~TicTacToe();
	int Run();
	void drawBoard();

private:
	int _gameState;
};