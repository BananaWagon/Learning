#pragma once 

#include "stdafx.h"

Player::Player()
{	
	ipos[100][100] = { 0 };
	playerToken = " ";
}

void Player::setState()
{
	// checks player state and sets to opposite player

	switch (_playerState)
	{
	case Uninitialized: _playerState = Player1; break;
	case Player1:		_playerState = Player2; break;
	case Player2:		_playerState = Player1; break;
	}
	
};

void Player::whosTurn()
{
	switch (_playerState)
	{
	case Player1: std::cout << "Player X move: "; break;
	case Player2: std::cout << "Player O move: "; break;
	}
}

std::string Player::getToken(int player)
{
	switch (player){
	
	case 0: playerToken = "X"; return playerToken;
	case 1: playerToken = "O"; return playerToken;
	}
	return "?";
}

int Player::getMove()
{
	char move {' '};
	
	std::cin >> move;

	switch (move){
	
	case '1': Board::setRow(0); Board::setCol(0); return 0;
	case '2': Board::setRow(0); Board::setCol(1); return 1;
	case '3': Board::setRow(0); Board::setCol(2); return 2;
	case '4': Board::setRow(1); Board::setCol(0); return 3;
	case '5': Board::setRow(1); Board::setCol(1); return 4;
	case '6': Board::setRow(1); Board::setCol(2); return 5;
	case '7': Board::setRow(2); Board::setCol(0); return 6;
	case '8': Board::setRow(2); Board::setCol(1); return 7;
	case '9': Board::setRow(2); Board::setCol(2); return 8;
	default: if (move > 9){ std::cout << "!!Not a valid choice...\n"; };
	}
	
	return 42;
}

Player::~Player()
{

}
