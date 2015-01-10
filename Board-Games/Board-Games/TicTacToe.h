#pragma once
#include "GameBase.h"
#include "Board.h"

class TicTacToe :
	public GameBase
{
public:
	TicTacToe();
	~TicTacToe();
	int Run();

private:
	int _gameState;
};