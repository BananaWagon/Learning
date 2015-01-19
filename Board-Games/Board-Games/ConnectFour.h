#pragma once
#include "GameBase.h"
#include "Board.h"

class ConnectFour :
	public GameBase
{
	Board C4;
public:
	ConnectFour();
	~ConnectFour();
	int Run();
	void drawBoard();
	bool DropPiece(int, std::string);
	void Fall(int, int, std::string);

private:
	int _gameState;
};

