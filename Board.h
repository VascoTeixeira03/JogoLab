#pragma once
#include <iostream>
#include "Word.h"
#include "Char.h"
#include "Point.h"
#include "Master.h"
#include "Rookie.h"

using namespace std;


class Board
{

private:

	int DimX;
	int DimY;
	Char** ch;
	Word* Words;
	int N_Words;
	Word* M_Words;
	Master M;
	Rookie R;

public:

	Board();
	~Board();

	int Get_Nwords(void) { return N_Words; };
	Word Get_Mwords(void) { return*M_Words; };
	Word Get_Mword(int x) { return M_Words[x]; };

	void Initialize(int x, int y, Rookie R);
	void Initialize(int x, int y, Master m);
	void View(void) const;
	void view_Word(int w);
	bool Check(int x, int y, int L, int r, int case1);
	void WriteWord(int x, int y, int L, int r, int case1);

	void setDimX(int x) { DimX = x; };
	void setDimY(int y) { DimY = y; };

};
