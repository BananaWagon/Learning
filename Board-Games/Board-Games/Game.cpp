#pragma once

#include "stdafx.h"

using namespace std;



void Game::Start()
{

	if (_gameState != Uninitialized)
	{
		return;
	}

	// This is universal and can be used in other programs
	_gameState = Game::ShowingMenu;

	while (!IsExiting())
	{
		gameLoop();
	}

	close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::gameLoop()
{
	int result { 0 };

	switch (_gameState)
	{
	case Game::ShowingMenu: { result = showMenu(); }
	case Game::Playing:		{ if (result == 1) { C4(); }
							  if (result == 2) { TicTacToe(); } 
							break; }
	}
	//_gameState = Exiting;   //<-- uncomment to have game auto exit.
	//add something to show winner and prompt to "Play again?"
}

int Game::showMenu()
{
	int result{ 0 };
	while (result == 0)
	{
		cout << "\t\t    --------------- \n";
		cout << "\t\t_-/||  X BOARD X  ||\n";
		cout << "\t\t   ||    X @ X    ||\n";
		cout << "\t\t   ||  X GAMES X  ||/-_\n";
		cout << "\t\t    ---------------\n\n";

		cout << "1. Connect Four\n";
		cout << "2. Tic Tac Toe\n";
		cout << "3. Exit\n\n";
		cin >> result;

		switch (result)
		{
		case 1: _gameState = Game::Playing; return result; 
		case 2: _gameState = Game::Playing; return result; 
		case 3: _gameState = Game::Exiting; break;
		default: continue;
		}
	}
}

void Game::close()
{
	// just to throw an error
	if (_gameState == Uninitialized) { cout << "/t !! Nothing was evaluated in start() !!"; }

	cin.get();
	return;
}

void Game::C4()
{
	Board C4;
	C4.setSize(8, 9);
	C4.drawBoard();

	Player players[2];
	int player {0};

		
	while (_gameState == Playing)
	{
		int col{ 0 };
		col = players[player].getMove();

		if (!C4.isEmpty( 0, col)){ continue; }
		
		C4.DropPiece(col, players[player].getToken(player));
		
		C4.drawBoard();

		player = (player + 1) % 2;
		
	}
}

void Game::TicTacToe()
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

					if (TTT.chkWin(_player.getToken(_player._playerState))) { _gameState = ShowingMenu; cin.get(); TTT.ClearScreen(); return; }

					break;
				}
				continue;
			}
		}
	}
}
Game::GameState Game::_gameState = Uninitialized;
Game::GameState Game::_mode	     = Uninitialized;