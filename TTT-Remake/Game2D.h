//#pragma once
//// Split classes into seperate files. Can use them later for another project. 
//using namespace std;
//
//class Board
//{
//public:
//	Board();
//	static int getRow(int);
//	static int getCol(int);
//	void setSize(int, int);
//	void drawBoard();
//	void printArray(int, int);
//	void setMove(string, int);
//	bool chkMove(int move);
//	
//	string pos[100][100];
//
//	~Board();
//	
//private:
//	int nRow;
//	int nCol;
//	static int ipos[100][100];
//};

//class Player: private Board
//{
//public:
//	Player();
//	int getMove();
//	enum state {Uninitialized, PlayerX, PlayerO };
//	Player::state setState(state);
//	int move;
//	~Player();
//
//protected:
//	
//	//int move;
//	char playerX;
//	char playerO;
//};

//class Game: public Board
//{
//public:
//	static void Start();
//
//private:
//	static void gameLoop();
//	static void showMenu();
//	static bool IsExiting();
//	static void close();
//	static void TicTacToe();
//
//	enum GameState { Uninitialized, ShowingMenu, Playing, Exiting};
//	static GameState _gameState;
//
//};
