#include "Game.h"

Game::Game(string name, int x, int y, Rookie R)
{
	GamePlayer = name;
	board.Initialize(x, y,R);
}

Game::Game(string name, int x, int y, Master m)
{
	GamePlayer = name;
	board.Initialize(x, y, m);
}

Game::~Game()
{
}

int Game::Play(void) //PRIMEIRA JOGADA
{
	string answer;

	cout << "Digite uma palavra: ";
	getline(cin, answer);

	FindWords(answer);

	return board.Get_Nwords() - score.GetScore();
}

void Game::Run(void)
{

	while (board.Get_Nwords() > score.GetScore())
	{

		//LIMPA ECRÃ
		system("cls");

		//Nº PALAVRAS DESCOBERTAS
		cout << score.GetScore() << endl;

		//VIEW MATRIX
		board.View();

		//CHAMA PLAY
		Play();

	}

}

void Game::FindWords(string word)
{
	int q=0;

	for (int i = 0; i < board.Get_Nwords(); i++)
	{
		if (word == board.Get_Mword(i).Get_Letters() && board.Get_Mword(i).Get_state() == false)
		{

			score.SetScore(score.GetScore() + 1);
			board.Get_Mword(i).Set_state(true);
			cout << "A palavra " << word << "está certa!" << endl;
			q++;

		}

	}

	if (q == 0) {

		cout << "A palavra " << word << "está errada!" << endl;

	}

}


