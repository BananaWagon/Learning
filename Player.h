#pragma once

class Player : private Board
{
public:
	Player();

	enum state { Uninitialized, PlayerX, PlayerO };
	Player::state _playerState = Uninitialized;
	void setState();
	void whosTurn();
	std::string getToken();
	
	
	~Player();

private:
	std::string playerToken;
	

protected:

};
