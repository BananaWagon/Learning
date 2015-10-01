#pragma once
#include "Game.h"

class Player :
	public Board
{
	Game Current;

public:
	Player();

	enum state { Player1, Player2, Uninitialized};
	Player::state _playerState;
	void		setState(int state = Uninitialized);
	void		whosTurn();
	std::string getToken(int);
	int			getMove();
	//char chkMove();
	
	~Player();

private:
	std::string playerToken;
	



};
