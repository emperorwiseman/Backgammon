//Backgammon Final Project
//Class: Obj Orient Pgm w/C++
//Programmed by: Kyle Opland
//Date: 6/9/14
//row.h file
#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class row
{
public:
	int getNumOfWhites();
	//Purpose:
	//	To find out the number of whites currently in the row.
	//Precondition:
	//	None
	//Postcondition:
	//	Returns number of white pieces as an integer.
	int getNumOfBlacks();
	//Purpose:
	//	To find out the number of whites currently in the row.
	//Precondition:
	//	None
	//Postcondition:
	//	Returns number of black pieces as an integer.
	void updateRowSub(int l, int r);
	//Purpose:
	//	To visually update the removal of a piece from a row.
	//Precondition:
	//	A white or black piece needs to be moved from the row. Number of current pieces and the number of the row are required.
	//Postcondition:
	//	The position of the moved piece is replaced with a < or > as position requires.
	void updateRowAddWhite(int l, int r);
	//Purpose:
	//	To visually update the addition of a white piece to a row.
	//Precondition:
	//	A white piece needs to be moved to the row. Number of current pieces and the number of the row are required.
	//Postcondition:
	//	A W is added to the row in the appropriate position based on how many are currently there.
	void updateRowAddBlack(int l, int r);
	//Purpose:
	//	To visually update the addition of a black piece to a row.
	//Precondition:
	//	A black piece needs to be moved to the row. Number of current pieces and the number of the row are required.
	//Postcondition:
	//	A B is added to the row in the appropriate position based on how many are currently there.
	void incrementWhite();
	//Purpose:
	//	Increments the number of white pieces in the row by 1.
	//Precondition:
	//	A piece needs to be moved to a new row for it to be called.
	//Postcondition:
	//	The variable numOfWhite is increased by 1.
	void incrementBlack();
	//Purpose:
	//	Increments the number of black pieces in the row by 1.
	//Precondition:
	//	A piece needs to be moved to a new row for it to be called.
	//Postcondition:
	//	The variable numOfBlack is increased by 1.
	void decrementBlack();
	//Purpose:
	//	Decrements the number of black pieces in the row by 1.
	//Precondition:
	//	A piece needs to be moved to a new row for it to be called.
	//Postcondition:
	//	The variable numOfBlack is decreased by 1.
	void decrementWhite();
	//Purpose:
	//	Decrements the number of white pieces in the row by 1.
	//Precondition:
	//	A piece needs to be moved to a new row for it to be called.
	//Postcondition:
	//	The variable numOfWhite is decreased by 1.
	void setRow(int x);
	//Purpose:
	//	Sets up the necessary initial contents of the rows to form the starting gameboard.
	//Precondition:
	//	The row's numbered position on the board needs to be passed to it.
	//Postcondition:
	//	Rows are properly assigned based on their labeled position on the game board.
	void printRow();
	//Purpose:
	//	To print out the row on screen.
	//Precondition:
	//	None
	//Postcondition:
	//	Contents of the array are outputted to screen.
	row(void);			//default constructor
						//Sets number of black and white pieces to zero to start with.
	~row(void);

private:
	int numOfBlack;		//Stores number of black pieces on a row.
	int numOfWhite;		//Stores number of white pieces on a row.
	char list[6];		//array to store pieces or blank spaces.
};
