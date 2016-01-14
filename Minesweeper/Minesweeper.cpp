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
	while (!_gameOver)
	{
		ClearUIBuffer();
		ClearErrorMsg();
		AppendToUIBuffer("\n\nEnter the Row and Column of the tile. \nRow: ");
		do {
			_board.Display();
			
			cout << GetErrorMsg();
			
			cout << GetUIBuffer();
			getline(std::cin, row);
			CreateErrorMsg("Invalid Row");
		} while (!_board.SelectRow(atoi(row.c_str())));
		
		ClearErrorMsg();
		AppendToUIBuffer(row + "\nCol: ");
		do {
			_board.Display();
			
			cout << GetErrorMsg();
			
			cout << GetUIBuffer();
			getline(std::cin, col);
			CreateErrorMsg("Invalid Column");
		} while (!_board.SelectColumn(atoi(col.c_str())));

		ClearErrorMsg();
		AppendToUIBuffer(col + "\nUncover, mark, or cancel? (u/m/c): ");
		do {
			_board.Display();
			cout << GetErrorMsg();

			cout << GetUIBuffer();
			getline(std::cin, choice);
			CreateErrorMsg("Invalid Choice");
		} while (SelectChoice(atoi(col.c_str())));
		char c = tolower(choice.c_str()[0]);
		switch (c)
		{
		case 'u':
			if (_board.Uncover(atoi(row.c_str()), atoi(col.c_str())))
				_gameOver = true;
			
			break;

		case 'm':
			_board.Mark(atoi(row.c_str()), atoi(col.c_str()));
			break;

		case 'c':
			//Do nothing
			break;
		}
	}
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
}

void Minesweeper::AppendToUIBuffer(string app)
{
	_UIBuffer += app;
}

string Minesweeper::GetUIBuffer()
{
	return _UIBuffer;
}

void Minesweeper::ClearUIBuffer()
{
	_UIBuffer = "";
}

void Minesweeper::CreateErrorMsg(string msg)
{
	_errorMsg = msg;
}

void Minesweeper::ClearErrorMsg()
{
	_errorMsg = "";
}

string Minesweeper::GetErrorMsg()
{
	return _errorMsg;;
}

bool Minesweeper::SelectChoice(char choice)
{
	if (toupper(choice) == 'C' || toupper(choice) == 'U' || toupper(choice) == 'M')
		return true;
	return false;
}
