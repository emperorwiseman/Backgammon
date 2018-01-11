//Backgammon Final Project
//Class: Obj Orient Pgm w/C++
//Programmed by: Kyle Opland
//Date: 6/9/14
//gameboard.h file
#pragma once
#include "row.h"
#include <iomanip>
#include <string>
#include <cstring>

class gameBoard
{
public:
	bool checkStuckWhite(int x, int y);
	//Purpose:
	//	Checks if a legal move is possible from the middle bar for the white player
	//Precondition:
	//	The dice rolls need to be passed in.
	//Postcondition:
	//	Returns true if a move is not possible, false if a move is available. Ends turn if true.
	bool checkStuckBlack(int x, int y);
	//Purpose:
	//	Checks if a legal move is possible from the middle bar for the black player
	//Precondition:
	//	The dice rolls need to be passed in.
	//Postcondition:
	//	Returns true if a move is not possible, false if a move is available. Ends turn if true.
	bool checkPenaltyWhite();
	//Purpose:
	//	Checks if a game piece is currently in the middle bar for the white player
	//Precondition:
	//	None
	//Postcondition:
	//	Returns true if piece is located there, false if it is empty. If true, player must move this piece first.
	bool checkPenaltyBlack();
	//Purpose:
	//	Checks if a game piece is currently in the middle bar for the black player
	//Precondition:
	//	None
	//Postcondition:
	//	Returns true if piece is located there, false if it is empty. If true, player must move this piece first.
	int movePieceWhite(int x, int y);
	//Purpose:
	//	Handles all updates for moving a white piece from one row to another. Also checks legality of selected move.
	//Precondition:
	//	Requires a selected row to move a piece from and selected row to move the piece to.
	//Postcondition:
	//	A white piece is moved from one row to another, assuming it met all criteria for a legal move.
	int movePieceBlack(int x, int y);
	//Purpose:
	//	Handles all updates for moving a black piece from one row to another. Also checks legality of selected move.
	//Precondition:
	//	Requires a selected row to move a piece from and selected row to move the piece to.
	//Postcondition:
	//	A black piece is moved from one row to another, assuming it met all criteria for a legal move.
	int movePieceWhitePenalty(int row, int choice);
	//Purpose:
	//	Handles all updates for moving a white piece from the middle bar back to the board. Also checks legality of selected move.
	//Precondition:
	//	Requires a dice roll and a selected row to move the piece to.
	//Postcondition:
	//	A white piece is moved from the middle bar back to the board, assuming it met all criteria for a legal move.
	int movePieceBlackPenalty(int row, int choice);
	//Purpose:
	//	Handles all updates for moving a black piece from the middle bar back to the board. Also checks legality of selected move.
	//Precondition:
	//	Requires a dice roll and a selected row to move the piece to.
	//Postcondition:
	//	A black piece is moved from the middle bar back to the board, assuming it met all criteria for a legal move.
	int numOfWhites(int x);
	//Purpose:
	//	To find out the number of white pieces currently in the row.
	//Precondition:
	//	requires an index number to access a particular row in the array.
	//Postcondition:
	//	Returns number of white pieces in the row as an integer.
	int numOfBlacks(int x);
	//Purpose:
	//	To find out the number of black pieces currently in the row.
	//Precondition:
	//	requires an index number to access a particular row in the array.
	//Postcondition:
	//	Returns number of black pieces in the row as an integer.
	bool checkBlackWin();
	//Purpose:
	//	Checks to see if the black player has won the game
	//Precondition:
	//	To be true the blackTotal variable must reach 15, meaning all 15 pieces have left the board.
	//Postcondition:
	//	Returns true if win condition is met.
	bool checkWhiteWin();
	//Purpose:
	//	Checks to see if the white player has won the game
	//Precondition:
	//	To be true the whiteTotal variable must reach 15, meaning all 15 pieces have left the board.
	//Postcondition:
	//	Returns true if win condition is met.
	void printBoard();
	//Purpose:
	//	Prints out the current gameBoard to the screen.
	//Precondition:
	//	All rows in the array must be initialized
	//Postcondition:
	//	Board is printed to screen.
	gameBoard(void);
	//Purpose:
	//	Sets up starting positions and values of rows for the beginning of the game.
	//Precondition:
	//	None
	//Postcondition:
	//	blackTotal and whiteTotal are initialized to zero and all the rows are set to their starting values with the setRow() function.
	~gameBoard(void);

private:
	row rows[24];		//Array of all the rows on the board
	row blackPenalty;	//special row for the black bar in the middle of the board.
	row whitePenalty;	//special row for the white bar in the middle of the board.
	int blackTotal;		//Keeps track of the amount of blacks that have made it off the board.
	int whiteTotal;		//Keeps track of the amount of whites that have made it off the board.
};
