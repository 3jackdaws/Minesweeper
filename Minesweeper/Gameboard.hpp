/************************************************************************
* Class: Gameboard
*
* Purpose: This class does pretty much everything that is required for a Minesweeper game
*
* Manager functions:
* 	 Gameboard();
		sets board data member to nullptr
	~Gameboard();
    void InitGame(char difficulty);
		initializes a new game of difficulty defined, creates a new array2D to serve as the board
    void Display();
		displays the board to console
    bool Uncover();
		uncovers the cell at selRow, selCol
    bool GameState();
		returns the state of the game, i.e. over or not
    int getRows();
		returns the number of rows
    int getCols();
		returns the number of columns
	bool SelectRow(int);
		sets the selected row
	bool SelectColumn(int);
		sets the selected column
	int GetSelectedRow();
		returns the selected row
	int GetSelectedCol();
		returns the selected column
	void ClearSelect();
		clears selected row and col

	void Rowmm();
		decrements selected row
	void Rowpp();
		increments selected row
	void Colmm();
		decrements selected col
	void Colpp();
		increments selected col

	void Mark();
		marks cell at selRow, selCol
	bool GetWinStatus();
		returns the win status
    
private:
    void PlaceMines(int mines);
		randomly places mines number of mines
	bool CheckAllMines();
		checks to see if all the cells except for bombs have been uncovered
*		...
*************************************************************************/


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
	Gameboard(const Gameboard & gb);
	Gameboard & operator = (const Gameboard & rhs);
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
