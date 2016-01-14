//
//  Cell.cpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/13/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include "Cell.hpp"

Cell::Cell() : _grid(nullptr), _prox('W')
{
    
}

Cell::Cell(Array2D<Cell> * grid, int row, int col): _exposed(false), _prox('0'), _grid(grid), _row(row), _col(col)
{
    
}

Cell::Cell(const Cell & cp) : _exposed(cp._exposed), _prox(cp._prox), _grid(cp._grid)
{
    
}

Cell::~Cell()
{
    
}

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

char Cell::operator++(int)
{
    char old = _prox;
    if(_prox != 'W' && _prox != 'B')
        _prox++;

    return old;
}

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

void Cell::SetProx(char p)
{
    _prox = p;
}

char Cell::getProx()
{
    return _prox;
}

bool Cell::Uncover()
{
    
    bool rval = false;
    if(_exposed == false)
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

bool Cell::getExposure()
{
    return _exposed;
}