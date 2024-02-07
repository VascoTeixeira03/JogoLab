#include "Player.h"
#include <iostream>

Player::Player()
{
	name = "";
	age = 0;
}

Player::Player(string n, int a)
{
	name = n;
	age = a;

	//Setname(n);
	//Setage(a);
}

Player::~Player()
{
}

