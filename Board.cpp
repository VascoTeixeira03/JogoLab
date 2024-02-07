#include "Board.h"
#include "Word.h"
#include "Point.h"
#include <time.h>
#include <fstream>
#include <string>
#include <iostream>
#include <ctype.h>
#include "Rookie.h"
#include "Master.h"

using namespace std;


Board::Board()
{

	setDimX(0); setDimY(0);
	ch = NULL;
	Words = NULL;
	N_Words = 0;

}

Board::~Board()
{

	delete ch, Words, M_Words;

}

void Board::Initialize(int x, int y, Rookie R)
{

	int i = 0, j = 0;
	setDimX(x);
	setDimY(y);

	ch = (Char**) new Char * [DimY];

	for (int i = 0; i < DimY; i++)
	{
		ch[i] = (Char*) new Char[DimX];
	}

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			ch[i][j].Rand();
			ch[i][j].Set_State(false);
		}
	}

	ifstream is;

	is.open("Words.txt");

	if (!is)
	{
		cout << "Erro ao abrir o ficheiro" << endl;
		exit(0);
	}

	string aux;
	int r1, r, r2, l, DimWX, DimWY;

	is.clear();
	is.ignore(numeric_limits<streamsize>::max(), '\n');

	Words = (Word*) new Word[120];

	for (i = 0; i < 117; i++)
	{
		getline(is, aux);
		Words[i].Set_Letters(aux);

	}

	is.close();

	r1 = rand() % 3 + 4; //Nº PALAVRAS NA MATRIZ ENTRE 8 E 12



	int n = 0; //PALAVRAS COMPLETAS

	M_Words = (Word*) new Word[r1];

	while (r1 > n) // r1
	{
		r = rand() % 117; //PALAVRA ALEATÓRIA
		Words[r].SetOri(rand() % 8); //HORIZONTAL VERTICAL OU DIAGONAL
	
		switch (Words[r].GetOri())
		{
		case 0: //VERTICAL

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();

			if (DimWX > 0 && Words[r].Get_state() == false)
			{
				int joa, quim;

				joa = rand() % DimWX;
				quim = rand() % DimY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa,quim,L,r,Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
					cout << Words[r].Get_Letters() << " ";
					cout << n << " " << r1 << endl;
				}

			}

			break;

		case 1: //VERTICAL CONTRÁRIO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();

			if (DimWX > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimWX + Words[r].GetLvec();
				quim = rand() % DimY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
					cout << Words[r].Get_Letters() << " ";
					cout << n << " " << r1 << endl;
				}
			}

			break;

		case 2: //HORIZONTAL

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWY = DimY - Words[r].GetLvec();

			if (DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimX;
				quim = rand() % DimWY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
					cout << Words[r].Get_Letters() << " ";
					cout << n << " " << r1 << endl;
				}
			}
			
			break;

		case 3: //HORIZONTAL CONTRÁRIO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWY = DimY - Words[r].GetLvec();

			if (DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimX;
				quim = rand() % DimWY + Words[r].GetLvec();;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
					cout << Words[r].Get_Letters() << " ";
					cout << n << " " << r1 << endl;
				}

			}
			
			break;

		case 4: //DIAGONAL CIMA PARA BAIXO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();
			DimWY = DimY - Words[r].GetLvec();

			if (DimWX > 0 && DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimWX;
				quim = rand() % DimWY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
					cout << Words[r].Get_Letters() << " ";
					cout << n << " " << r1 << endl;
				}

			}
		
			break;

		case 5: //DIAGONAL BAIXO PARA CIMA

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();
			DimWY = DimY - Words[r].GetLvec();

			if (DimWX > 0 && DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimWX + Words[r].GetLvec();
				quim = rand() % DimWY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
					cout << Words[r].Get_Letters() << " ";
					cout << n << " " << r1 << endl;
				}

			}

			break;

		case 6: //DIAGONAL CIMA PARA BAIXO CONTRÁRIO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();
			DimWY = DimY - Words[r].GetLvec();

			if (DimWX > 0 && DimWY > 0)
			{

				int joa, quim;

				joa = rand() % DimWX + Words[r].GetLvec();
				quim = rand() % DimWY + Words[r].GetLvec();
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
					cout << Words[r].Get_Letters() << " ";
					cout << n << " " << r1 << endl;
				}
			}
				break;
		case 7: //DIAGONAL BAIXO PARA CIMA CONTRÁRIO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();
			DimWY = DimY - Words[r].GetLvec();

			if (DimWX > 0 && DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimWX;
				quim = rand() % DimWY + Words[r].GetLvec();;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
					cout << Words[r].Get_Letters() << " ";
					cout << n << " " << r1 << endl;
				}

			}

			break;

		default:

			break;

		}

	}

}

void Board::Initialize(int x, int y, Master m)
{

	int i = 0, j = 0;
	setDimX(x);
	setDimY(y);

	ch = (Char**) new Char * [DimY];

	for (int i = 0; i < DimY; i++)
	{
		ch[i] = (Char*) new Char[DimX];
	}

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			ch[i][j].Rand();
			ch[i][j].Set_State(false);
		}
	}

	ifstream is;

	is.open("Words.txt");

	if (!is)
	{
		cout << "Erro ao abrir o ficheiro" << endl;
		exit(0);
	}

	string aux;
	int r1, r, r2, l, DimWX, DimWY;

	is.clear();
	is.ignore(numeric_limits<streamsize>::max(), '\n');

	Words = (Word*) new Word[120];

	for (i = 0; i < 117; i++)
	{
		getline(is, aux);
		Words[i].Set_Letters(aux);

	}

	is.close();

	r1 = rand() % 5 + 8; //Nº PALAVRAS MATRIX ENTRE 8 E 12 



	int n = 0; //Nº PALAVRAS COMPLETAS

	M_Words = (Word*) new Word[r1];

	while (r1 > n)
	{
		r = rand() % 117; //PALAVRA ALEATÓRIA
		Words[r].SetOri(rand() % 8); //HORIZONTAL VERTICAL OU DIAGONAL, em todas as opcoes frente ou tras

		switch (Words[r].GetOri())
		{
		case 0: //VERTICAL 

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();

			if (DimWX > 0 && Words[r].Get_state() == false)
			{
				int joa, quim;

				joa = rand() % DimWX;
				quim = rand() % DimY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;
				}

			}

			break;

		case 1: //VERTICAL CONTRÁRIO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();

			if (DimWX > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimWX + Words[r].GetLvec();
				quim = rand() % DimY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;

				}
			}

			break;

		case 2: //HORIZONTAL


			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWY = DimY - Words[r].GetLvec();

			if (DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimX;
				quim = rand() % DimWY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;

				}
			}

			break;

		case 3: //HORIZONTAL CONTRÁRIO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWY = DimY - Words[r].GetLvec();

			if (DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimX;
				quim = rand() % DimWY + Words[r].GetLvec();;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true)//VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;

				}

			}

			break;

		case 4: //DIAGONAL CIMA PARA BAIXO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();
			DimWY = DimY - Words[r].GetLvec();

			if (DimWX > 0 && DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimWX;
				quim = rand() % DimWY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true)//VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;

				}

			}

			break;

		case 5: //DIAGONAL BAIXO PARA CIMA

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();
			DimWY = DimY - Words[r].GetLvec();

			if (DimWX > 0 && DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimWX + Words[r].GetLvec();
				quim = rand() % DimWY;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) // Vê se a palavra é valida ou não
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;

				}

			}

			break;

		case 6: // DIAGONAL CIMA PARA BAIXO CONTRÁRIO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();
			DimWY = DimY - Words[r].GetLvec();

			if (DimWX > 0 && DimWY > 0)
			{

				int joa, quim;

				joa = rand() % DimWX + Words[r].GetLvec();
				quim = rand() % DimWY + Words[r].GetLvec();
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;

				}
			}
			break;
		case 7: //DIAGONAL BAIXO PARA CIMA CONTRÁRIO

			Words[r].SetLvec(Words[r].Get_Letters().length());

			DimWX = DimX - Words[r].GetLvec();
			DimWY = DimY - Words[r].GetLvec();

			if (DimWX > 0 && DimWY > 0 && Words[r].Get_state() == false)
			{

				int joa, quim;

				joa = rand() % DimWX;
				quim = rand() % DimWY + Words[r].GetLvec();;
				Words[r].Set_Position(joa, quim);
				int L = Words[r].GetLvec();

				if (Check(joa, quim, L, r, Words[r].GetOri()) == true) //VERIFICA A PALAVRA (VÁLIDA OU INVÁLIDA)
				{

					WriteWord(joa, quim, L, r, Words[r].GetOri());

					M_Words[n] = Words[r];
					n++;
					N_Words++;

				}

			}

			break;

		default:

			break;

		}

	}

}

void Board::View() const
{
	int i, j;
	for (i = 0; i < DimX; i++)
	{
		for (j = 0; j < DimY; j++)
		{
			if (ch[i][j].Get_State() == true) ch[i][j].View();
			else cout << " '";
		}
		cout << endl;
	}

}

void Board::view_Word(int w)
{

	for (int i = 0; i < w; i++)
	{
		cout << M_Words[i].Get_Letters() << endl;
	}

}

bool Board::Check(int x, int y, int L, int r, int case1)
{
	int aux1 = 0;

	switch (case1)
	{
	case 0: //VERTICAL

		for (int i = 0; i < L; i++)
		{
			if ((ch[x + i][y].Get_State() == false) || (ch[x + i][y].Get_State() == true && ch[x + i][y].Get_Ch() == Words[r].Get_Letters()[i]))
			{

				aux1++;

			}
		}
		break;

	case 1: //VERTICAL CONTRÁRIO

		for (int i = 0; i < L; i++)
		{
			if ((ch[x - i][y].Get_State() == false) || (ch[x - i][y].Get_State() == true && ch[x - i][y].Get_Ch() == Words[r].Get_Letters()[i]))
			{

				aux1++;

			}
		}
		break;

	case 2: //HORIZONTAL 

		for (int i = 0; i < L; i++)
		{
			if ((ch[x][y + i].Get_State() == false) || (ch[x][y + i].Get_State() == true && ch[x][y + i].Get_Ch() == Words[r].Get_Letters()[i]))
			{

				aux1++;

			}
		}
		break;

	case 3: //HORIZONTAL CONTRÁRIO

		for (int i = 0; i < L; i++)
		{
			if ((ch[x][y - i].Get_State() == false) || (ch[x][y - i].Get_State() == true && ch[x][y - i].Get_Ch() == Words[r].Get_Letters()[i]))
			{

				aux1++;

			}
		}
		break;

	case 4: //DIAGONAL CIMA PARA BAIXO

		for (int i = 0; i < L; i++)
		{
			if ((ch[x + i][y + i].Get_State() == false) || (ch[x + i][y + i].Get_State() == true && ch[x + i][y + i].Get_Ch() == Words[r].Get_Letters()[i]))
			{

				aux1++;

			}
		}
		break;

	case 5: //DIAGONAL BAIXO PARA CIMA

		for (int i = 0; i < L; i++)
		{
			if ((ch[x - i][y + i].Get_State() == false) || (ch[x - i][y + i].Get_State() == true && ch[x - i][y + i].Get_Ch() == Words[r].Get_Letters()[i]))
			{

				aux1++;

			}
		}
		break;

	case 6: //DIAGONAL CIMA PARA BAIXO CONTRÁRIO

		for (int i = 0; i < L; i++)
		{
			if ((ch[x - i][y - i].Get_State() == false) || (ch[x - i][y - i].Get_State() == true && ch[x - i][y - i].Get_Ch() == Words[r].Get_Letters()[i]))
			{

				aux1++;

			}
		}
		break;

	case 7: //DIAGONAL BAIXO PARA CIMA CONTRÁRIO

		for (int i = 0; i < L; i++)
		{
			if ((ch[x + i][y - i].Get_State() == false) || (ch[x + i][y - i].Get_State() == true && ch[x + i][y - i].Get_Ch() == Words[r].Get_Letters()[i]))
			{

				aux1++;

			}
		}
		break;
	}

	if (L == aux1) return true;
	else return false;
}

void Board::WriteWord(int x, int y, int L, int r, int case1)
{

	switch (case1)
	{

	case 0: //VERTICAL NORMAL

		for (int i = 0; i < L; i++)
		{
			ch[x + i][y] = tolower(Words[r].Get_Letters()[i]);
			ch[x + i][y].Set_State(true);
		}
		Words[r].Set_state(true);

		break;

	case 1: // VERTICAL CONTRÁRIO

		for (int i = 0; i < L; i++)
		{
			ch[x - i][y] = tolower(Words[r].Get_Letters()[i]);
			ch[x - i][y].Set_State(true);
		}
		Words[r].Set_state(true);

		break;

	case 2: // HORIZONTAL NORMAL

		for (int i = 0; i < L; i++)
		{
			ch[x][y + i] = tolower(Words[r].Get_Letters()[i]);
			ch[x][y + i].Set_State(true);
		}
		Words[r].Set_state(true);

		break;

	case 3: // HORIZONTAL CONTRÁRIO

		for (int i = 0; i < L; i++)
		{
			ch[x][y - i] = tolower(Words[r].Get_Letters()[i]);
			ch[x][y - i].Set_State(true);
		}
		Words[r].Set_state(true);

		break;

	case 4: // DIAGONAL CIMA PARA BAIXO

		for (int i = 0; i < L; i++)
		{
			ch[x + i][y + i] = tolower(Words[r].Get_Letters()[i]);
			ch[x + i][y + i].Set_State(true);
		}
		Words[r].Set_state(true);

		break;

	case 5: // DIAGONAL BAIXO PARA CIMA

		for (int i = 0; i < L; i++)
		{
			ch[x - i][y + i] = tolower(Words[r].Get_Letters()[i]);
			ch[x - i][y + i].Set_State(true);
		}
		Words[r].Set_state(true);

		break;

	case 6: // DIAGONAL CIMA PARA BAIXO CONTRÁRIO

		for (int i = 0; i < L; i++)
		{
			ch[x - i][y - i] = tolower(Words[r].Get_Letters()[i]);
			ch[x - i][y - i].Set_State(true);
		}
		Words[r].Set_state(true);

		break;

	case 7: // DIAGONAL BAIXO PARA CIMA CONTRÁRIO

		for (int i = 0; i < L; i++)
		{
			ch[x + i][y - i] = tolower(Words[r].Get_Letters()[i]);
			ch[x + i][y - i].Set_State(true);
		}
		Words[r].Set_state(true);

		break;

	}

}

