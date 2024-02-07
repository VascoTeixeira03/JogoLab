#pragma once
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

/*Esta classe ir� especificar as palavras a utilizar. Atributos m�nimos:
Vetor de letras, Orienta��o, Estado, Ponto (localiza��o no tabuleiro).*/

class Word
{

public:

	Word(void);
	Word(string);
	Word(string, Point, bool);

	void Set_Position(Point);
	void Set_Position(int x, int y);
	Point Get_Position(void);
	void Set_Letters(string);
	string Get_Letters(void) { return Letters; };
	void SetOri(int o) { ori = o; }
	int GetOri(void) const { return ori; }
	void SetLvec(int L) { Lvector = L; }
	int GetLvec(void) const { return Lvector; }
	void Set_state(bool q) { state = q; };
	bool Get_state(void) { return state; };

	void View();


	friend istream& operator >> (istream& is, Word& w);

private:

	string Letters; //a palavra
	Point Position; //Posi��o no tabuleiro do caracter
	int ori; //Qual das 2(?) dire��es possiveis a palavra vai se formar
	int Lvector; //O comprimento da palavra (quantas letras tem)
	bool state;

};
