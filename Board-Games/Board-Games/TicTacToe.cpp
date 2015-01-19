#include "stdafx.h"
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe()
{

}

TicTacToe::~TicTacToe()
{

}

int TicTacToe::Run()
{
	// Initializes array to null 3x3 to show a blank board. 
	//Board TTT;
	TTT.setSize(3, 3);
	drawBoard();



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

					drawBoard();

					if (TTT.chkWin(_player.getToken(_player._playerState))) { _gameState = Game::ShowingMenu; std::cin.get(); TTT.ClearScreen(); return 1; }

					break;
				}
				continue;
			}
		}
	}
}

void TicTacToe::drawBoard()
{
	TTT.ClearScreen();
	char index[3][3]
				{ {'1', '2', '3'},
				{ '4', '5', '6' },
				{ '7', '8', '9' } };
		
				// Chose to use a visual index. Made the board look cleaner.
				cout << "      board index\n";
				cout << "\n     " << index[0][0] << "  |  " << index[0][1] << "  |  " << index[0][2] << "  \n";
				cout << "\n     " << index[1][0] << "  |  " << index[1][1] << "  |  " << index[1][2] << "  \n";
				cout << "\n     " << index[2][0] << "  |  " << index[2][1] << "  |  " << index[2][2] << "  \n\n";
		
				
				cout << "\n";
		
		
				cout << "\t\t        |     |     \n";
				cout << "\t\t     " << TTT.pos[0][0] << "  |  " << TTT.pos[0][1] << "  |  " << TTT.pos[0][2] << "  \n";
				cout << "\t\t   _____|_____|_____\n";
				cout << "\t\t        |     |     \n";
				cout << "\t\t     " << TTT.pos[1][0] << "  |  " << TTT.pos[1][1] << "  |  " << TTT.pos[1][2] << "  \n";
				cout << "\t\t   _____|_____|_____\n";
				cout << "\t\t        |     |     \n";
				cout << "\t\t     " << TTT.pos[2][0] << "  |  " << TTT.pos[2][1] << "  |  " << TTT.pos[2][2] << "  \n";
				cout << "\t\t        |     |     \n\n";
}