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
			int row = 0;
			int col = 0;
			minesweeper.Display();
			cout << "\n\nEnter the row then the column of the tile.\nRow:";
			std::cin >> row;
			minesweeper.SelectRow(row);
			minesweeper.Display();
			cout << "\n\nEnter tile to uncover. \nRow:";
			cout << minesweeper.GetSelectedRow() << endl;
			cout << "\nColumn: ";
			std::cin >> col;
			minesweeper.SelectRow(NULL);
			if (row < minesweeper.getRows() && col < minesweeper.getCols())
			{
				char choice;
				cout << "Uncover or Mark? (u/m): ";
				std::cin >> choice;
				if (toupper(choice) == 'U')
					minesweeper.Uncover(row, col);
				else if (toupper(choice) == 'M')
					minesweeper.Mark(row, col);
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


