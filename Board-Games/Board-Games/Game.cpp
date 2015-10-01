#pragma once

#include "stdafx.h"

using namespace std;

void Game::Start()
{
	// This is universal and can be used in other programs
	_gameState = Game::ShowingMenu;

	while (!IsExiting())
	{
		gameLoop();
	}

	return;
}

int Game::getState()
{
	int state = _gameState;
	return state;
}

void Game::setState(GameState state)
{
	_gameState = state;
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
	GameBase* result = showMenu();
	result->Run();
	
	// TODO: Add something to "Play again?"
}

GameBase* Game::showMenu()
{
	Board M;
	int result{ 0 };
	while (result == 0)
	{
		M.ClearScreen();
		M.Color(M.CYAN);
		cout << "\t\t    --------------- \n";
		cout << "\t\t_-/||"; M.Color(M.RED); cout << "  X"; M.Color(M.BRT_RED); cout << " BOARD"; M.Color(M.DRK_YELLOW); cout << " X"; M.Color(M.CYAN); cout << "  || \n";
		cout << "\t\t   ||"; M.Color(M.BRT_RED); cout << "    X"; M.Color(M.BRT_CYAN); cout << " @"; M.Color(M.YELLOW); cout << " X"; M.Color(M.CYAN); cout << "    || \n";
		cout << "\t\t   ||"; M.Color(M.RED); cout << "  X"; M.Color(M.YELLOW); cout << " GAMES"; M.Color(M.DRK_YELLOW); cout << " X"; M.Color(M.CYAN); cout << "  ||/-_\n";
		cout << "\t\t    ---------------\n\n";
		M.Color(M.DEFAULT);

		cout << "1. Connect Four\n";
		cout << "2. Tic Tac Toe\n";
		cout << "3. Exit\n\n";
		cin >> result;
		
		switch (result)
		{
		case 1:
			_gameState = Game::Playing;
			return new ConnectFour();

		case 2:
			_gameState = Game::Playing;
			return new TicTacToe(); 

		case 3: 
			_gameState = Game::Exiting; 
			return new Game();

		default: continue;
		}
	}
}

int Game::Run()
{
	Game::close();
	return 0;
}

void Game::close()
{
	// just to throw an error
	if (_gameState == Uninitialized) { cout << "/t !! Nothing was evaluated in start() !!"; }

	_gameState = Exiting;
	cout << "\t !! Thanks for Playing !! ";

	cin.get();
	return;
}

