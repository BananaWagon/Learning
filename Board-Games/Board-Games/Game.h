#pragma once 
#include "GameBase.h"
#include "ConnectFour.h"

class Game
{
public:
	void Start();

	enum GameState { Uninitialized, ShowingMenu, Playing, Exiting, Single, Multi };
	GameState _gameState;
	GameState _mode;

private:
	void gameLoop();
	GameBase* showMenu();
	bool IsExiting();
	void close();
	void TicTacToe();
};