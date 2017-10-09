//Backgammon Final Project
//Class: Obj Orient Pgm w/C++
//Programmed by: Kyle Opland
//Date: 6/9/14
//dice.cpp file
#include "dice.h"
#include <iostream>

dice::dice(void)
{
}

dice::~dice(void)
{
}

int dice::rollDice()    //https://www.youtube.com/watch?v=naXUIEAIt4U&list=PLAE85DE8440AA6B83&index=28
{
	srand(rand() + time(0));

	roll = 1+(rand()%6);

	return roll;
}

int dice::getDice()
{
	return roll;
}

void dice::printDice()
{
	cout << roll;
}