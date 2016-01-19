#include "Minesweeper.hpp"

Minesweeper::Minesweeper(char d) : _difficulty(d), _gameOver(false)
{
	
}

Minesweeper::Minesweeper(const Minesweeper &)
{

}

Minesweeper::~Minesweeper()
{

}

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

void Minesweeper::StartGameUI()
{
	_board.InitGame(_difficulty);
	string row, col, choice;
	int c = 0;
	int rownum = 5;
	int colnum = 5;
	_board.SelectRow(rownum);
	_board.SelectColumn(colnum);
	while (!_gameOver)
	{
		_board.Display();
		cout <<"["<< _board.GetSelectedRow()<<"][" << _board.GetSelectedCol()<<"]" << endl;
		cout << "Use the arrow keys to move, [space] to unvover a tile, and [M] to mark a mine." << endl;
		c = 0;

		switch ((c = getch())) {
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
	_board.ClearSelect();
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

