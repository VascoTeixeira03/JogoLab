#pragma once
#include "Board.h"
#include "Player.h"
#include "Score.h"
#include "Rookie.h"
#include "Master.h"

using namespace std;

class Game
{

private:

	Board board;
	Player player;
	string GamePlayer;
	Score score;

public:

	Game(string name, int x, int y, Rookie R);
	Game(string name, int x, int y, Master m);
	Game(string name) { GamePlayer = name; };
	~Game();

	int Play(void);
	void Run(void);
	void FindWords(string word);
	void SaveFile();
	void LoadFile();

};

