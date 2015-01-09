#include "stdafx.h"
#include "ConnectFour.h"


ConnectFour::ConnectFour()
{
}


ConnectFour::~ConnectFour()
{
}


int ConnectFour::Run()
{
	Board C4;
	C4.setSize(8, 9);
	C4.drawBoard();

	Player players[2];
	int player{ 0 };

	//TODO: Change the GameState so the players can exit
	_gameState = 0;
	while (_gameState == 0)
	{
		int col{ 0 };
		col = players[player].getMove();

		if (!C4.isEmpty(0, col)){ continue; }

		C4.DropPiece(col, players[player].getToken(player));

		C4.drawBoard();

		player = (player + 1) % 2;

	}
	return 1;
}
