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
				if (_player.getMove() == 99) { _gameState = Game::ShowingMenu; return 1; }

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
				
				TTT.Color(TTT.DRK_YELLOW);
				cout << "      board index\n";
				TTT.Color(TTT.RED);
				
				// Chose to use a visual index. Made the board look cleaner.
				
				cout << "\n     " << index[0][0] << "  |  " << index[0][1] << "  |  " << index[0][2] << "  \n";
				cout << "\n     " << index[1][0] << "  |  " << index[1][1] << "  |  " << index[1][2] << "  \n";
				cout << "\n     " << index[2][0] << "  |  " << index[2][1] << "  |  " << index[2][2] << "  \n\n";
				TTT.Color(TTT.DEFAULT);
				
				cout << "\n";
		
		
				cout << "\t\t        |     |     \n";
				cout << "\t\t     " << TTT.drawTile(0, 0) << ""; TTT.Color(TTT.DEFAULT);  cout << "  |  " << TTT.drawTile(0, 1) << ""; TTT.Color(TTT.DEFAULT);  cout << "  |  " << TTT.drawTile(0, 2) << ""; TTT.Color(TTT.DEFAULT);  cout << "  \n";
				cout << "\t\t   _____|_____|_____\n";
				cout << "\t\t        |     |     \n";
				cout << "\t\t     " << TTT.drawTile(1, 0) << ""; TTT.Color(TTT.DEFAULT);  cout << "  |  " << TTT.drawTile(1, 1) << ""; TTT.Color(TTT.DEFAULT);  cout << "  |  " << TTT.drawTile(1, 2) << ""; TTT.Color(TTT.DEFAULT);  cout << "  \n";
				cout << "\t\t   _____|_____|_____\n";
				cout << "\t\t        |     |     \n";
				cout << "\t\t     " << TTT.drawTile(2, 0) << ""; TTT.Color(TTT.DEFAULT);  cout << "  |  " << TTT.drawTile(2, 1) << ""; TTT.Color(TTT.DEFAULT);  cout << "  |  " << TTT.drawTile(2, 2) << ""; TTT.Color(TTT.DEFAULT);  cout << "  \n";
				cout << "\t\t        |     |     \n\n";
}