#ifndef BOARD_H
#define BOARD_H
#include<string>
using namespace std;
class piece{};
class board {
private:
	//board class use composition it contains peice class
	piece* grid[8][8];
	char currentturn;   //'w' or 'b'
	bool gameover;
	string winner;
	void setuppieces();
	void clearboard();
	bool isinbound(int rows, int cols)const;
	//bool iskingalive(char color)const;
	//bool isincheck(char color)const;
		//bool ischeckmate(char color)const;
public:
	board();
	~board();
	void display()const;
	bool movepiece(int frorow, int frocols, int torow, int tocol);
	void switchturn();
	bool isgameover();
	string getwinner();
	piece* getpiece(int rows, int cols)const;
	//parse user inputs
	static bool parseposition(const string& pos, int& rows, int& cols);
	char getcurrentturn() const;
	
};
#endif

