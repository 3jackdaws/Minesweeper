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
	cout << endl;
    cout<<"  ";
    for (int i = 1; i< board->getColumn(); i++) {
        if(i%2 == 0)
            cout<<setw(2)<<i;
        else
            cout<<setw(2)<<" ";
    }
    cout<<endl;
    for(int row = 1; row<board->getRow()-1; row++)
    {
        if(row%2 == 0)
            cout<<setw(2)<<row;
        else
            cout<<setw(2)<<" ";
        for (int col =1; col<board->getColumn()-1; col++)
        {
#ifdef DEBUGMODE
            cout<<setw(2)<<(*board)[row][col].getProx();
#else
            if((*board)[row][col].getExposure())
            {
                char output = (*board)[row][col].getProx();
                if(output != '0')
                    cout<<setw(2)<<output;
                else
                {
                    cout<<setw(2)<<" ";
                }
            }
            else
                cout<<setw(2)<<"\u2610";

            
#endif
        }
        cout<<endl;
    }
    cout<<setw(2)<<endl<< "   ";
    
    
}

void Gameboard::InitGame(char difficulty)
{
    int row, col, mines;
    switch(difficulty)
    {
        case 'b':
            row =10, col = 10, mines = 10;
            break;
        case 'i':
            row = 16, col = 16, mines = 40;
            break;
        case 'e':
            row = 16, col = 30, mines = 100;
            break;
            
    }
    board = new Array2D<Cell>(row+2, col+2);
    for(int row = 0; row<board->getRow(); row++)
    {
        
        for (int col =0; col<board->getColumn(); col++)
        {
            Cell init(board, row, col);
            (*board)[row][col] = init;
            
            if(row == 0 || row == board->getColumn()-1 || col == 0 || col == board->getColumn()-1)
            {
                (*board)[row][col].SetProx('W');
            }
            
        }
        
    }
    PlaceMines(mines);
}

void Gameboard::PlaceMines(int mines)
{

    int col = 0;
    int row = 0;
    
    for(int i = 0; i<mines; i++)
    {
        std::srand(std::time(0)+i*(col+1)*(row+1));
        col = rand()%(board->getColumn()-2)+1;
        std::srand(std::time(0)+i*(row+1));
        row = rand()%(board->getRow()-2)+1;
        if((*board)[row][col].getProx() != 'B')
            (*board)[row][col].SetBomb();
        else
            i--;
    }
    
}

bool Gameboard::GameState()
{
    return _still_playing;
}

void Gameboard::Uncover(int row, int col)
{
    if((*board)[row][col].Uncover())
    {
        _still_playing = false;
        std::cout<<"\nYou hit a bomb"<<std::endl;
    }
}

int Gameboard::getRows()
{
    return board->getRow()-2;
}






