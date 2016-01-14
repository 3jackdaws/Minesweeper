//
//  main.cpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/11/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//





#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
#include <string>
using std::string;
#include "Gameboard.hpp"

int main()
{
	bool exit = false;

	
	    
	while (!exit)
	{
		Gameboard minesweeper;
		minesweeper.InitGame('b');
		while (minesweeper.GameState())
		{
			string row;
			string col;
			minesweeper.Display();
			cout << "\n\nEnter the row then the column of the tile.\nRow:";
			std::getline(std::cin, row);
			minesweeper.SelectRow(atoi(row.c_str()));
			minesweeper.Display();
			cout << "\n\nEnter tile to uncover. \nRow:";
			cout << minesweeper.GetSelectedRow() << endl;
			cout << "\nColumn: ";
			std::getline(std::cin, col);
			minesweeper.SelectColumn(atoi(col.c_str()));
			if (atoi(row.c_str()) < minesweeper.getRows() && atoi(col.c_str()) < minesweeper.getCols())
			{
				minesweeper.Display();
				string choice;
				cout << "Uncover or Mark? (u/m): ";
				std::getline(std::cin, choice);
				if (choice == "U" || choice == "u")
					minesweeper.Uncover(atoi(row.c_str()), atoi(col.c_str()));
				else if (choice == "M" || choice == "m")
					minesweeper.Mark(atoi(row.c_str()), atoi(col.c_str()));
				else
				{

				}
			}
			else
			{
				minesweeper.Display();
				cout << "\n\nEnter tile to uncover. \nRow:";
				cout << minesweeper.GetSelectedRow() << endl;
				cout << "\nColumn: ";
				cout << col << endl;
			}
			
		}
		minesweeper.Display();
		cout << "Oh no, you hit a mine!"<<endl;
		system("pause");
	}
	    
	
	    
	
	    
	return 0;
}


