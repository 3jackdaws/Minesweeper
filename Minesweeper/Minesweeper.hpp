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
	void AppendToUIBuffer(string app);
	string GetUIBuffer();
	void ClearUIBuffer();
	void CreateErrorMsg(string msg);
	void ClearErrorMsg();
	string GetErrorMsg();
	bool SelectChoice(char choice);

	char _difficulty;
	Gameboard _board;
	std::string _UIBuffer;
	string _errorMsg;
	bool _gameOver;
	
};
#endif // !MINESWEEPER_H
