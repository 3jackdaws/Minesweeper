/*************************************************************
* Author:		Ian Murphy
* Filename:		Minesweeper.cpp
* Date Created:	1/18/2016
* Modifications:	1/18/16 - Added documentation
*
**************************************************************/


#include "Minesweeper.hpp"

/**********************************************************************
* Purpose: Constructor for Minesweeper class
*
* Precondition:
*     none
*
* Postcondition:
*      difficulty is set, gameOver is set to false
*
************************************************************************/
Minesweeper::Minesweeper(char d) : _difficulty(d), _gameOver(false)
{
	
}

/**********************************************************************
* Purpose: copy Constructor for Minesweeper class
*
* Precondition:
*     none
*
* Postcondition:
*      also none
*
************************************************************************/
Minesweeper::Minesweeper(const Minesweeper &)
{

}

/**********************************************************************
* Purpose: destructor for Minesweeper class
*
* Precondition:
*     none
*
* Postcondition:
*      object is deleted
*
************************************************************************/
Minesweeper::~Minesweeper()
{

}

/**********************************************************************
* Purpose: op =  for Minesweeper class
*
* Precondition:
*     both must be valid objects
*
* Postcondition:
*      I'm not sure why I wrote this, but everything on the lhs is set equal to the rhs
*
************************************************************************/
Minesweeper & Minesweeper::operator=(Minesweeper & rhs)
{
	if (this != &rhs)
	{
		_difficulty = rhs._difficulty;
		_UIBuffer = rhs._UIBuffer;
		_board = rhs._board;
	}
	return *this;
}

/**********************************************************************
* Purpose: Takes all user input and controls the program accordingly
*
* Precondition:
*     object must be instantiated
*
* Postcondition:
*      It only ever leaves this function if the game has been won or lost, so there
*
************************************************************************/
void Minesweeper::StartGameUI()
{
	_board.InitGame(_difficulty);
	string row, col, choice;
	int c = 0;
	int rownum = 5;
	int colnum = 5;
	_board.SelectRow(rownum);
	_board.SelectColumn(colnum);	//put cursor right around there
	while (!_gameOver)
	{
		_board.Display();
		cout <<"["<< _board.GetSelectedRow()<<"][" << _board.GetSelectedCol()<<"]" << endl;
		cout << "Use the arrow keys to move, [space] to unvover a tile, and [M] to mark a mine." << endl;
		c = 0;

		switch ((c = getch())) {		//get keryboard input one key at a time
		case KEY_UP:
			_board.Rowmm();
			break;
		case KEY_DOWN:
			_board.Rowpp();
			break;
		case KEY_LEFT:
			_board.Colmm();
			break;
		case KEY_RIGHT:
			_board.Colpp();
			break;
		case KEY_SPACE:
			if (_board.Uncover())
				_gameOver = true;
			break;
		case KEY_M:
			_board.Mark();
			break;
		default:
			break;
		}
		
	
	}
	_board.ClearSelect();		//remove cursor from screen
	_board.Display();
	if (_board.GetWinStatus())
	{
		cout << "Congratulations!  You defused all the mines!" << endl;
	}
	else
	{
		cout << "You hit a mine!" << endl;
	}
	system("pause");
	system("pause");
}

