#pragma once
#include "GameBase.h"
#include "Board.h"

class ConnectFour :
	public GameBase
{
public:
	ConnectFour();
	~ConnectFour();
	int Run();

private:
	int _gameState;
};

