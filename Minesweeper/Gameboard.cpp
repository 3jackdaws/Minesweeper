//
//  Gameboard.cpp
//  Minesweeper
//
//  Created by Ian Murphy on 1/11/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include "Gameboard.hpp"

Gameboard::Gameboard(): board(nullptr)
{
    
}

void Gameboard::Display()
{
    for(int row = 1; row<board->getRow()-1; row++)
    {
        std::cout<<setw(2)<<board->getRow() - row -1;
        for (int col =1; col<board->getColumn()-1; col++)
        {
            if((*board)[row][col].getExposure())
                std::cout<<setw(2)<<(*board)[row][col].getProx();
            else
                std::cout<<" ";
            
        }
        std::cout<<std::endl;
    }
    std::cout<<setw(2)<<std::endl<< " ";
    for (int i = 0; i< board->getColumn(); i++) {
        std::cout<<setw(2)<<i;
    }
    
}

void Gameboard::InitGame(int row, int col, int difficulty)
{
    
    board = new Array2D<Cell>(row+2, col+2);
    _difficulty = difficulty;
    for(int row = 0; row<board->getRow(); row++)
    {
        
        for (int col =0; col<board->getColumn(); col++)
        {
            Cell init(board, row, col);
            (*board)[row][col] = init;
            
            if(row == 0 || row == board->getColumn() || col == 0 || col == board->getColumn())
            {
                (*board)[row][col].SetProx('W');
            }
            
        }
        
    }
    PlaceMines();
}

void Gameboard::PlaceMines()
{
    int num_mines = _difficulty * 10;

    int col = 0;
    int row = 0;
    
    for(int i = 0; i<num_mines; i++)
    {
        std::srand(std::time(0)+i*(col+1)*(row+1));
        col = rand()%(board->getColumn()-2)+1;
        std::srand(std::time(0)+i*(row+1));
        row = rand()%(board->getRow()-2)+1;
        (*board)[row][col].SetBomb();
    }
    
}

bool Gameboard::GameState()
{
    return _still_playing;
}








