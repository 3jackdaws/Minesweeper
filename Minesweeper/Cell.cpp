/*************************************************************
* Author:		Ian Murphy
* Filename:		Cell.cpp
* Date Created:	1/18/16
* Modifications:	1/18/16 - added documentation
**************************************************************/

#include "Cell.hpp"

/**********************************************************************
* Purpose: Default ctor for cell.
*
* Precondition:
*     none
*
* Postcondition:
*      sets _grid to nullptr, _prox to 'W', and _mark to false
*
************************************************************************/
Cell::Cell() : _grid(nullptr), _prox('W'), _mark(false)
{
    
}

/**********************************************************************
* Purpose: 3 arg ctor for cell.
*
* Precondition:
*     none
*
* Postcondition:
*      sets _grid to grid, _prox to 'W', and _mark to false, and _row to row, and _col to col
*
************************************************************************/
Cell::Cell(Array2D<Cell> * grid, int row, int col): _exposed(false), _prox('0'), _grid(grid), _row(row), _col(col), _mark(false)
{
    
}

/**********************************************************************
* Purpose: copy ctor for cell.
*
* Precondition:
*     cp must be an object
*
* Postcondition:
*      sets everything equal to cp
*
************************************************************************/
Cell::Cell(const Cell & cp) : _exposed(cp._exposed), _prox(cp._prox), _grid(cp._grid), _mark(cp._mark)
{
    
}

/**********************************************************************
* Purpose: d'tor for cell.
*
* Precondition:
*     cell is instantiated
*
* Postcondition:
*      cell is gone
*
************************************************************************/
Cell::~Cell()
{
    
}

/**********************************************************************
* Purpose: op = overload for cell.
*
* Precondition:
*     both objects are instantiated
*
* Postcondition:
*      sets cell to values in rhs
*
************************************************************************/
Cell & Cell::operator=(Cell &rhs)
{
    if(&rhs != this)
    {
        _prox = rhs._prox;
        _exposed = rhs._exposed;
        _row = rhs._row;
        _col = rhs._col;
        _grid = rhs._grid;
    }
    return *this;
}

/**********************************************************************
* Purpose: increments the _prox value in cell
*
* Precondition:
*     _prox must have some value
*
* Postcondition:
*      sets _prox to 1 more than its previous value
*
************************************************************************/
char Cell::operator++(int)
{
    char old = _prox;
    if(_prox != 'W' && _prox != 'B')
        _prox++;

    return old;
}

/**********************************************************************
* Purpose: Tells the cell object that it is now a bomb
*
* Precondition:
*     none, really
*
* Postcondition:
*      _prox is set to 'B'
		all cells around the cell have their _prox incremented
*
************************************************************************/
void Cell::SetBomb()
{
    _prox = 'B';
    (*_grid)[_row][_col-1]++; //west
    (*_grid)[_row-1][_col-1]++; //North West
    (*_grid)[_row-1][_col]++; //north
    (*_grid)[_row-1][_col+1]++; //north east
    (*_grid)[_row][_col+1]++; //east
    (*_grid)[_row+1][_col+1]++; //south east
    (*_grid)[_row+1][_col]++; //south
    (*_grid)[_row+1][_col-1]++; //south west
    
}

/**********************************************************************
* Purpose: Sets _prox to p.
*
* Precondition:
*     none
*
* Postcondition:
*      _prox is now p
*
************************************************************************/
void Cell::SetProx(char p)
{
    _prox = p;
}

/**********************************************************************
* Purpose: returns the value in _prox.
*
* Precondition:
*     _prox needs a value
*
* Postcondition:
*      returns _prox
*
************************************************************************/
char Cell::getProx()
{
    return _prox;
}

/**********************************************************************
* Purpose: Uncovers the current cell.
*
* Precondition:
*     cell must be real
*
* Postcondition:
*     Cell is set to uncovered, will call uncover on all cells around it if the _prox of the current cell is 0
		will return true if a bomb is uncovered
*
************************************************************************/
bool Cell::Uncover()
{
    
    bool rval = false;
    if(_exposed == false && _mark == false)
    {
        _exposed = true;
        
        if(_prox == '0')
        {
            (*_grid)[_row][_col-1].Uncover(); //west
            (*_grid)[_row-1][_col-1].Uncover(); //North West
            (*_grid)[_row-1][_col].Uncover(); //north
            (*_grid)[_row-1][_col+1].Uncover(); //north east
            (*_grid)[_row][_col+1].Uncover(); //east
            (*_grid)[_row+1][_col+1].Uncover(); //south east
            (*_grid)[_row+1][_col].Uncover(); //south
            (*_grid)[_row+1][_col-1].Uncover(); //south west
        }
        else if(_prox == 'B')
        {
            rval = true;
        }
        else    //not one of those
        {
            
        }

    }
    return rval;
}

/**********************************************************************
* Purpose: returns the cells exposure status
*
* Precondition:
*     none
*
* Postcondition:
*      returns _exposed
*
************************************************************************/
bool Cell::getExposure()
{
    return _exposed;
}

/**********************************************************************
* Purpose: Marks a cell.
*
* Precondition:
*     none
*
* Postcondition:
*      toggles _mark for a cell
*
************************************************************************/
void Cell::Mark()
{
	if(!_exposed)
		_mark == true ? _mark = false : _mark = true;
}

/**********************************************************************
* Purpose: returns the cell's mark status

* Precondition:
*     none
*
* Postcondition:
*      returns _mark
*
************************************************************************/
bool Cell::MarkStatus()
{
	return _mark;
}