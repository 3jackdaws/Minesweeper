//
//  main.cpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/11/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <windows.h>



#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>

#include "Gameboard.hpp"

int main()
{
	HANDLE hStdout = 0;
	COORD cursor;

	cursor.X = 25;
	cursor.Y = 5;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, cursor);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);

	Gameboard minesweeper;
	minesweeper.InitGame('b');
	    
	    
	    
	while(minesweeper.GameState())
	{
	    minesweeper.Display();
	    cout<<"\n\nSelect tile to uncover. \nRow:";
	    int row = 0;
	    int col = 0;
	    std::cin>>row;
	    cout<<"\nColumn: ";
	    std::cin>>col;
	        
	    minesweeper.Uncover(row, col);
	    minesweeper.Display();
	}
	    
	
	    
	return 0;
}

//int main() {
//    Gameboard minesweeper;
//    minesweeper.InitGame('e');
//    
//    
//    
//    while(minesweeper.GameState())
//    {
//        minesweeper.Display();
//        cout<<"\n\nSelect tile to uncover. \nRow:";
//        int row = 0;
//        int col = 0;
//        std::cin>>row;
//        cout<<"\nColumn: ";
//        std::cin>>col;
//        
//        minesweeper.Uncover(row, col);
//        minesweeper.Display();
//    }
//    
//
//    
//    return 0;
//}
