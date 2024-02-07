#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{
private:

	string name;
	int age;
	int lives;

public:

	Player();
	Player(string n, int a);
	~Player();

	void Setname(string n) { name = n; };
	string Getname(void) { return name; };
	void Setage(int a) { age = a; };
	int Getage(void) { return age; };

};
