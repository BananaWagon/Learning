#include "stdafx.h"
#include "TicTacToe.h"

TicTacToe::TicTacToe()
{

}

TicTacToe::~TicTacToe()
{

}

int TicTacToe::Run()
{
	// Initializes array to null 3x3 to show a blank board. 
	Board TTT;
	TTT.setSize(3, 3);
	TTT.drawBoard();



	Player _player;

	// This is the actual game loop. Total of 9 turns.

	// Consider making a loop to get inputs, update, draw. Could make the code below easier.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//sets player state after loop back
			_player.setState();

			// Loop will not break unless chkMove evaluates to true
			while (_player._playerState == Player::Player1 || Player::Player2)
			{

				_player.whosTurn();
				_player.getMove();

				if (TTT.isEmpty(_player.getRow(), _player.getCol()))
				{
					TTT.setMove(_player.getRow(), _player.getCol(), _player.getToken(_player._playerState));

					TTT.drawBoard();

					if (TTT.chkWin(_player.getToken(_player._playerState))) { _gameState = Game::ShowingMenu; std::cin.get(); TTT.ClearScreen(); return 1; }

					break;
				}
				continue;
			}
		}
	}
}