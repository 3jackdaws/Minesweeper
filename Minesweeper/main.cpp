//
//  main.cpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/11/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//
#ifndef _WIN32
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"
#else
#include <windows.h>
#endif


#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>

#include "Gameboard.hpp"


int main() {
    Gameboard minesweeper;
    minesweeper.InitGame(10, 10, 1);
    minesweeper.Display();
    while(minesweeper.GameState())
    {
        cout<<"\n\nSelect tile to uncover. \nRow:";
        int row = 0;
        int col = 0;
        std::cin>>row;
        cout<<"\nColumn: ";
        std::cin>>col;
        minesweeper.Uncover(row, col);
        
    }
    

    
    return 0;
}
