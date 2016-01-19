/*************************************************************
* Author:		Ian Murphy
* Filename:		main.cpp
* Date Created:	1/18/2016
* Modifications:	1/18/16 - Added documentation
*  			
**************************************************************\

/*************************************************************
*
* Lab/Assignment: Lab 1 – Minesweeper
*
* Overview:
*	This program implements the game minesweeper in the console.  
*
* Input:
*	Input consists of keyboard commands that correspond to certain actions.  The program will alert users to possible inputs.
*
* Output:
*	The program outputs the state of the minesweeper gameboard after most inputs.  Output is to the console.
*
************************************************************/



#define _CRTDBG_MAP_ALLOC



#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
#include <string>
using std::string;
#include "Minesweeper.hpp"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool exit = false;
	
	while (!exit)
	{
		system("cls");
		string choice;
		cout << "What difficulty do you want to play at?\nChoices are beginner, intermediate, or expert (b, i, e)\nType 'q' to quit\nChoice: ";
		std::getline(std::cin, choice);
		char c = tolower(choice.c_str()[0]);
		if (c == 'q')
		{
			exit = true;
		}
		else
		{
			Minesweeper newGame(c);
			newGame.StartGameUI();
		}
	}
	return 0;
}


