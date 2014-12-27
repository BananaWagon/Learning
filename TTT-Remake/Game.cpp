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
	switch (_gameState)
	{
	case Game::ShowingMenu: { showMenu(); break; }
	case Game::Playing:		{ TicTacToe(); cin.get();  break; }
	}
	//_gameState = Exiting;   //<-- uncomment to have game auto exit.
	//add something to show winner and prompt to "Play again?"
}

void Game::showMenu()
{
	int result{ 0 };
	while (result == 0)
	{
		ClearScreen();

		cout << "\t\t    --------------- \n";
		cout << "\t\t_-/||  X  TAC  X  ||\n";
		cout << "\t\t   || TIC  O  TOE ||\n";
		cout << "\t\t   ||  X  TAC  X  ||/-_\n";
		cout << "\t\t    ---------------\n\n";

		cout << "1. Play \n2. Exit \n\n";
		cin >> result;

		switch (result)
		{
		case 1: _gameState = Game::Playing; break;
		case 2: _gameState = Game::Exiting; break;
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
			while (_player._playerState == Player::PlayerX || Player::PlayerO)
			{
				
				_player.whosTurn();
				TTT.getMove();

				if (TTT.chkMove())
				{
					TTT.setMove(_player.getToken());
					TTT.drawBoard();
					if (TTT.chkWin(_player.getToken())) { _gameState = ShowingMenu; return; }

					break;
				}
				continue;
			}
		}
	}
}
// Had to be initialized outside of class for some reason...
Game::GameState Game::_gameState = Uninitialized;
