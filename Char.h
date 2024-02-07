#pragma once
#include <iostream>
#include "Point.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


/*Esta classe ir� especificar as letras a utilizar. Atributos m�nimos: Letra,
Ponto(localiza��o no tabuleiro), C�digo ASCII, Tipo(mai�scula ou min�scula).*/

class Char
{

public:

	Char();
	Char(char c);
	~Char();

	void Set_State(bool ft);
	bool Get_State(void) const { return state; }

	void Rand(void);
	void View();
	void ASCII(void);

	void Set_Ch(char c) { Ch = c; };
	char Get_Ch(void) { return Ch; };

private:

	bool state;
	char Ch;
	bool caps;
	int ascii;

};
