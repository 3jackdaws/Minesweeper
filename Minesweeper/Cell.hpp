//
//  Cell.hpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/13/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

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
    
private:
    Array2D<Cell> * _grid = nullptr;
    bool _exposed;
    char _prox;
    int _row;
    int _col;
    
};

#endif /* Cell_hpp */
