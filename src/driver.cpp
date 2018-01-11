//Backgammon Final Project
//Class: Obj Orient Pgm w/C++
//Programmed by: Kyle Opland
//Date: 6/9/14
//driver.cpp file
#include "dice.h"
#include "gameBoard.h"
#include <iostream>
#include <string>

using namespace std;

bool whiteTurn(gameBoard&, string, string);
//Purpose:
//	Runs through the steps for the white player's turn.
//Precondition:
//	Turn variable must be an odd number.
//Postcondition:
//	Turn variable is incremented causing the blackTurn() function to be called, unless the player won on their turn.
bool blackTurn(gameBoard&, string, string);
//Purpose:
//	Runs through the steps for the black player's turn.
//Precondition:
//	Turn variable must be an odd number.
//Postcondition:
//	Turn variable is incremented causing the whiteTurn() function to be called, unless the player won on their turn.



int main()
{
	int turn = 3;
	string p1, p2;
	gameBoard backgammon;
	bool whiteWin = false;
	bool blackWin = false;
	dice dice1, dice2;

	cout << "Welcome to Backgammon!" << endl;
	cout << "The object of the game is to try and get all of your pieces to the home location." << endl;

	cout << "Enter name of player one: ";
	getline(cin, p1);
	cout << endl;

	cout << "Enter name of player two: ";
	getline(cin, p2);
	cout << endl;

	cout << "To determine who goes first, roll the dice for the players.";
	cout << endl;
	system("pause");

	do
	{
		dice1.rollDice();
		dice2.rollDice();
		cout << p1 << " rolled a ";
		dice1.printDice();
		cout << endl;
		cout << p2 << " rolled a ";
		dice2.printDice();
		cout << endl;

		if(dice1.getDice() == dice2.getDice())
		{
			cout << "Roll is a tie, rolling again." << endl;
		}
	}
	while(dice1.getDice() == dice2.getDice());


	if (dice1.getDice() > dice2.getDice())
	{
		cout << p1 << " goes first.";
	}

	else if (dice1.getDice() < dice2.getDice())
	{
		cout << p2 << " goes first.";
		turn++;
	}

	cout << endl << endl;

	system("pause");

	backgammon.printBoard();
	cout << endl << endl;

	while (!whiteWin && !blackWin)
	{
	
		if (turn % 2 == 0)
		{
			blackWin = blackTurn(backgammon, p1, p2);
			turn++;
		}
		else
		{
			whiteWin = whiteTurn(backgammon, p1, p2);
			turn++;
		}
		whiteWin = backgammon.checkWhiteWin();
		blackWin = backgammon.checkBlackWin();
	}

	backgammon.printBoard();

	if (whiteWin)
	{
		cout << endl << endl << p1 << ", the white player, has won the game!!! Congratulations!!!" << endl;
		system("pause");
		return 0;
	}

	if (blackWin)
	{
		cout << endl << endl << p2 << ", the black player, has won the game!!! Congratulations!!!" << endl;
		system("pause");
		return 0;
	}
}

bool whiteTurn(gameBoard &backgammon, string p1, string p2)
{
	int move1 = 0;
	int move2 = 0;
	int move3 = 0;
	int move4 = 0;

	bool check = false;
	bool stuck = false;
	bool penalty = false;
	int errorCheck;

	int rowChoice;
	int moved;
	dice dice1, dice2;
	int choice;

		cout << p1 << ", you are White. Rolling dice for your turn." << endl << endl;
		cout << endl << "You rolled a 1.) ";
		move1 = dice1.rollDice(); 
		move2 = dice2.rollDice();
	
		cout << move1 << " and a 2.) " << endl << move2 << endl << endl;

		if (move1 == move2)
		{
			
			cout << "You rolled doubles! You get to move twice for each die."<< endl << endl;
			move3 = move1;
			move4 = move2;
		}

		penalty = backgammon.checkPenaltyWhite();

		while(penalty)
		{
			rowChoice = 25;
			stuck = backgammon.checkStuckWhite(move1, move2);
			if (stuck)
			{
				cout << "Your piece is stuck on the bar. You have no possible moves, your turn is over." << endl;
				return false;
			}
			if (move1 != 0 && move2 == 0)
			{
				cout << "Your remaining dice roll is: " << move1 << endl;
				choice = 1;
			}
			else if(move2 != 0 && move1 == 0)
			{
				cout << "Your remaining dice roll is: " << move2 << endl;
				choice = 2;
			}
			else
			{
				do{
					try
					{


					cout << "Please enter the die you would like to use first." << endl << "Type (1) for Dice 1.) " << move1 << endl << "Type (2) for Dice 2.) " << move2 << endl << ":"; 
					cin >> choice;
					if(!cin)
					{
						throw 3;
					
					}
					cout << endl << endl;
					check = true;
					}
				
					catch(int)
					{
					cout << endl << endl << "ERROR: Input invalid. Please enter a number between 1 and 2.";
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl;
					}
				}while(check == false);
			}
			switch (choice)
			{
			case 1:
				if(move3 != 0)
				{
					moved = rowChoice - move3;
					errorCheck = backgammon.movePieceWhitePenalty(rowChoice, moved);
					if(errorCheck == 0)
					{
						move3 = 0;
						penalty = backgammon.checkPenaltyWhite();
						backgammon.printBoard();
					}
					break;
				}
				moved = rowChoice - move1;
				errorCheck = backgammon.movePieceWhitePenalty(rowChoice, moved);
				if(errorCheck == 0)
				{
					move1 = 0;
					penalty = backgammon.checkPenaltyWhite();
					backgammon.printBoard();
				}
				break;
			case 2:
				if(move4 != 0)
				{
					moved = rowChoice - move4;
					errorCheck = backgammon.movePieceWhitePenalty(rowChoice, moved);
					if(errorCheck == 0)
					{
						move4 = 0;
						penalty = backgammon.checkPenaltyWhite();
						backgammon.printBoard();
					}
					break;
				}

				moved = rowChoice - move2;
				errorCheck = backgammon.movePieceWhitePenalty(rowChoice, moved);
				if(errorCheck == 0)
				{
					move2 = 0;
					penalty = backgammon.checkPenaltyWhite();
					backgammon.printBoard();
				}
				break;
			default:
				cout << "That is not a valid input. Try again below by choosing the die you would want to start with." << endl << endl;
				break;
			}
		}

		do
		{
			if (move1 != 0 && move2 == 0)
			{
				cout << "Your remaining dice roll is: " << move1 << endl;
				choice = 1;
			}
			else if(move2 != 0 && move1 == 0)
			{
				cout << "Your remaining dice roll is: " << move2 << endl;
				choice = 2;
			}
			else
			{
				check = false;
				do{
					try
					{


					cout << "Please enter the die you would like to use first." << endl << "Type (1) for Dice 1.) " << move1 << endl << "Type (2) for Dice 2.) " << move2 << endl << ":"; 
					cin >> choice;
					if(!cin)
					{
						throw 3;
					
					}
					cout << endl << endl;
					check = true;
					}
				
					catch(int)
					{
					cout << endl << endl << "ERROR: Input invalid. Please enter a number between 1 and 2.";
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl;
					}
				}while(check == false);
			}
			
			check = false;
				do{
					try
					{

						cout << "Now enter the row you want to move from: ";
						cin >> rowChoice;//add error handling
					
					if(!cin)
					{
						throw 4;
					
					}
					cout << endl << endl;
					check = true;
					}
				
					catch(int)
					{
					cout << endl << endl << "ERROR: Input invalid. Please enter a number between 1 and 24.";
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl;
					}
				}while(check == false);

		
			switch (choice)
			{
			case 1:
				if(move3 != 0)
				{
					moved = rowChoice - move3;
					errorCheck = backgammon.movePieceWhite(rowChoice, moved);
					if(errorCheck == 0)
					{
						move3 = 0;
						
						if(backgammon.checkWhiteWin())
						{	
							return true;
						}
					}
					break;
				}
				moved = rowChoice - move1;
				errorCheck = backgammon.movePieceWhite(rowChoice, moved);
				if(errorCheck == 0)
				{
					move1 = 0;
					
					if(backgammon.checkWhiteWin())
					{	
						return true;
					}
				}
				break;
			case 2:
				if(move4 != 0)
				{
					moved = rowChoice - move4;
					errorCheck = backgammon.movePieceWhite(rowChoice, moved);
					if(errorCheck == 0)
					{
						move4 = 0;
						
						if(backgammon.checkWhiteWin())
						{	
							return true;
						}
						
					}
					break;
				}

				moved = rowChoice - move2;
				errorCheck = backgammon.movePieceWhite(rowChoice, moved);
				if(errorCheck == 0)
				{
					move2 = 0;
					
						if(backgammon.checkWhiteWin())
						{	
							return true;
						}
				}
				break;
			default:
				cout << "That is not a valid input. Try again below by choosing the die you would want to start with." << endl << endl;
				break;
			}
		
			backgammon.printBoard();
		//if(backgammon.numOfWhites(rowChoice - 1) == 0)
		//{
		//}
		} while(move1 != 0 || move2 != 0);

		return false;
}

bool blackTurn(gameBoard &backgammon, string p1, string p2)
{
	int move1 = 0;
	int move2 = 0;
	int move3 = 0;
	int move4 = 0;

	bool check = false;
	bool stuck;
	bool penalty;

	int errorCheck;

	int rowChoice;
	int moved;
	dice dice1, dice2;
	int choice;

		cout << p2 << ", you are Black. Rolling dice for your turn." << endl << endl;
		cout << "You rolled a 1.) ";
		move1 = dice1.rollDice(); 
		move2 = dice2.rollDice();
	
		cout << move1 << " and a 2.) " << move2 << endl << endl;

		if (move1 == move2)
		{
			
			cout << "You rolled doubles! You get to move twice for each die."<< endl << endl;
			move3 = move1;
			move4 = move2;
		}

		penalty = backgammon.checkPenaltyBlack();

		while(penalty)
		{
			rowChoice = 0;
			stuck = backgammon.checkStuckBlack(move1, move2);
			if (stuck)
			{
				cout << "Your piece is stuck on the bar.You have no possible moves, your turn is over." << endl;
				
				return false;
			}
			if (move1 != 0 && move2 == 0)
			{
				cout << "Your remaining dice roll is: " << move1 << endl;
				choice = 1;
			}
			else if(move2 != 0 && move1 == 0)
			{
				cout << "Your remaining dice roll is: " << move2 << endl;
				choice = 2;
			}
			else
			{

				check = false;
				do{
					try
					{


					cout << "Please enter the die you would like to use first." << endl << "Type (1) for Dice 1.) " << move1 << endl << "Type (2) for Dice 2.) " << move2 << endl << ":"; 
					cin >> choice;
					if(!cin)
					{
						throw 3;
					
					}
					cout << endl << endl;
					check = true;
					}
				
					catch(int)
					{
					cout << endl << endl << "ERROR: Input invalid. Please enter a number between 1 and 2.";
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl;
					}
				}while(check == false);
			}
			switch (choice)
			{
			case 1:
				if(move3 != 0)
				{
					moved = rowChoice + move3;
					errorCheck = backgammon.movePieceBlackPenalty(rowChoice, moved);
					if(errorCheck == 0)
					{
						move3 = 0;
						penalty = backgammon.checkPenaltyBlack();
						backgammon.printBoard();
					}
					break;
				}
				moved = rowChoice + move1;
				errorCheck = backgammon.movePieceBlackPenalty(rowChoice, moved);
				if(errorCheck == 0)
				{
					move1 = 0;
					penalty = backgammon.checkPenaltyBlack();
					backgammon.printBoard();
				}
				break;
			case 2:
				if(move4 != 0)
				{
					moved = rowChoice + move4;
					errorCheck = backgammon.movePieceBlackPenalty(rowChoice, moved);
					if(errorCheck == 0)
					{
						move4 = 0;
						penalty = backgammon.checkPenaltyBlack();
						backgammon.printBoard();
					}
					
					break;
				}

				moved = rowChoice + move2;
				errorCheck = backgammon.movePieceBlackPenalty(rowChoice, moved);
				if(errorCheck == 0)
				{
					move2 = 0;
					penalty = backgammon.checkPenaltyBlack();
					backgammon.printBoard();
				}
				break;
			default:
				cout << "That is not a valid input. Try again below by choosing the die you would want to start with." << endl << endl;
				break;
			}
		}

		do
		{
			if (move1 != 0 && move2 == 0)
			{
				cout << "Your remaining dice roll is: " << move1 << endl;
				choice = 1;
			}
			else if(move2 != 0 && move1 == 0)
			{
				cout << "Your remaining dice roll is: " << move2 << endl;
				choice = 2;
			}
			else
			{
				check = false;
				do{
					try
					{


					cout << "Please enter the die you would like to use first." << endl << "Type (1) for Dice 1.) " << move1 << endl << "Type (2) for Dice 2.) " << move2 << endl << ":"; 
					cin >> choice;
					if(!cin)
					{
						throw 3;
					
					}
					cout << endl << endl;
					check = true;
					}
				
					catch(int)
					{
					cout << endl << endl << "ERROR: Input invalid. Please enter a number between 1 and 2.";
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl;
					}
				}while(check == false);
			}

			check = false;
				do{
					try
					{


						cout << "Now enter the row you want to move from: ";
						cin >> rowChoice;
					if(!cin)
					{
						throw 4;
					
					}
					cout << endl << endl;
					check = true;
					}
				
					catch(int)
					{
					cout << endl << endl << "ERROR: Input invalid. Please enter a number between 1 and 24.";
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl;
					}
				}while(check == false);

		
			switch (choice)
			{
			case 1:
				if(move3 != 0)
				{
					moved = rowChoice + move3;
					errorCheck = backgammon.movePieceBlack(rowChoice, moved);
					if(errorCheck == 0)
					{	move3 = 0;

						
						if (backgammon.checkBlackWin())
						{
							return true;
						}
					}
					break;
				}
				moved = rowChoice + move1;
				errorCheck = backgammon.movePieceBlack(rowChoice, moved);
				if(errorCheck == 0)
				{
					move1 = 0;
					
					if (backgammon.checkBlackWin())
						{
							return true;
						}
				}
				break;
			case 2:
				if(move4 != 0)
				{
					moved = rowChoice + move4;
					errorCheck = backgammon.movePieceBlack(rowChoice, moved);
					if(errorCheck == 0)
					{
						move4 = 0;
						
						if (backgammon.checkBlackWin())
						{
							return true;
						}	
					}
					break;
				}

				moved = rowChoice + move2;
				errorCheck = backgammon.movePieceBlack(rowChoice, moved);
				if(errorCheck == 0)
				{
					move2 = 0;
					
					if (backgammon.checkBlackWin())
						{
							return true;
						}
				}
				break;
			default:
				cout << "That is not a valid input. Try again below by choosing the die you would want to start with." << endl << endl;
				break;
			}
		
			backgammon.printBoard();
		//if(backgammon.numOfWhites(rowChoice - 1) == 0)
		//{
		//}
		} while(move1 != 0 || move2 != 0);

		return false;
}
