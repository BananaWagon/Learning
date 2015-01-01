#pragma once


class Player : public Board
{
	//friend class Board;
public:
	Player();

	enum state { Player1, Player2 };
	Player::state _playerState = Player1;
	void setState();
	void whosTurn();
	std::string getToken(int);
	int getMove();
	char chkMove();
	
	~Player();

private:
	std::string playerToken;
	



};
