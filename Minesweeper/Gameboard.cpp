/*************************************************************
* Author:		Ian Murphy
* Filename:		Gameboard.cpp
* Date Created:	1/18/2016
* Modifications:	1/18/16 - Added documentation
*
**************************************************************/


#include "Gameboard.hpp"

/**********************************************************************
* Purpose: Default ctor for Gameboard.
*
* Precondition:
*     none
*
* Postcondition:
*      sets board to nullptr,
*
************************************************************************/
Gameboard::Gameboard(): board(nullptr)
{
    
}

/**********************************************************************
* Purpose: dtor for Gameboard.
*
* Precondition:
*     none
*
* Postcondition:
*      deletes a newed board,
*
************************************************************************/
Gameboard::~Gameboard()
{
	delete board;
	//cout << "in Gameboard d'tor" << endl;
}

/**********************************************************************
* Purpose: copy ctor for Gameboard.
*
* Precondition:
*     none
*
* Postcondition:
*      does nothing because don't use this,
*
************************************************************************/
Gameboard::Gameboard(const Gameboard & gb)
{
	//throw Exception("Don't use this, it does nothing");
	//don't use this
}

/**********************************************************************
* Purpose: Displays the current state of the board.
*
* Precondition:
*     board must be a thing
*
* Postcondition:
*      COLORS! and cool stuff, board is now displayed to the console
*
************************************************************************/
void Gameboard::Display()
{
	system("cls");
	HANDLE hStdout = 0;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);		//COLORS!!!
    cout<<"  ";
    for (int i = 1; i< board->getColumn(); i++) {		//output column number every two cols
        if(i%2 == 0)
            cout<<setw(2)<<i;
        else
            cout<<setw(2)<<" ";
    }
    cout<<endl;
    for(int row = 1; row<board->getRow()-1; row++)		//for every row
    {
		
        if(row%2 == 0)							//same every 2 row number output
            cout<<setw(2)<<row;
        else
            cout<<setw(2)<<" ";
        for (int col =1; col<board->getColumn()-1; col++)			//for every column
        {
#ifdef DEBUGMODE
            cout<<setw(2)<<(*board)[row][col].getProx();			//debugmode, show all tiles uncovered
#else
			if (col == selCol && row == selRow)
			{
				SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);		//if outputting the cursor, set it to green
			}
			
			if ((*board)[row][col].getExposure())		//if tile is exposed
			{
				char output = (*board)[row][col].getProx();		//get ready to output its _prox
				if (col == selCol && row == selRow)
				{
					cout << setw(2) << "x";					//cursor is always an 'X' and visible
				}
				else if (output != '0')						//if not '0' choose the color here
				{

					
					switch (output)
					{

					case '1':
						SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY );
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
					case 'B':
						SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY);
						break;
					}
					cout << setw(2) << output;
					SetConsoleTextAttribute(hStdout, 7);	//reset color
				}
				
				else
				{
					cout << setw(2) << " ";
				}
			}
			else
			{
				if ((*board)[row][col].MarkStatus())		//if the tile is marked output '^'
					cout << setw(2) << "^";
				else
					cout<<setw(2)<<char(254);				//if tile is not marked output a square
			}
			SetConsoleTextAttribute(hStdout, 7);

            
#endif
        }
        cout<<endl;
		SetConsoleTextAttribute(hStdout, 7);
    }
	
    cout<<setw(2)<<endl<< "   ";
    
    
}

/**********************************************************************
* Purpose: op =  for Gameboard.
*
* Precondition:
*     none
*
* Postcondition:
*      none
*
************************************************************************/
Gameboard & Gameboard::operator=(const Gameboard & rhs)
{

	return *this;
}

/**********************************************************************
* Purpose: initializes the Gameboard.
*
* Precondition:
*     none
*
* Postcondition:
*      decides the difficulty and sets the mines accordingly, makes a new board and fills it with cells correclty
*
************************************************************************/
void Gameboard::InitGame(char difficulty)
{
    int row, col, mines;
    switch(difficulty)		//pick game difficulty
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
		default:
			//really easy mode
			row = 16, col = 16, mines = 10;
    }
    board = new Array2D<Cell>(row+2, col+2);		//make new board 2 wider than displayed size
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

/**********************************************************************
* Purpose: Randomly places mines on the board.
*
* Precondition:
*     board must exist
*
* Postcondition:
*      sets mines number of mines randomly,
*
************************************************************************/
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

/**********************************************************************
* Purpose:returns the gamestate.
*
* Precondition:
*     none
*
* Postcondition:
*      returns _still_playing
*
************************************************************************/
bool Gameboard::GameState()
{
    return _still_playing;
}

/**********************************************************************
* Purpose: Uncovers the tile at selRow selCol
*
* Precondition:
*     selRow and selCol must be set to real numbers
*
* Postcondition:
*      uncovers the cell at location and ends the game if it was a mine,
*
************************************************************************/
bool Gameboard::Uncover()
{
	
	bool endgame = false;
    if((*board)[selRow][selCol].Uncover())
    {
        _still_playing = false;
		endgame =  true;
    }
	if (CheckAllMines())
	{
		_hasWon = true;
		endgame = true;
	}

	return endgame;
}

/**********************************************************************
* Purpose: getter for number of rows.
*
* Precondition:
*     none
*
* Postcondition:
*      returns the size of the playable rows 
************************************************************************/
int Gameboard::getRows()
{
    return board->getRow()-2;
}

/**********************************************************************
* Purpose: getter for number of cols.
*
* Precondition:
*     none
*
* Postcondition:
*      returns the size of the playable cols
************************************************************************/
int Gameboard::getCols()
{
	return board->getColumn();
}

/**********************************************************************
* Purpose: setter for the selected row
*
* Precondition:
*     none
*
* Postcondition:
*      returns true if row could be set to the input number
************************************************************************/
bool Gameboard::SelectRow(int row)
{
	bool rval = true;
	if (row > 0 && row < board->getRow() - 1)
		selRow = row;
	else
		rval = false;
	return rval;
}

/**********************************************************************
* Purpose: setter for the selected col
*
* Precondition:
*     none
*
* Postcondition:
*      returns true if col could be set to the input number
************************************************************************/
bool Gameboard::SelectColumn(int col)
{
	bool rval = true;
	if (col > 0 && col < board->getColumn() - 1)
		selCol = col;
	else
		rval = false;
	return rval;
}

/**********************************************************************
* Purpose: getter for the selected row
*
* Precondition:
*     none
*
* Postcondition:
*      returns the selected row numebr
************************************************************************/
int Gameboard::GetSelectedRow()
{
	return selRow;
}

/**********************************************************************
* Purpose: getter for the selected row
*
* Precondition:
*     none
*
* Postcondition:
*      returns the selected column number
************************************************************************/
int Gameboard::GetSelectedCol()
{
	return selCol;
}

/**********************************************************************
* Purpose:clears both selRow and selCol
*
* Precondition:
*     none
*
* Postcondition:
*      removes the cursor from the screen
************************************************************************/
void Gameboard::ClearSelect()
{
	selCol = 0;
	selRow = 0;
}

/**********************************************************************
* Purpose: decrements the selected row if possible
*
* Precondition:
*     none
*
* Postcondition:
*      selRow is selRow--
************************************************************************/
void Gameboard::Rowmm()
{
	if (selRow > 1)
	{
		selRow--;
	}
}


/**********************************************************************
* Purpose: increments the selected row if possible
*
* Precondition:
*     none
*
* Postcondition:
*      selRow is selRow++
************************************************************************/
void Gameboard::Rowpp()
{
	if (selRow < board->getRow()-2)
	{
		selRow++;
	}
}

/**********************************************************************
* Purpose: decrements the selected col if possible
*
* Precondition:
*     none
*
* Postcondition:
*      selCol is selCol--
************************************************************************/
void Gameboard::Colmm()
{
	if (selCol > 1)
	{
		selCol--;
	}
}


/**********************************************************************
* Purpose: increments the selected col if possible
*
* Precondition:
*     none
*
* Postcondition:
*      selCol is selCol++
************************************************************************/
void Gameboard::Colpp()
{
	if (selCol < board->getColumn()-2)
	{
		selCol++;
	}
}


/**********************************************************************
* Purpose: marks the cell at selRow selCol
*
* Precondition:
*     selRow selCol must select a valid cell
*
* Postcondition:
*      board[selRow][selCol] is marked
************************************************************************/
void Gameboard::Mark()
{

	(*board)[selRow][selCol].Mark();
}


/**********************************************************************
* Purpose: Checks to see if the player has won
*
* Precondition:
*     the board must exist
*
* Postcondition:
*      returns true if player has won, flase if player has not yet won
************************************************************************/
bool Gameboard::CheckAllMines()
{
	bool AllSquaresUncovered = true;
	for (int row = 1; row<board->getRow()-1 && AllSquaresUncovered; row++)
	{

		for (int col = 1; col<board->getColumn()-1 && AllSquaresUncovered; col++)
		{

			if (!(*board)[row][col].getExposure())
			{
				if((*board)[row][col].getProx() != 'B')
					AllSquaresUncovered = false;
			}

		}

	}
	return AllSquaresUncovered;
}


/**********************************************************************
* Purpose: returns the win status
*
* Precondition:
*     none
*
* Postcondition:
*      returns _hasWon
************************************************************************/
bool Gameboard::GetWinStatus()
{
	return _hasWon;
}