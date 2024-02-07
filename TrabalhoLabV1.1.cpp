//Trabalho realizado por: António Costa 70737 e Vasco Teixeira 72314	

#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Point.h"
#include <stdlib.h>
#include <stdio.h>
#include "Char.h"
#include "Word.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    int x=0, y=0;

    srand(time(NULL));

    int i = 0;

    string name;

    cout << "Introduza um nome:" << endl;
    getline(cin,name);
    system("cls");

    Game G(name);
    
    while ((x < 8 || x > 50) || (y < 8 || y > 50)) {

        cout << "Escolha a dimensao x e y respectivamente(MIN_8-MAX_50)" << endl;
        cin >> x;
        cin >> y;
        system("cls");
    }
    
    Board A;

    i = 0;

    while (i != 1) {

        char c;

        cout << "Escolha a dificuldade ('M' para Master e 'R' para Rookie):" << endl;
        cin >> c;


        if (c == 'M') {

            Master m;

            A.Initialize(y, x, m);

            i++;


        }
        else if (c == 'R') {

            Rookie R;

            A.Initialize(y, x, R);

            i++;

        }
        else
        {
            cout << "Introduza uma dificuldade válida" << c << endl << endl;
            Sleep(5000);
            system("cls");
        }

    }

    A.View();
    
}


