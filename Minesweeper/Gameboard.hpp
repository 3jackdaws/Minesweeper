//
//  Gameboard.hpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/11/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef Gameboard_hpp
#define Gameboard_hpp

#include <cstdlib>
#include <iostream>
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
    void InitGame(int row, int col, int difficulty);
    void Display();
    void Uncover(int row, int col);
    bool GameState();
    
private:
    void PlaceMines();
    Array2D<Cell> * board;
    
    int8_t _difficulty;
    bool _still_playing = false;
};

#endif /* Gameboard_hpp */
