//Backgammon Final Project
//Class: Obj Orient Pgm w/C++
//Programmed by: Kyle Opland
//Date: 6/9/14
//dice.h file
#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class dice
{
public:
	dice(void);
	~dice(void);
	int rollDice();
	//Purpose:
	//	Rolls dice for a number between 1 and 6
	//Precondition:
	//	Requires <ctime> library to add more randomness to the rolls.
	//Postcondition:
	//	Returns the the random roll as an int between 1 and 6
	int getDice();
	//Purpose:
	//	Retrieves the stored value of the die.
	//Precondition:
	//	The function rollDice() needs to have already been called.
	//Postcondition:
	//	Returns an int value between 1 and 6
	void printDice();
	//Purpose:
	//	Prints te value of the die to screen
	//Precondition:
	//	The function rollDice() needs to have already been called.
	//Postcondition:
	//	Prints variable roll to the screen.

private:
	int roll;	//variable to store dice roll
};
