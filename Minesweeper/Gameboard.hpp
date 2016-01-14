//
//  Gameboard.hpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/11/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef Gameboard_hpp
#define Gameboard_hpp


#define _DEBUGMODE


#include <cstdlib>
#include <windows.h>
#include <iostream>
using std::cout;
using std::endl;
#include <ctime>

#include <iomanip>
using std::setw;
using std::setfill;
#include "Array2D.h"
#include "Cell.hpp"

class Gameboard
{
public:
    Gameboard();
    void InitGame(char difficulty);
    void Display();
    bool Uncover(int row, int col);
    bool GameState();
    int getRows();
    int getCols();
	void SelectRow(int);
	void SelectColumn(int);
	int GetSelectedRow();
	void Mark(int row, int col);
    
private:
    void PlaceMines(int mines);
    Array2D<Cell> * board;
    
    bool _still_playing = true;
	int selRow;
	int selCol;
    
};

#endif /* Gameboard_hpp */
