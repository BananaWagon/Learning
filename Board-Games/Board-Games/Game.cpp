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

	// Moved Close() to showingMenu().
	// result->Run() had no function to call therfor threw and error. 

	return;
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

