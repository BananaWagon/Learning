//#include "stdafx.h"
//#include "Game2D.h"
//
//using namespace std;

//Board::Board()
//{
//	
//	Board::nRow = {0};
//	Board::nCol = {0};
//
//}
//
//void Board::setSize(int nRow, int nCol)
//{	
//	// initializes the array to user defined size up to 300 x 300
//	// may use this idea for drawBoard() as well
//	int p_i { 0 };
//	for (int i = 0; i < nRow; i++)
//	{
//		for (int j = 0; j < nCol; j++)
//		{	
//			++p_i; /* put p_i in place of ' ' to initialize in a sequential manner. 
//				    has a problem at 127, it moves to -127 and if printed you get
//				    random characters. char can only take single char if initialized to literal 1 / 9
//					and not anything higher than that.*/
//			pos[i][j] = " ";
//			
//		}
//	}
//}
//
//int Board::getRow(int nRow)
//{
//	return nRow;
//}
//
//int Board::getCol(int nCol)
//{
//	return nCol;
//}
//
//void Board::drawBoard()
//{
//	ClearScreen();
//
//	char index[3][3]	{ {'1', '2', '3'},
//						  {'4', '5', '6'},
//						  {'7', '8', '9'} };
//	
//	// Chose to use a visual index. Made the board look cleaner.
//
//	// ToDo: Make this universal. Drawing user defined board size. 
//	//		 May need to use a for loops to implement. 
//	cout << "      board index\n";
//	cout << "\n     " << index[0][0] << "  |  " << index[0][1] << "  |  " << index[0][2] << "  \n";
//	cout << "\n     " << index[1][0] << "  |  " << index[1][1] << "  |  " << index[1][2] << "  \n";
//	cout << "\n     " << index[2][0] << "  |  " << index[2][1] << "  |  " << index[2][2] << "  \n";
//
//	cout << "\t\t        |     |     \n";
//	cout << "\t\t     " << Board::pos[0][0] << "  |  " << Board::pos[0][1] << "  |  " << Board::pos[0][2] << "  \n";
//	cout << "\t\t   _____|_____|_____\n";
//	cout << "\t\t        |     |     \n";
//	cout << "\t\t     " << Board::pos[1][0] << "  |  " << Board::pos[1][1] << "  |  " << Board::pos[1][2] << "  \n";
//	cout << "\t\t   _____|_____|_____\n";
//	cout << "\t\t        |     |     \n";
//	cout << "\t\t     " << Board::pos[2][0] << "  |  " << Board::pos[2][1] << "  |  " << Board::pos[2][2] << "  \n";
//	cout << "\t\t        |     |     \n\n";
//}
//
//void Board::printArray(int nRow, int nCol)
//{
//	// tests initialized values for array. Far from polished...
//
//	for (int i = 0; i < nRow; i++)
//	{
//
//		for (int j = 0; j < nCol; j++)
//		{
//			cout << i << " x " << j << pos[i][j] << " " << '\t';
//		}
//	}
//}
//
//void Board::setMove(string player, int move)
//{
//	switch (move){
//
//	case 1: pos[0][0] = player; break;
//	case 2: pos[0][1] = player; break;
//	case 3: pos[0][2] = player; break;
//	case 4: pos[1][0] = player; break;
//	case 5: pos[1][1] = player; break;
//	case 6: pos[1][2] = player; break;
//	case 7: pos[2][0] = player; break;
//	case 8: pos[2][1] = player; break;
//	case 9: pos[2][2] = player; break;
//	}
//}
//
//bool Board::chkMove(int move)
//{
//	// checks to see if square is blank. If it is anything else then  
//	// the loop for getting player input will continue and array will
//	// not be changed. This can be applied in the same way for chess... I think.
//
//	if (move == 1 && pos[0][0] == " "){ return true; }
//	else if (move == 2 && pos[0][1] == " "){ return true; }
//	else if (move == 3 && pos[0][2] == " "){ return true; }
//	else if (move == 4 && pos[1][0] == " "){ return true; }
//	else if (move == 5 && pos[1][1] == " "){ return true; }
//	else if (move == 6 && pos[1][2] == " "){ return true; }
//	else if (move == 7 && pos[2][0] == " "){ return true; }
//	else if (move == 8 && pos[2][1] == " "){ return true; }
//	else if (move == 9 && pos[2][2] == " "){ return true; }
//	
//	return false;
//}
//
//
//Board::~Board()
//{
//
//}

//Player::Player()
//{
//	playerX = 'X';
//	playerO = 'O';
//}
//
//int Player::getMove()
//{
//	char c_move;
//	
//cin >> c_move;
//	
//	switch (c_move){
//
//	case '1': move = 1; return 1;
//	case '2': move = 2; return 2;
//	case '3': move = 3; return 3;
//	case '4': move = 4; return 4;
//	case '5': move = 5; return 5;
//	case '6': move = 6; return 6;
//	case '7': move = 7; return 7;
//	case '8': move = 8; return 8;
//	case '9': move = 9; return 9;
//	}
//	return 0;
//}


//Player::state Player::setState(Player::state _gameState)
//{
//	// checks player state and sets to opposite player
//
//	switch (_gameState)
//	{
//	case Player::Uninitialized: { return PlayerX; }
//	case Player::PlayerX:		{ return PlayerO; }
//	case Player::PlayerO:		{ return PlayerX; }
//	}
//	return Uninitialized;
//};
//
//
//Player::~Player()
//{
//
//}



//void Game::Start()
//{
//	
//	if (_gameState != Uninitialized)
//	{
//		return;
//	}
//
//	// This is universal and can be used in other programs
//	_gameState = Game::ShowingMenu;
//
//	while (!IsExiting())
//	{
//		gameLoop();
//	}
//
//	close();
//}
//
//bool Game::IsExiting()
//{
//	if (_gameState == Game::Exiting)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void Game::gameLoop()
//{
//	switch (_gameState)
//	{
//		case Game::ShowingMenu: { showMenu(); break; }
//		case Game::Playing:		{ TicTacToe(); cin.get();  break; }
//	}
//	//_gameState = Exiting;   //<-- uncomment to have game auto exit.
//	//add something to show winner and prompt to "Play again?"
//}
//
//void Game::showMenu()
//{
//	int result{ 0 };
//	while (result == 0)
//	{
//		ClearScreen();
//		
//		cout << "\t\t    --------------- \n";
//		cout << "\t\t_-/||  X  TAC  X  ||\n";
//		cout << "\t\t   || TIC  O  TOE ||\n";
//		cout << "\t\t   ||  X  TAC  X  ||/-_\n";
//		cout << "\t\t    ---------------\n\n";
//
//		cout << "1. Play \n2. Exit \n";
//		cin >> result;
//		
//		switch (result)
//		{
//			case 1: _gameState = Game::Playing; break;
//			case 2: _gameState = Game::Exiting; break;
//			default: continue;
//		}
//	}
//}
//
//void Game::close()
//{	
//	// just to throw an error
//	if (_gameState == Uninitialized) { cout << "/t !! Nothing was evaluated int start() !!"; }
//	
//	cin.get();
//	return;
//}
//
//void Game::TicTacToe()
//{	
//	// Initializes array to null 3x3 to show a blank board. 
//	Board TTT;
//	TTT.setSize(3, 3);
//	TTT.drawBoard();
//
//	Player _player;
//	Player::state _playerState;
//	_playerState = Player::state::Uninitialized;
//
//	// This is the actual game loop. Total of 9 turns. 
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{	
//			//sets player state after loop back
//			_playerState = _player.setState(_playerState);
//
//			// Loop will not break unless chkMove evaluates to true
//			while (_playerState == Player::PlayerX || Player::PlayerO)
//			{
//				if (_playerState == Player::PlayerX){ cout << "Player X move: "; }
//				if (_playerState == Player::PlayerO){ cout << "Player O move: "; }
//				
//				_player.getMove();
//
//				if (TTT.chkMove(_player.move))
//				{
//					if (_playerState == Player::PlayerX){ TTT.setMove("X", _player.move); }
//					if (_playerState == Player::PlayerO){ TTT.setMove("O", _player.move); }
//					
//					TTT.drawBoard();
//					// add chkWin here
//
//					break;
//				}
//				cout << "Enter valid choice...\n"; continue;
//			}
//		}
//	}
//}
//// Had to be initialized outside of class for some reason...
//Game::GameState Game::_gameState = Uninitialized;