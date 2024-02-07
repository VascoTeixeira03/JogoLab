#include "Char.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#pragma warning( disable : 6031)

using namespace std;

Char::Char()
{
	Set_Ch('\0');
	Set_State(false);
	ASCII();
}

Char::Char(char c)
{

	Set_Ch(c);
	ASCII();

}

Char::~Char()
{
	Set_Ch('\0');
}

void Char::Set_State(bool ft)
{
	state = ft;
}

void Char::Rand(void)
{
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	Set_Ch(letters[rand() % 26]);
}

void Char::View()
{
	cout << " " << Get_Ch();
}

void Char::ASCII(void)
{
	ascii = int(Ch);
}
