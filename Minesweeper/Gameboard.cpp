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
	system("cls");
	HANDLE hStdout = 0;
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
		if (row == selRow)
		{
			SetConsoleTextAttribute(hStdout, BACKGROUND_BLUE | FOREGROUND_INTENSITY);
		}
        if(row%2 == 0)
            cout<<setw(2)<<row;
        else
            cout<<setw(2)<<" ";
        for (int col =1; col<board->getColumn()-1; col++)
        {
#ifdef DEBUGMODE
            cout<<setw(2)<<(*board)[row][col].getProx();
#else
			if ((*board)[row][col].getExposure())
			{
				char output = (*board)[row][col].getProx();
				if (output != '0')
				{

					hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
					switch (output)
					{

					case '1':
						SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
						break;

					case '2':
						SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						break;

					case '3':
						SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						break;

					case '4':
						SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						break;

					case '5':
						SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						break;

					case '6':
						SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						break;

					case '7':
						SetConsoleTextAttribute(hStdout, FOREGROUND_RED);
						break;

					case '8':
						SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE);
						break;


					}
					cout << setw(2) << output;
					SetConsoleTextAttribute(hStdout, 7);
				}



				else
				{
					cout << setw(2) << " ";
				}
			}
			else
			{
				if ((*board)[row][col].MarkStatus())
					cout << setw(2) << "?";
				else
					cout<<setw(2)<<"#";
			}
				

            
#endif
        }
        cout<<endl;
		SetConsoleTextAttribute(hStdout, 7);
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

bool Gameboard::Uncover(int row, int col)
{
    if((*board)[row][col].Uncover())
    {
        _still_playing = false;
		return true;
    }
	return false;
}

int Gameboard::getRows()
{
    return board->getRow()-2;
}

int Gameboard::getCols()
{
	return board->getColumn();
}

void Gameboard::SelectRow(int row)
{
	selRow = row;
}

int Gameboard::GetSelectedRow()
{
	return selRow;
}

void Gameboard::Mark(int row, int col)
{
	(*board)[row][col].Mark();
}
