#pragma once
#include "Player.h"
class Master :
	public Player
{
private:

	int Num_Words;
	bool active;

public:

	Master();
	~Master();
	void setNum_Words(int n) { Num_Words = n; };
	int getNum_Words(void) { return Num_Words; };

};

