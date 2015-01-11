#pragma once 
#include "GameBase.h"
#include "ConnectFour.h"

class Game :
	public GameBase
{
public:
	void Start();
	
	enum GameState { Uninitialized, ShowingMenu, Playing, Exiting, Single, Multi };
	GameState _gameState;
	GameState _mode;
	int Run();
	
private:
	void gameLoop();
	GameBase* showMenu();
	bool IsExiting();
	void close();
};