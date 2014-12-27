#pragma once 

class Game : public Board
{
public:
	static void Start();

private:
	static void gameLoop();
	static void showMenu();
	static bool IsExiting();
	static void close();
	static void TicTacToe();

	enum GameState { Uninitialized, ShowingMenu, Playing, Exiting };
	static GameState _gameState;

};