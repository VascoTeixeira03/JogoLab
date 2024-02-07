#pragma once
#include "Player.h"
class Rookie :
	public Player
{
private:

	int Num_Words;
	bool active;

public:

	Rookie();
	~Rookie();
	void setNum_Words(int n) { Num_Words = n; };
	int getNum_Words(void) { return Num_Words; };

};

