#include "Word.h"
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

Word::Word(void)
{

	Set_Letters("0");
	Position.SetX(0);
	Position.SetY(0);
	Set_state(false);

}

Word::Word(string Ph)
{

	Set_Letters(Ph);
	Position.SetX(0);
	Position.SetY(0);
	Set_state(false);
}

Word::Word(string Ph, Point p, bool s)
{

	Set_Letters(Ph);
	Set_Position(p);
	Set_state(s);
}

void Word::Set_Position(Point p)
{

	Position = p;

}

void Word::Set_Position(int x, int y)
{
	Position.SetX(x);
	Position.SetY(y);
}

Point Word::Get_Position(void)
{

	return Position;

}

void Word::Set_Letters(string Ph)
{

	Letters = Ph;

}

void Word::View()
{
	cout << "Palavra: " << Letters << endl;
	cout << "X: " << Get_Position().GetX() << endl;
	cout << "Y: " << Get_Position().GetY() << endl;


}

istream& operator >> (istream& is, Word& w)
{
	getline(is, w.Letters);

	return is;
}
