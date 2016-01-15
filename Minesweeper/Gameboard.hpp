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
	~Gameboard();
    void InitGame(char difficulty);
    void Display();
    bool Uncover();
    bool GameState();
    int getRows();
    int getCols();
	bool SelectRow(int);
	bool SelectColumn(int);
	int GetSelectedRow();
	int GetSelectedCol();
	void ClearSelect();

	void Rowmm();
	void Rowpp();
	void Colmm();
	void Colpp();

	void Mark();
	bool GetWinStatus();
    
private:
    void PlaceMines(int mines);
    Array2D<Cell> * board;
    
    bool _still_playing = true;
	int selRow;
	int selCol;
	bool CheckAllMines();
    
	bool _hasWon = false;
};

#endif /* Gameboard_hpp */
