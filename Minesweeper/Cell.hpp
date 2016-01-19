/************************************************************************
* Class: Cell
*
* Purpose: This class serves as a representation of each cell of a minesweeper board
*
* Manager functions:
* 	Cell ( )
* 		By default, the cell is a Wall cell, it is not uncovered, and has no pointer to the greater grid of cells.
*	Cell(Array2D<Cell> * grid, int row, int col);
		Sets the cell grid to the grid address, proximity to 0, marked to false, assigns the cells coords 
    Cell(const Cell &);
		Copies stuff, actually never used
    ~Cell();
		destructor
    Cell & operator = (Cell & rhs);
		Used a bunch, sets the cell on the left so that it is a duplicate of the cell on the right
    
Methods:
    char operator ++ (int);
		incremrents the proximity number of the cell
    char getProx();
		returns the proximity 
    bool getExposure();
		returns the exposure status of the cell
    void SetBomb();
		Tells the cell that it is now a bomb and now must increment the prox counter on all the cells around it
    void SetProx(char p);
		sets the proximity to p
    bool Uncover();
		uncovers a cell, returns true if cell is a bomb
	bool MarkStatus();
		returns _mark
	void Mark();
		toggles the mark status of the cell
*		...
*************************************************************************/


#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include "Array2D.h"

class Cell
{
public:
    Cell();
    Cell(Array2D<Cell> * grid, int row, int col);
    Cell(const Cell &);
    ~Cell();
    Cell & operator = (Cell & rhs);
    
    char operator ++ (int);
    char getProx();
    bool getExposure();
    void SetBomb();
    void SetProx(char p);
    bool Uncover();
	bool MarkStatus();
	void Mark();
    
private:
    Array2D<Cell> * _grid = nullptr;
    bool _exposed;
    char _prox;
	bool _mark;
    int _row;
    int _col;
    
};

#endif /* Cell_hpp */
