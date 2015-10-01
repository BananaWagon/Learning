#pragma once
#include "GameBase.h"

class TicTacToe :
	public GameBase
{
	Board TTT;
	Player _player;

public:
	TicTacToe();
	~TicTacToe();
	int Run();
	void input();
	void update();
	void drawBoard();
	bool chkWin();
	int alphabeta(int node, int depth, int a, int b, bool maximizingPlayer);

private:
	int _gameState;
		
};

