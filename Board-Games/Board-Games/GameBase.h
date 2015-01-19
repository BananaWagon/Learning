#pragma once

class GameBase
{
public:
	GameBase();
	~GameBase();
	virtual int Run();
	virtual void drawBoard();
};

