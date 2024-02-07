#pragma once
#include <iostream>
#include "Point.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


/*Esta classe irá especificar as letras a utilizar. Atributos mínimos: Letra,
Ponto(localização no tabuleiro), Código ASCII, Tipo(maiúscula ou minúscula).*/

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
