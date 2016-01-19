/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be * started at any base.
*
* public:
	Minesweeper(char d);
		starts up a game with the given difficulty
	Minesweeper(const Minesweeper &);
		would copy the entire game if that made sense
	~Minesweeper();
		destructor
	Minesweeper & operator = (Minesweeper & rhs);
		kinda like a copy ctor only not

	void StartGameUI();
		all the UI interaction is handled here



*		...
*************************************************************************/

#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Gameboard.hpp"
#include <string>
using std::string;
using std::getline;

#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 0x020
#define KEY_M 109

class Minesweeper
{
public:
	Minesweeper(char d);
	Minesweeper(const Minesweeper &);
	~Minesweeper();
	Minesweeper & operator = (Minesweeper & rhs);

	void StartGameUI();

private:


	char _difficulty;
	Gameboard _board;
	std::string _UIBuffer;
	string _errorMsg;
	bool _gameOver;
	
};
#endif // !MINESWEEPER_H
