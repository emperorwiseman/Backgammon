//Backgammon Final Project
//Class: Obj Orient Pgm w/C++
//Programmed by: Kyle Opland
//Date: 6/9/14
//row.cpp file
#include "row.h"

row::row(void)
{
	numOfBlack = 0;
	numOfWhite = 0;
	
}

row::~row(void)
{
}

int row::getNumOfBlacks()
{
	return numOfBlack;
}

int row::getNumOfWhites()
{
	return numOfWhite;
}

void row::printRow()
{
	for(int i = 0; i < 6; i++)
	{
		cout << list[i];
	}
}

void row::updateRowSub(int l, int r)
{

	int index = l  - 1; // amount of pieces
	if (r < 12)//checks what side of the board the row is on.
	{
		list[index] = '>';
	}
	else 
	{
		switch (index)
		{
			case 0:
				list[5] = '<';
				break;
			case 1:
				list[4] = '<';
				break;
			case 2:
				list[3] = '<';
				break;
			case 3:
				list[2] = '<';
				break;
			case 4:
				list[1] = '<';
				break;
			case 5:
				list[0] = '<';
				break;
		}
	}
}

void row::updateRowAddWhite(int l, int r)
{
	int index = l; // amount of pieces
	if (r < 12)
	{
		list[index] = 'W';
	}
	else 
	{
		switch (index)
		{
			case 0:
				list[5] = 'W';
				break;
			case 1:
				list[4] = 'W';
				break;
			case 2:
				list[3] = 'W';
				break;
			case 3:
				list[2] = 'W';
				break;
			case 4:
				list[1] = 'W';
				break;
			case 5:
				list[0] = 'W';
				break;
		}
	}
}

void row::updateRowAddBlack(int l, int r)
{
	int index = l; // amount fo pieces
	if (r < 12)
	{
		list[index] = 'B';
	}
	else 
	{
		switch (index)
		{
			case 0:
				list[5] = 'B';
				break;
			case 1:
				list[4] = 'B';
				break;
			case 2:
				list[3] = 'B';
				break;
			case 3:
				list[2] = 'B';
				break;
			case 4:
				list[1] = 'B';
				break;
			case 5:
				list[0] = 'B';
				break;
		}
	}
}

void row::incrementWhite()
{
	numOfWhite++;
}

void row::incrementBlack()
{
	numOfBlack++;
}

void row::decrementWhite()
{
	numOfWhite--;
}

void row::decrementBlack()
{
	numOfBlack--;
}

void row::setRow(int x)
{
	switch (x)
	{
	case -1:
		strcpy(list, "||||||");
		break;
	case 0:
		strcpy(list, "BB>>>>");
		numOfBlack = 2;
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 6:
	case 8:
	case 9:
	case 10:
		strcpy(list, ">>>>>>");
		break;
	case 5: 
		strcpy(list, "WWWWW>");
		numOfWhite = 5;
		break;
	case 7:
		strcpy(list, "WWW>>>");
		numOfWhite = 3;
		break;
	case 11:
		strcpy(list, "BBBBB>");
		numOfBlack = 5;
		break;	
	case 12:
		strcpy(list, "<WWWWW");
		numOfWhite = 5;
		break;
	case 13:
	case 14:
	case 15:
	case 17:
	case 20:
	case 19:
	case 21:
	case 22:
		strcpy(list, "<<<<<<");
		break;
	case 16:
		strcpy(list, "<<<BBB");
		numOfBlack = 3;
		break;
	case 18:
		strcpy(list, "<BBBBB");
		numOfBlack = 5;
		break;
	case 23:
		strcpy(list, "<<<<WW");
		numOfWhite = 2;
		break;
	case 24:
		strcpy(list, "||||||");
		break;
	//case 32: home rows if needed
		//
	}
}
