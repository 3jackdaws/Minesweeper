//
//  main.cpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/11/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//




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


