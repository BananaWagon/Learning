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

	C4.setSize(8, 9);
	drawBoard();

	Player	players[2];
	int		player{ 0 };

	//TODO: Change the GameState so the players can exit
	
	Game state;
	state._gameState = state.Playing;

	while (state._gameState == state.Playing)
	{
		
		int col	{ 0 };
		col =	players[player].getMove();
		
		if (col == 99)	{state._gameState = state.ShowingMenu;}

		if (!C4.isEmpty(0, col)){ continue; }

		DropPiece(col, players[player].getToken(player));

		drawBoard();

		player = (player + 1) % 2;

	}
	return 1;
}

void ConnectFour::drawBoard()
{
	C4.ClearScreen();

	C4.Color(C4.RED);
	std::cout << "\n   1   2   3   4   5   6   7   8   9\n"; 
	C4.Color(C4.CYAN);
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 0){ std::cout << " |"; }
			std::cout << " " << C4.drawTile(i, j) << ""; C4.Color(C4.CYAN); std::cout << " |";
		}
		std::cout << "\n";
	}
	C4.Color(C4.DEFAULT);
}

bool ConnectFour::DropPiece(int move, std::string token)
{
	if (C4.ipos[0][move] != C4.Empty){ return false; }

	for (int i = 0; i < 8; i++)
	{
		switch (C4.ipos[i][move])
		{
		case Board::Empty:
			Fall(i, move, token);
			if (i == 7){ C4.setMove(7, move, token); return true; }
			break;

		default:
			//bounce
			--i; C4.setMove(i, move, token); return true;
		}

	}
	return false;
}

void ConnectFour::Fall(int x, int y, std::string token)
{
	C4.pos[x][y] = token;

	if (token == "X")	{ C4.ipos[x][y] = C4.Taken_X; }
	if (token == "O")	{ C4.ipos[x][y] = C4.Taken_O; }

	drawBoard();
	
	if (x != 0) { C4.pos[--x][y] = " "; C4.ipos[x][y] = C4.Empty; };
}