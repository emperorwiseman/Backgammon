//Backgammon Final Project
//Class: Obj Orient Pgm w/C++
//Programmed by: Kyle Opland
//Date: 6/9/14
//gameBoard.cpp file
#include "gameBoard.h"

gameBoard::gameBoard(void)
{
	blackTotal = 0;
	whiteTotal = 0;

	for (int i = 0; i < 24; i++)
	{
		rows[i].setRow(i);
	}
	blackPenalty.setRow(-1);
	whitePenalty.setRow(24);
}

bool gameBoard::checkStuckWhite(int x, int y)
{
	if(rows[24-x].getNumOfBlacks() > 1 && rows[24-y].getNumOfBlacks() > 1) //Based on the dice rolls, (x and y), checks the possible moves from the bar to check if a move is possible.
	{
		return true;
	}
	else
		return false;
}

bool gameBoard::checkStuckBlack(int x, int y)
{
	if(rows[-1+x].getNumOfWhites() > 1 && rows[-1+y].getNumOfWhites() > 1)
	{
		return true;
	}
	else
		return false;
}

bool gameBoard::checkPenaltyWhite()
{
	if (whitePenalty.getNumOfWhites() > 0)
	{
		cout << "You must move your piece from the bar if possible." << endl;
		return true;
	}
	else
		return false;
}

bool gameBoard::checkPenaltyBlack()
{
	if (blackPenalty.getNumOfBlacks() > 0)
	{
		cout << "You must move your piece from the bar if possible." << endl;
		return true;
	}
	else
		return false;
}

int gameBoard::movePieceWhitePenalty(int row, int choice)
{
	int moved = choice - 1;
	int length;
	if(rows[moved].getNumOfBlacks() > 1)
	{
		cout << "Cannot move on row containing two or more opponents pieces!" << endl;
		return 1;
	}
	else if(rows[moved].getNumOfBlacks() == 1)
	{
		length = whitePenalty.getNumOfWhites();
		whitePenalty.setRow(24);
		whitePenalty.decrementWhite();

		rows[moved].decrementBlack();
		length = rows[moved].getNumOfWhites();

		rows[moved].updateRowAddWhite(length, moved); //7 and 4
		rows[moved].incrementWhite();
		blackPenalty.incrementBlack();
		blackPenalty.updateRowAddBlack(blackPenalty.getNumOfBlacks() - 1, 0); //might switch 15 to lower
		return 0;
	}

	else if(rows[moved].getNumOfWhites() == 6) // untrue rule
	{
		cout << "Invalid move. Maximum number of your pieces are on that row." << endl;
		return 1;
	}

	else
	{
		length = whitePenalty.getNumOfWhites();

		whitePenalty.setRow(24);

		whitePenalty.decrementWhite();

		length = rows[moved].getNumOfWhites();
		rows[moved].updateRowAddWhite(length, moved);
		rows[moved].incrementWhite();
		return 0;
	}
}

int gameBoard::movePieceBlackPenalty(int row, int choice)
{
	int moved = choice - 1;
	int length;
	if(rows[moved].getNumOfWhites() > 1)
	{
		cout << "Cannot move on row containing two or more opponents pieces!" << endl;
		return 1;
	}
	else if(rows[moved].getNumOfWhites() == 1)
	{
		length = blackPenalty.getNumOfBlacks();
		blackPenalty.setRow(-1);
		blackPenalty.decrementBlack();

		rows[moved].decrementWhite();
		length = rows[moved].getNumOfBlacks();

		rows[moved].updateRowAddBlack(length, moved); //7 and 4
		rows[moved].incrementBlack();
		whitePenalty.incrementWhite();
		whitePenalty.updateRowAddWhite(whitePenalty.getNumOfWhites() - 1, 15); //might switch 15 to lower
		return 0;
	}

	else if(rows[moved].getNumOfBlacks() == 6) // untrue rule
	{
		cout << "Invalid move. Maximum number of your pieces are on that row." << endl;
		return 1;
	}

	else
	{
		length = blackPenalty.getNumOfBlacks();

		blackPenalty.setRow(-1);

		blackPenalty.decrementBlack();

		length = rows[moved].getNumOfBlacks();
		rows[moved].updateRowAddBlack(length, moved);
		rows[moved].incrementBlack();
		return 0;
	}
}

int gameBoard::movePieceWhite(int x, int y)
{
	int index = x - 1;
	int moved = y - 1;
	int length;
	
	if(rows[index].getNumOfWhites() == 0)
	{
		cout << "You do not have any pieces to move in that row. Try again." << endl;
		return 1;
	}
	if(moved <= -1)
	{
		int homeSum = 0;
		int i;
		for (i = 0; i < 6; i++)
		{
			homeSum = homeSum + rows[i].getNumOfWhites();
		}
		homeSum = homeSum + whiteTotal;
		if (homeSum == 15)
		{
			whiteTotal++;
			length = rows[index].getNumOfWhites();
			rows[index].updateRowSub(length, index);
			rows[index].decrementWhite();
			return 0;	
		}
		else
		{
			cout << "All your pieces need to be on the home board to start bearing off. Try again." << endl;
			return 1;
		}
	}
	else if(rows[moved].getNumOfBlacks() > 1)
	{
		cout << "Cannot move on row containing two or more opponents pieces!" << endl;
		return 1;
	}
	else if(rows[moved].getNumOfBlacks() == 1)
	{
		length = rows[index].getNumOfWhites();
		rows[index].updateRowSub(length, index);
		rows[index].decrementWhite();

		rows[moved].decrementBlack();
		length = rows[moved].getNumOfWhites();

		rows[moved].updateRowAddWhite(length, moved); 
		rows[moved].incrementWhite();
		blackPenalty.incrementBlack();
		blackPenalty.updateRowAddBlack(blackPenalty.getNumOfBlacks() - 1, 0); //might switch 15 to lower
		return 0;
	}
	else if(rows[moved].getNumOfWhites() == 6) // untrue rule
	{
		cout << "Invalid move. Maximum number of your pieces are on that row." << endl;
		return 1;
	}
	else
	{
		length = rows[index].getNumOfWhites();

		rows[index].updateRowSub(length, index);

		rows[index].decrementWhite();

		length = rows[moved].getNumOfWhites();
		rows[moved].updateRowAddWhite(length, moved);
		rows[moved].incrementWhite();
		return 0;
	}
}

int gameBoard::movePieceBlack(int x, int y)
{
	int index = x - 1;
	int moved = y - 1;
	int length;
	//check legality
	if(rows[index].getNumOfBlacks() == 0)
	{
		cout << "You do not have any pieces to move in that row. Try again." << endl;
		return 1;
	}

	if(moved >= 24)
	{
		int homeSum = 0;
		int i;
		for (i = 0; i < 6; i++)
		{
			homeSum = homeSum + rows[i].getNumOfBlacks();
		}

		homeSum = homeSum + blackTotal;
		if (homeSum == 15)
		{
			blackTotal++;
			length = rows[index].getNumOfBlacks();
			rows[index].updateRowSub(length, index);
			rows[index].decrementBlack();
			return 0;	
		}
		else
		{
			cout << "All your pieces need to be on the home board to start bearing off. Try again." << endl;
			return 1;
		}
	}
	else if(rows[moved].getNumOfWhites() > 1)
	{
		cout << "Cannot move on row containing two or more opponents pieces!" << endl;
		return 1;
	}
	else if(rows[moved].getNumOfWhites() == 1)
	{
		length = rows[index].getNumOfBlacks();
		rows[index].updateRowSub(length, index);
		rows[index].decrementBlack();

		rows[moved].decrementWhite();

		length = rows[moved].getNumOfBlacks();
		rows[moved].updateRowAddBlack(length, moved);
		rows[moved].incrementBlack();
		whitePenalty.incrementWhite();
		whitePenalty.updateRowAddWhite(whitePenalty.getNumOfWhites() - 1, 15); //might switch zero to higher
		return 0;
	}
	else if(rows[moved].getNumOfBlacks() == 6)
	{
		cout << "Invalid move. Maximum number of your pieces are on that row." << endl;
		return 1;
	}
	else
	{
		length = rows[index].getNumOfBlacks();

		rows[index].updateRowSub(length, index);

		rows[index].decrementBlack();

		length = rows[moved].getNumOfBlacks();
		rows[moved].updateRowAddBlack(length, moved);
		rows[moved].incrementBlack();
		return 0;
	}
}

int gameBoard::numOfBlacks(int x)
{
	return rows[x].getNumOfBlacks();
}

int gameBoard::numOfWhites(int x)
{
	return rows[x].getNumOfWhites();
}

bool gameBoard::checkWhiteWin()
{
	if(whiteTotal == 15)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool gameBoard::checkBlackWin()
{
	if(blackTotal == 15)
	{
		return true;
	}
	else
	{
		return false;
	}
}


gameBoard::~gameBoard(void)
{
}

void gameBoard::printBoard()
{
	cout << "######################" << endl;
	cout << "12" << " ";
	rows[11].printRow(); 
	cout << "   " ;
	rows[12].printRow();
	cout << "  " << "13" << endl;
	cout << "11" << " ";
	rows[10].printRow();
	cout << "   ";
	rows[13].printRow();
	cout << "  " << "14" << endl;
	cout << "10" << " ";
	rows[9].printRow() ;
	cout << "   ";
	rows[14].printRow();
	cout << "  " << "15" << endl;
	cout << '9' << "  ";
	rows[8].printRow() ;
	cout << "   ";
	rows[15].printRow();
	cout << "  " << "16" << endl;
	cout << '8' << "  ";
	rows[7].printRow() ;
	cout << "   ";
	rows[16].printRow();
	cout << "  " << "17" << endl;
	cout << '7' << "  ";
	rows[6].printRow() ;
	cout << "   ";
	rows[17].printRow();
	cout << "  " << "18" << endl;
	
	cout << "BP ";
	blackPenalty.printRow();
	cout << "|||||||||  ##" << endl;

	cout << "## ";
	cout << "|||||||||";
	whitePenalty.printRow();
	cout << "  WP" << endl;

	cout << '6' << "  ";
	rows[5].printRow() ;
	cout << "   ";
	rows[18].printRow();
	cout << "  " << "19" << endl;
	cout << '5' << "  ";
	rows[4].printRow() ;
	cout << "   ";
	rows[19].printRow();
	cout << "  " << "20" << endl;
	cout << '4' << "  ";
	rows[3].printRow() ;
	cout << "   ";
	rows[20].printRow();
	cout << "  " << "21" << endl;
	cout << "3" << "  ";
	rows[2].printRow() ;
	cout << "   ";
	rows[21].printRow();
	cout << "  " << "22" << endl;
	cout << "2" << "  ";
	rows[1].printRow() ;
	cout << "   ";
	rows[22].printRow();
	cout << "  " << "23" << endl;
	cout << "1" << "  ";
	rows[0].printRow() ;
	cout << "   ";
	rows[23].printRow();
	cout << "  " << "24" << endl;
	cout << "######################" << endl;
}
