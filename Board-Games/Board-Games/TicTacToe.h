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
	bool chkWin();
	int alphabeta(int node, int depth, int a, int b, bool maximizingPlayer);

private:
	int _gameState;
		
};

