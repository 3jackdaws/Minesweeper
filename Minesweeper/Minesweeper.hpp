#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Gameboard.hpp"
#include <string>
using std::string;
using std::getline;

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
