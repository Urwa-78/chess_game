#ifndef BOARD_H
#define BOARD_H
#include<string>
#include"piece.h"
using namespace std;
class board {
private:
	piece* grid[8][8];
	char currentturn;   //'w' or 'b'
	bool gameover;
	string winner;
	void setuppieces();
	void clearboard();
	bool isinbound(int rows, int cols)const;
public:
	board();
	~board();
	void display()const;
	bool movepiece(int frorow, int frocols, int torow, int tocol);
	void switchturn();
	bool isgameover()const;
	bool isKingCaptured(char color)const;
	bool isincheck(char color)const;
	bool ischeckmate(char color)const;
	string getwinner();
	piece* getpiece(int rows, int cols)const;
	static bool parseposition(const string& pos, int& rows, int& cols);
	char getcurrentturn() const;
};
#endif
