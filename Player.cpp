#pragma once 

#include "stdafx.h"

Player::Player()
{

}

void Player::setState()
{
	// checks player state and sets to opposite player

	switch (_playerState)
	{
	case Uninitialized: _playerState = PlayerX; break;
	case PlayerX:		_playerState = PlayerO; break;
	case PlayerO:		_playerState = PlayerX; break;
	}
	
};

void Player::whosTurn()
{
	switch (_playerState)
	{
	case PlayerX: std::cout << "Player X move: "; break;
	case PlayerO: std::cout << "Player O move: "; break;
	}
}

std::string Player::getToken()
{
	switch (_playerState){
	
	case PlayerX: return playerToken = "X";
	case PlayerO: return playerToken = "O";
	}
	
}

Player::~Player()
{

}
