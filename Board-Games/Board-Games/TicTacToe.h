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
	int minimax(int node, int depth, bool maximizingPlayer);

private:
	int _gameState;
		
};

