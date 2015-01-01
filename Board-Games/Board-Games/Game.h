#pragma once 

class Game
{
public:
	static void Start();
	

	enum GameState { Uninitialized, ShowingMenu, Playing, Exiting, Single, Multi };
	static GameState _gameState;
	static GameState _mode;

private:
	static void gameLoop();
	static  int showMenu();
	static bool IsExiting();
	static void close();
	static void C4();
	static void TicTacToe();
};