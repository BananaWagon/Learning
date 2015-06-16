#pragma once

class Player : 
	public Board
{
public:
	Player();

	enum state { Player1, Player2, Uninitialized};
	Player::state _playerState = Uninitialized;
	void setState();
	void whosTurn();
	std::string getToken(int);
	int getMove();
	char chkMove();
	
	~Player();

private:
	std::string playerToken;
	



};
